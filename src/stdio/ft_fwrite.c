/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fwrite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 15:04:49 by maldavid          #+#    #+#             */
/*   Updated: 2022/08/08 13:34:43 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"
#include <errno.h>

t_size	ft_fwrite(t_file *file, char *msg, t_size len)
{
	t_size	size;

	if (file == FT_NULL || !(file->flags & F_WR))
	{
		g_ft_errno = FT_EBADF;
		return (0);
	}
	size = ft_write(file->fd, msg, (unsigned int)len);
	if (size == (t_size)-1)
	{
		g_ft_errno = errno;
		return (0);
	}
	return (size);
}
