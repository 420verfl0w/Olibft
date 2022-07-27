/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errno.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 14:51:48 by maldavid          #+#    #+#             */
/*   Updated: 2022/07/27 16:14:35 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef __STDC_NO_ATOMICS__

static int			g_errno = 0;

int	*__ft_bits_get_errno_location(void)
{
	return (&g_errno);
}
#else

static _Atomic int	g_errno = 0;

_Atomic int	*__ft_bits_get_errno_location(void)
{
	return (&g_errno);
}
#endif
