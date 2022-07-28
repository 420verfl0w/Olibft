/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 19:50:04 by stales            #+#    #+#             */
/*   Updated: 2022/07/28 20:01:00 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "libft_net.h"

int	main(void)
{
	t_port	p;
	t_u16	n;
	t_u32	a;
	t_u32	b;

	p = htons(4568);
	n = ntohs(p);
	printf("To network byte order : %d | To big endian : %d\n", p, n);
	a = htonl(45687);
	b = ntohl(a);
	printf("To network byte order : %d | To big endian : %d\n", a, b);
	return (0);
}
