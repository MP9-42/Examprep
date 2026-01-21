#include <unistd.h>

int ft_strlen(char *str)
{
	int i = 0;

	while(str[i] != '\0')
		i++;
	return(i);
}
int main(int argc, char **argv)
{
	if (argc != 3)
	{
		write(1, "\n", 1);
		return(1);
	}
	int i2 = 0;
	int i = 0;
	while (argv[1][i2])
	{
		if (argv[2][i] == '\0' && argv[1][i2] != '\0')
		{
			write(1, "\n", 1);
			return(1);
		}
		else if(argv[2][i] == argv[1][i2])
			i2++;
		i++;
	}
	write(1, argv[1], ft_strlen(argv[1]));
	write(1, "\n", 1);
	return(0);
}