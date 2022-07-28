/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:55:29 by stales            #+#    #+#             */
/*   Updated: 2022/07/28 18:51:14 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "libft_net.h"

int	main(void)
{
	int	fd;

	fd = ft_socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (fd < 0)
		return (1);
	printf("[+] Socket created !\n");
	printf("%d\n", ft_htons(4444));
	ft_close(fd);
	return (0);
}
