/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 04:10:48 by sam               #+#    #+#             */
/*   Updated: 2022/07/27 04:13:59 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <unistd.h>

int	main(int ac, char **av)
{
	char	path[0x100];

	if (ac < 2)
		return (1);
	ft_chdir(av[1]);
	printf("%s\n", getcwd(path, sizeof(path)));
	return (0);
}
