/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errno.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 14:51:48 by maldavid          #+#    #+#             */
/*   Updated: 2022/07/27 15:49:09 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef __STDC_NO_ATOMICS__

static int			g_errno = 0;
#else

_Atomic static int	g_errno = 0;
#endif

int	*__ft_bits_get_errno_location(void)
{
	return (&g_errno);
}
