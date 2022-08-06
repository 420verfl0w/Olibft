/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:30:29 by maldavid          #+#    #+#             */
/*   Updated: 2022/07/28 20:09:38 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void __memset_sse2_unaligned(void* buf, char c, unsigned int size);

int	main(void)
{
	char	buf[33] = { 0 };
	__memset_sse2_unaligned(buf, 'a', sizeof(buf));
	puts(buf);
	return (0);
}
