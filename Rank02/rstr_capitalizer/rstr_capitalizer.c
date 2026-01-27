#include <unistd.h>


int ft_isalpha(char c);
int ft_isspace(char c);

int ft_isalpha(char c)
{
	if (c >= 'a' && c <= 'z')
		return(1);
	else if (c >= 'A' && c <= 'Z')
		return(2);
	else
		return (0);
}

int ft_isspace(char c)
{
	if ((c >= 8 && c <= 13) || c == ' ')
		return(1);
	return(0);
}

int ft_strlen(char *str)
{
	int i = 0;
	while (str[i] != '\0')
		i++;
	return(i);
}

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		write(1, "\n", 1);
		return(1);
	}
	int bi = 1;
	int si = 0;
	int last = 0;
	while(argv[bi])
	{
		si = 0;
		while (argv[bi][si + 1] != '\0')
		{
			if(ft_isspace(argv[bi][si + 1]) == 1 && ft_isalpha(argv[bi][si]) == 2)
			{
				write(1, &argv[bi][si], 1);
				si++;
			}
			else if(ft_isspace(argv[bi][si + 1]) == 1 && ft_isalpha(argv[bi][si]) == 1)
			{
				argv[bi][si] -= 32;
				write(1, &argv[bi][si], 1);
				si++;
			}
			else if (ft_isalpha(argv[bi][si]) == 2 && ft_isspace(argv[bi][si + 1]) == 0)
			{
				argv[bi][si] += 32;
				write(1, &argv[bi][si], 1);
				si++;
			}
			else
			{
				write(1, &argv[bi][si], 1);
				si++;
			}
		}
		last = ft_strlen(argv[bi]) - 1;
		if (ft_isalpha(argv[bi][last]) == 1)
		{
			argv[bi][last] -= 32;
			write(1, &argv[bi][si], 1);
			si++;
		}
		else
		{
			write(1, &argv[bi][last], 1);
			si++;
		}
		write(1, "\n", 1);
		bi++;
	}
	return(0);
}
