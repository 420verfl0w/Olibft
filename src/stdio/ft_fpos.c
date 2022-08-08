/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fpos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 17:45:20 by maldavid          #+#    #+#             */
/*   Updated: 2022/08/08 13:35:34 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

t_size	ft_fgetpos(t_file *file)
{
	if (file == FT_NULL)
		return (0);
	return (file->pos);
}

t_bool	ft_fsetpos(t_file *file, t_size pos)
{
	if (file == FT_NULL)
		return (FALSE);
	file->pos = pos;
	return (TRUE);
}
