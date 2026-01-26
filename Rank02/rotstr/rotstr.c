#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int ft_isspace(char c)
{
	if ((c >= 8 && c <= 13) || c == ' ')
		return(1);
	return(0);
}

int ft_strlen(char *str)
{
	int i = 0;
	while(str[i] != '\0')
		i++;
	return(i);
}

char	*rotstr(char *str)
{
	int begin = 0;
	int end = ft_strlen(str) - 1;
	int i = 0;
	while(end >= 0 && ft_isspace(str[end]) == 1)
		end--;
	while(str[begin] != '\0' && ft_isspace(str[begin]) == 1)
		begin++;
	char *torot = malloc(sizeof(char) * end - begin + 1);
	if (!torot)
		return(NULL);
	torot[end - begin] = '\0';
	end = begin;
	while (ft_isspace(str[begin]) == 0 && str[begin] != '\0')
		begin++;
	while (ft_isspace(str[begin]) == 1 && str[begin] != '\0')
		begin++;
	while(str[begin] != '\0')
	{
		end = begin;
		while (ft_isspace(str[end]) == 0 && str[end] != '\0')
			end++;
		while(begin != end)
		{
			torot[i] = str[begin];
			i++;
			begin++;
		}
		if (ft_isspace(str[begin]) == 1)
		{
			torot[i] = ' ';
			i++;
		}
		while (ft_isspace(str[begin]))
			begin++;
	}
	if (torot[i - 1] != ' ')
	{
		torot[i] = ' ';
		i++;
	}
	begin = 0;
	end = 0;
	while (ft_isspace(str[begin]) == 1 && str[begin] != '\0')
		begin++;
	end = begin;
	while (ft_isspace(str[end]) == 0 && str[end] != '\0')
		end++;
	while(begin != end)
	{
		torot[i] = str[begin];
		i++;
		begin++;
	}
	return(torot);
}

int main(int argc, char **argv)
{
	if (argc != 2 || !argv[1])
	{
		write(1, "\n", 1);
		return(-1);
	}
	char *torot	= rotstr(argv[1]);
	write(1, torot, ft_strlen(torot));
	free(torot);
	// write(1, "\n", 1);
	return(0);
}