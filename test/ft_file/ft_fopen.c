/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fopen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 18:15:21 by maldavid          #+#    #+#             */
/*   Updated: 2022/08/08 15:02:27 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	main(void)
{
	t_file	*file;
	char	buf[255];

	ft_fopen("test.txt", F_WR | F_RD);
	ft_fread(file, buf, 255);
	puts(buf);
	ft_fclose(file);
	return (0);
}
