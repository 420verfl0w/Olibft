/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 23:14:47 by maldavid          #+#    #+#             */
/*   Updated: 2022/07/27 18:49:01 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	main(int ac, char **av)
{
	if (ac < 2)
		return (1);
	printf("%d\n", ft_iscntrl(av[1][0]));
	return (0);
}
