/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen_ifunc.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 00:20:21 by maldavid          #+#    #+#             */
/*   Updated: 2022/08/11 20:19:25 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// constexpr is a C++ feature that allows compiler to do condition
// or calculations at the compilation to save some runtime

#ifdef AVX2
	constexpr bool has_avx2 = true;
#else
	constexpr bool has_avx2 = false;
#endif

#ifdef SSE2
	constexpr bool has_sse2 = true;
#else
	constexpr bool has_sse2 = false;
#endif

extern "C" // export C++ code to interact with C code
{
	extern unsigned int __strlen_avx2(char* str);
	extern unsigned int __strlen_sse2(char* str);

	unsigned int ft_dumb_strlen(char* s);

	using func_ptr = unsigned int (*)(char*);

	static inline func_ptr __ft_strlen_ifunc(void)
	{
		if constexpr(has_avx2) // if cpu has avx2, use __strlen_avx2
			return __strlen_avx2;
		if constexpr(has_sse2) // else if cpu has sse2, use __strlen_sse2
			return __strlen_sse2;
		return ft_dumb_strlen; // else use the dumb strlen but this is garbage
	}

	unsigned int ft_strlen(void* str) __attribute__((ifunc("__ft_strlen_ifunc"))); // ft_strlen uses an indirect function to tell it what sub function to use
}
