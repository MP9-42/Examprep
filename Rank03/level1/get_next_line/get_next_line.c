#define _GNU_SOURCE

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFER_SIZE 420

char *get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE];
	static int pos, len;
	int i = 0;
	char *tmp, *str = NULL;

	while (1)
	{
		if (pos >= len && (len = read(fd, buffer, BUFFER_SIZE)) <= 0)
		{
			if (len < 0 || !str)
				return(NULL);
			return(str[i] = 0, str);
		}
		if (pos >= len)
			pos = 0;
		if (!(tmp = malloc(i + 2)))
			return(free(str), NULL);
		for (int j = 0; j < i; j++)
			tmp[j] = str[j];
		if (str)
			free(str);
		str = tmp;
		if ((str[i++] = buffer[pos++]) == '\n')
			return(str[i] = 0, str);
	}
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return(1);
	int fd = open(argv[1], O_RDONLY);
	char *line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		printf("%s", line);
	}
	if (line)
		free(line);
	close(fd);
	return(0);
}