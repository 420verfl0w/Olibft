/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 23:32:10 by stales            #+#    #+#             */
/*   Updated: 2022/07/26 23:34:45 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	main(int ac, char **av)
{
	int	a;
	int	b;

	if (ac < 3)
		return (1);
	a = ft_atoi(av[1]);
	b = ft_atoi(av[2]);
	printf("A : %d | B : %d\n", a, b);
	ft_swap(&a, &b);
	printf("A : %d | B : %d\n", a, b);
	return (0);
}
