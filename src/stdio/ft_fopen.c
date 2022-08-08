/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fopen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 22:20:13 by maldavid          #+#    #+#             */
/*   Updated: 2022/08/08 16:48:48 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>

int	ft_get_system_flags(t_fflags flags)
{
	int	res;

	res = 0;
	if (flags & F_AP)
		res |= FT_OPEN_APPEND;
	if (flags & F_RD && flags & F_WR)
		res |= FT_OPEN_RW;
	else if (flags & F_RD)
		res |= FT_OPEN_RO;
	else if (flags & F_WR)
		res |= FT_OPEN_WO;
	return (res);
}

t_file	*ft_fopen(const char *path, t_fflags flag)
{
	t_file	*f;

	f = (t_file *)malloc(sizeof(t_file));
	if (f == NULL)
	{
		g_ft_errno = FT_ENOMEM;
		return (FT_NULL);
	}
	int res = ft_get_system_flags(flag);
	printf("%d\n", res);
	f->fd = ft_open(path, res, 0);
	if (f->fd == -1)
	{
		g_ft_errno = errno;
		return (FT_NULL);
	}
	f->flags = flag;
	f->pos = 0;
	return (f);
}
