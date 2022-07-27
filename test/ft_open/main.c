/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 03:27:32 by sam               #+#    #+#             */
/*   Updated: 2022/07/27 03:59:07 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <fcntl.h>
#include <unistd.h>

int	main(void)
{
	char	buf[0x100];
	int		fd;
	size_t	size;

	fd = ft_open("test.txt", OPEN_RO, 0);
	size = ft_lseek(fd, 0, SEEK_END);
	ft_lseek(fd, 0, SEEK_SET);
	ft_read(fd, buf, sizeof(buf));
	printf("Size : %zd\nData : %s", size, buf);
	ft_close(fd);
	return (0);
}
