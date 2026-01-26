#include <unistd.h>

int ft_strlen(char *str)
{
	int i = 0;
	while (str[i] != '\0')
		i++;
	return(i);
}

int main(int argc, char **argv)
{
	if(argc != 2 || !argv[1])
	{
		write(1, "\n", 1);
		return(1);
	}
	int len = ft_strlen(argv[1]) - 1;
	while (argv[1][len] <= ' ')
		len--;
	while (argv[1][len] > ' ')
		len--;
	len++;
	while (argv[1][len] != '\0' && argv[1][len] > ' ')
	{
		write(1, &argv[1][len], 1);
		len++;
	}
	write(1, "\n", 1);
	return(0);
}