#include <unistd.h>

int ft_isspace(char c)
{
	if ((c >= 8 && c <= 13) || c == ' ')
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
	while (ft_isspace(argv[1][i]) == 1)
		i++;
	while (argv[1][i] != '\0')
	{
		if (ft_isspace(argv[1][i]) == 1)
		{
			while(ft_isspace(argv[1][i]) == 1)
				i++;
			if (argv[1][i] != '\0')
				write(1, "   ", 3);
		}
		else
		{
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return(0);
}