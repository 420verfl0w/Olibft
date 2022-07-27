/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strerrno.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 16:58:39 by maldavid          #+#    #+#             */
/*   Updated: 2022/07/27 21:18:00 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const char	*ft_strerrno(int e)
{
	if (~ -e > (int)(sizeof(g_errno_tab) / sizeof(char *)))
		return ("ft_error : Unknown error code");
	return (g_errno_tab[~ -e]);
}
