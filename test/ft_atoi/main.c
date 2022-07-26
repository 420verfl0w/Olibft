#include <stdio.h>
#include "libft.h"

int main(int ac, char **av)
{
	if (ac < 2)
		return (1);
	printf("%d\n", ft_atoi(av[1]));
	return (0);
}

