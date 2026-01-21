#include <unistd.h>

int ft_isspace(char c)
{
	if ((c >= 8 && c <= 13) || c == ' ')
		return(1);
	return(0);
}

int ft_isalphabig(char c)
{
	if ((c >= 'A' && c <= 'Z'))
		return(1);
	return(0);
}

int ft_isalphasmall(char c)
{
	if (c >= 'a' && c <= 'z')
		return(1);
	return(0);
}

int main(int argc, char **argv)
{
	if (argc <= 1)
	{
		write(1, "\n", 1);
		return(1);
	}
	int bi = 1;
	int si = 1;
	while(argv[bi])
	{
		while(argv[bi][si] != '\0')
		{
			if (ft_isalphasmall(argv[bi][0]) == 1)
			{
				argv[bi][0] -= 32;
				write(1, &argv[bi][0], 1);
			}
			if (ft_isspace(argv[bi][si]) == 1)
			{
				while(ft_isspace(argv[bi][si]) == 1)
				{
					write(1, &argv[bi][si], 1);
					si++;
				}
				if (ft_isalphasmall(argv[bi][si]) == 1)
					argv[bi][si] -= 32;
				write(1, &argv[bi][si], 1);
				si++;
			}
			else
			{
				if (ft_isalphabig(argv[bi][si]) == 1)
					argv[bi][si] += 32;
				write(1, &argv[bi][si], 1);
				si++;
			}
		}
		write(1, "\n", 1);
		si = 1;
		bi++;
	}
	return(0);
}