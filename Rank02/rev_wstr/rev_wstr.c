#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char *ft_strdup(char *str)
{
	int i = 0;
	while(str[i] != '\0')
		i++;
	char *new = malloc(sizeof(char) * i + 1);
	if (!str)
		return(NULL);
	int i2 = 0;
	while(i2 <= i)
	{
		new[i2] = str[i2];
		i2++;
	}
	return(new);
}

int main(int argc, char **argv)
{
	if (!argv[1] || argc != 2)
	{
		write(1, "\n", 1);
		return(1);
	}
	int i = 0;
	while (argv[1][i] != '\0')
		i++;
	int i2 = i;
	char *str = ft_strdup(argv[1]);
	while(i > 0)
	{
		while(str[i] > ' ')
			i--;
		i2 = i;
		i++;
		while(str[i] > ' ' && str[i] != '\0')
		{
			write(1, &str[i], 1);
			i++;
		}
		i = i2;
		write(1, &str[i], 1);
		i--;
	}
	// write(1, "\n", 1);
	free(str);
	return(0);
}

// hallo was geht?