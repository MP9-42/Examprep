#include <unistd.h>
#include <limits.h>

int ft_isvalid(char c, int base)
{
	char input1[17] = "0123456789abcdef";
	char input2[17] = "0123456789ABCDEF";
	int		i = 0;
	while(i <= base)
	{
		if(input1[i] == c || input2[i] == c)
			return(i);
		i++;
	}
	return(0);
}
int ft_atoi_base(char *num, int base)
{
	int nb = 0;
	int prepoc = 1;
	while(*num < 32)
		num++;
	if(*num == '-' || *num == '+')
	{
		if(*num == '-')
			prepoc = -1;
		num++;
	}
	while(*num && ft_isvalid(*num, base) != 0)
	{
		nb *= base;
		if(*num >= '0' && *num <= '9')
			nb += *num - '0';
		else if(*num >= 'a' && *num <= 'z')
			nb += *num - 'a' + 10;
		else if (*num >= 'A' && *num <= 'Z')
			nb += *num - 'A' + 10;
		num++;
	}
	return(nb * prepoc);
}


#include <stdio.h>
int	main(int ac, char **av)
{
	(void) ac;
	(void) av;
	if (ac == 3)
	{
		printf("%d\n", ft_atoi_base(av[1], 10));
		return (0);
	}
}
