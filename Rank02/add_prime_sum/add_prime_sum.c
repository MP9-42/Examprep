#include <unistd.h>
#include <stdio.h>
#include <limits.h>

int isprime(int num)
{
	int i = 2;
	while(i <= num / 2)
	{
		if(num % i == 0 && (i != num || i != 1))
			return(0);
		i++;
	}
	return(num);
}

void ft_putnum(int num)
{
	if (num < 0)
	{
		write(1, "-", 1);
		num *= -1;
	}
	char c = '\0';
	if (num / 10 != 0)
		ft_putnum(num / 10);
	c = num % 10 + '0';
	write(1, &c, 1);
}

int ft_atoi(char *num)
{
	int nb = 0;
	int prepoc = 1;
	int i = 0;
	while (num[i] <= 32)
		i++;
	if (num[i] == '-' || num[i] == '+')
	{
		if (num[i] == '-')
			prepoc *= -1;
		i++;
	}
	while(num[i] != '\0')
	{
		nb = nb * 10 + num[i] - '0';
		i++;
	}
	if (nb * prepoc > INT_MAX || nb * prepoc < INT_MIN)
		return(0);
	return(nb * prepoc);
}

int main(int argc, char **argv)
{
	if (argc != 2 || !argv[1] || argv[1][0] == '-')
	{
		write(1, "0\n", 2);
		return(1);
	}
	int num = ft_atoi(argv[1]);
	int result = 0;
	while(num >= 2)
	{
		result += isprime(num);
		num--;
	}
	ft_putnum(result);
	write(1, "\n", 1);
	return(0);
}

// gfAdfgasdgdasggbsRES Etya
 
// Abcdjw4eatuw893y46t08w36y0873yq0tryb 6q3yaty9 q3976rb5t93qt4AV9T Fsde#123