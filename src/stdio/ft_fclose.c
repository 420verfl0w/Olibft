/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fclose.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 22:45:41 by maldavid          #+#    #+#             */
/*   Updated: 2022/08/06 22:51:33 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>
#include "libft.h"

int	ft_fclose(t_file *file)
{
	if (file == FT_NULL)
		return (0);
	if (ft_close(file->fd) == -1)
	{
		g_ft_errno = errno;
		return (-1);
	}
	free(file);
	file = FT_NULL;
	return (0);
}
