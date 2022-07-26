/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dumb_strlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 23:40:02 by maldavid          #+#    #+#             */
/*   Updated: 2022/08/11 20:18:34 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_size	ft_dumb_strlen(char *str)
{
	t_size	size;

	size = 0;
	while (*(str + size))
		size++;
	return (size);
}
