#include <unistd.h>

int main(int argc, char **argv)
{
	if(argc != 3 || !argv[1] || !argv[2])
	{
		write(1, "\n", 1);
		return(1);
	}
	int lookup[256] = {};
	int i = 0;
	while(argv[1][i] != '\0')
	{
		lookup[(int)argv[1][i]] = 1;
		i++;
	}
	i = 0;
	while (argv[1][i] != '\0')
	{
		if (lookup[(int)argv[1][i]] == 1)
		{
			write(1, &argv[1][i], 1);
			lookup[(int)argv[1][i]] = 0;
		}
		i++;
	}
	i = 0;
	while(argv[2][i] != '\0')
	{
		if (lookup[(int)argv[2][i]] == 1)
		{
			write(1, &argv[2][i], 1);
			lookup[(int)argv[2][i]] = 0;
		}
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
