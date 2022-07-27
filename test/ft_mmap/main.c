/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 13:38:08 by stales            #+#    #+#             */
/*   Updated: 2022/07/27 20:32:23 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	void	*addr;

	addr = ft_mmap(NULL, 0x1000, PROT_NONE,
			MAP_PRIVATE | MAP_ANONYMOUS);
	ft_mprotect(addr, 0x1000, PROT_READ | PROT_WRITE);
	if (addr == (void *)-1)
		return (printf("mmap failed !\n"), 1);
	memcpy(addr, "hello world", 12);
	printf("%s\n", (char *)addr);
	ft_munmap(addr, 0x1000);
	return (0);
}
