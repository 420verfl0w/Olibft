/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 15:18:20 by stales            #+#    #+#             */
/*   Updated: 2022/07/27 19:01:14 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int	main(int ac, char **av)
{
	int	dfd;

	if (ac < 2)
		return (1);
	dfd = ft_dup(1);
	ft_write(dfd, av[1], strlen(av[1]));
	ft_close(dfd);
	return (0);
}
