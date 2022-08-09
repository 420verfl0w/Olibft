/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset_ifunc.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 12:14:00 by maldavid          #+#    #+#             */
/*   Updated: 2022/08/09 23:39:16 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef ERMS
	constexpr bool has_erms = true;
#else
	constexpr bool has_erms = false;
#endif

#ifdef AVX512
	constexpr bool has_avx512 = true;
#else
	constexpr bool has_avx512 = false;
#endif

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
	extern void	*__memset_erms(void *str, int c, unsigned int n);
	extern void	*__memset_avx512_unaligned(void *str, int c, unsigned int n);
	extern void	*__memset_avx2_unaligned(void *str, int c, unsigned int n);
	extern void	*__memset_sse2_unaligned(void *str, int c, unsigned int n);
	extern void	*__memset_sse2_unaligned_erms(void *str, int c, unsigned int n);

	void* ft_dumb_memset(void* s, int c, unsigned int n);

	static void (*__ft_memset_ifunc(void)) (void)
	{
		register unsigned int edx asm("%edx");
		//void* res = nullptr;
		if constexpr(has_erms) // don't do the two tests in a single if because of the constexpr that is tested at compile time
			if((edx & 0x1000) != 0)
				return __memset_erms;

		return ft_dumb_memset;
	}

	void* ft_memset(void* str, int c, unsigned int n) __attribute__((ifunc("__ft_memset_ifunc")));
}
