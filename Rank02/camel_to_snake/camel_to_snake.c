#include <stdio.h>
#include <unistd.h>

int ft_isupper(char c)
{
	if (c >= 'A' && c <= 'Z')
		return(1);
	return(0);
}

int main(int argc, char **argv)
{
	if (argc != 2 || !argv[1])
	{
		write(1, "\n", 1);
		return(1);
	}
	int i = 0;
	while(argv[1][i] != '\0')
	{
		if (ft_isupper(argv[1][i]) == 1)
		{
			write(1, "_", 1);
			argv[1][i] += 32;
			write(1, &argv[1][i], 1);
		}
		else
			write(1, &argv[1][i], 1);
		i++;
	}
	write(1, "\n", 1);
	return(0);
}