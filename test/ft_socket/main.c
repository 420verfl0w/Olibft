/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:55:29 by stales            #+#    #+#             */
/*   Updated: 2022/07/28 17:14:31 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define FT_USE_NETWORK 1
#include <stdio.h>
#include "libft.h"

int	main(void)
{
	int	fd;

	fd = ft_socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (fd < 0)
		return (1);
	printf("[+] Socket created !\n");
	ft_close(fd);
	return (0);
}
