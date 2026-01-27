#include <unistd.h>
#include <stdio.h>
#include <limits.h>

// printf("%d\n", i);


void ft_putnum(int num)
{
	if (num < 0)
	{
		write(1, "-", 1);
		num *= -1;
	}
	if(num / 10 != 0)
		ft_putnum(num / 10);
	char c = num % 10 + '0';
	write(1, &c, 1);
}

int ft_atoi(char *str)
{
	int num = 0;
	int prepoc = 1;
	int i = 0;
	while (str[i] <= 32)
		i++;
	if(str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			prepoc *= -1;
		i++;
	}
	while(str[i] != '\0')
	{
		num = (num * 10) + str[i] - '0';
		i++;
	}
	if (num * prepoc > INT_MAX || num * prepoc < INT_MIN)
		return(0);
	return(num * prepoc);
}

void tab_mult(int num)
{
	int i = 1;

	while (i <= 9)
	{
		ft_putnum(i);
		write(1, " x ", 3);
		ft_putnum(num);
		write(1, " = ", 3);
		ft_putnum(i * num);
		write(1, "\n", 1);
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc != 2 || !argv[1])
	{
		write(1, "\n", 1);
		return(1);
	}
	int i = ft_atoi(argv[1]);
	tab_mult(i);
	return(0);
}