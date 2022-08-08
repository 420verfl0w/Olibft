/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fputc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 17:55:34 by maldavid          #+#    #+#             */
/*   Updated: 2022/08/08 13:35:28 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

int	ft_fputc(int c, t_file *file)
{
	if (file == FT_NULL)
		return (-1);
	if (ft_fwrite(file, (char *)&c, 1))
		return (c);
	return (-1);
}
