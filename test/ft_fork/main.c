/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 04:22:09 by sam               #+#    #+#             */
/*   Updated: 2022/07/27 04:23:38 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	main(void)
{
	t_pid	pid;

	pid = ft_fork();
	if (pid == 0)
		printf("Hello world from child !\n");
	else
		printf("Hello world from Parent process !\n");
	return (0);
}
