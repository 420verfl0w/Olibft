/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_internal.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 11:34:29 by maldavid          #+#    #+#             */
/*   Updated: 2022/08/08 13:44:14 by maldavid         ###   ########.fr       */
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

#endif
