/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fread.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 17:27:32 by maldavid          #+#    #+#             */
/*   Updated: 2022/08/08 13:35:23 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"
#include <errno.h>

t_size	ft_fread(t_file *file, char *dest, t_size len)
{
	t_size	size;

	if (file == FT_NULL || !(file->flags & F_RD))
	{
		g_ft_errno = FT_EBADF;
		return (0);
	}
	size = ft_read(file->fd, dest, len);
	if (size == (t_size)-1)
	{
		g_ft_errno = errno;
		return (0);
	}
	file->pos += size;
	return (size);
}
