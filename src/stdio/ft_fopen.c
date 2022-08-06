/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fopen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 22:20:13 by maldavid          #+#    #+#             */
/*   Updated: 2022/08/06 22:51:40 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <errno.h>

t_file	*ft_fopen(const char *path, t_fflags flag)
{
	t_file	*f;

	f = (t_file *)malloc(sizeof(t_file));
	if (f == NULL)
	{
		g_ft_errno = FT_ENOMEM;
		return (FT_NULL);
	}
	f->fd = ft_open(path, 0, 0);
	if (f->fd == -1)
	{
		g_ft_errno = errno;
		return (FT_NULL);
	}
	f->flags = flag;
	f->pos = 0;
	return (f);
}
