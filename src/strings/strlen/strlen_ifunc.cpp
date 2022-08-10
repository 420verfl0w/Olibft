/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen_ifunc.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 00:20:21 by maldavid          #+#    #+#             */
/*   Updated: 2022/08/11 00:27:13 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

extern "C"
{
	extern unsigned int __strlen_avx2(char* str);
	extern unsigned int __strlen_sse2(char* str);

	unsigned int ft_dumb_strlen(char* s);

	using func_ptr = unsigned int (*)(char*);

	static inline func_ptr __ft_strlen_ifunc(void)
	{
		if constexpr(has_avx2)
			return __strlen_avx2;
		if constexpr(has_sse2)
			return __strlen_sse2;
		return ft_dumb_strlen;
	}

	unsigned int ft_strlen(void* str) __attribute__((ifunc("__ft_strlen_ifunc")));
}
