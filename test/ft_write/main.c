#include <stdio.h>
#include "libft.h"
#include <string.h>

int main(int ac, char **av)
{
	if (ac < 2)
		return (1);
	ft_write(1, av[1], strlen(av[1]));
	return (0);
}
