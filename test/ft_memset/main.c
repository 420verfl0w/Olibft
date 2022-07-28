/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:30:29 by maldavid          #+#    #+#             */
/*   Updated: 2022/07/28 18:48:07 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern void *__memset_avx512_unaligned_erms(void *dst, int c, unsigned long size);

#include <stdio.h>

#include <string.h>

int	main(void)
{
	char	buf[33] = { 0 };
	__memset_avx512_unaligned_erms(buf, 'a', sizeof(buf));
	puts(buf);
	return (0);
}
