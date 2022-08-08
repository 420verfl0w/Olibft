/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_internal.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 11:34:29 by maldavid          #+#    #+#             */
/*   Updated: 2022/08/09 00:29:53 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_INTERNAL_H
# define LIBFT_INTERNAL_H

# include "libft.h"

/////////////////////////////////
//
//			ENUM
//
/////////////////////////////////

enum __attribute__((__packed__)) e_bool
{
	FALSE	= 0,
	TRUE	= 1
};

/////////////////////////////////
//
//			STRUCT
//
/////////////////////////////////

struct	s_file
{
	int			fd;
	t_fflags	flags;
	t_size		pos;
};

/////////////////////////////////
//
//			ERRORS
//
/////////////////////////////////

// src/sys/ft_errnotab.c
extern const char	*g_errno_tab[FT_ERRNO];

//////////////////////////////////
//
//			STRINGS
//
//////////////////////////////////

# ifdef ERMS
extern void	__memset_erms(void *str, int c, t_size n);
extern inline void	ft_memset(void *str, int c, t_size n)
{
	__memset_erms(str, c, n);
}
# elif defined AVX512
extern void	__memset_avx512_unaligned(void *str, int c, t_size n);
extern inline void	ft_memset(void *str, int c, t_size n)
{
	return (__memset_avx512_unaligned(str, c, n));
}
# elif defined AVX2
extern void	__memset_avx2_unaligned(void *str, int c, t_size n);
extern inline void	ft_memset(void *str, int c, t_size n)
{
	return (__memset_avx2_unaligned(str, c, n));
}
# elif defined SSE2
#  ifdef ERMS
extern void	__memset_sse2_unaligned_erms(void *str, int c, t_size n);
extern inline void	ft_memset(void *str, int c, t_size n)
{
	return (__memset_sse2_unaligned_erms(str, c, n));
}
#  else
extern void	__memset_sse2_unaligned(void *str, int c, t_size n);
extern inline void	ft_memset(void *str, int c, t_size n)
{
	return (__memset_sse2_unaligned(str, c, n));
}
#  endif
# endif

#endif
