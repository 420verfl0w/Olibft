/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 03:27:32 by sam               #+#    #+#             */
/*   Updated: 2022/07/27 03:29:33 by sam              ###   ########.fr       */
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

	fd = ft_open("test.txt", OPEN_RO, 0);
	ft_read(fd, buf, sizeof(buf));
	printf("%s", buf);
	close(fd);
	return (0);
}
