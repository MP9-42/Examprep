#include <unistd.h>

void ft_putnum(int num)
{
	char c = '\0';
	int nbr;
	if (num < 0)
	{
		write(1, "-", 1);
		num *= -1;
	}
	if(num / 10 > 0)
		ft_putnum(num / 10);
	nbr = num % 10;
	c = '0' + nbr;
	write(1, &c, 1);
}

int main(int argc, char **argv)
{
	if (argc <= 1)
	{
		write(1, "0\n", 2);
		return(1);
	}
	int i = argc - 1;
	ft_putnum(i);
	write(1, "\n", 1);
	argv[1][i] = 'c';
	return(0);
}