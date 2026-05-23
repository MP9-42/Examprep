#define _GNU_SOURCE
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

#define BUFFER_SIZE 420

int main(int argc, char **argv)
{
	if (argc != 2)
		return(1);
	char buffer[BUFFER_SIZE];
	char *tmp = NULL;
	char *result = NULL;
	char *position;
	char *find = argv[1];
	int result_len = 0;
	int find_len = strlen(find);
	int	bytes_read;

	while ((bytes_read = read(0, buffer, BUFFER_SIZE)) > 0)
	{
		tmp = realloc(result , result_len + bytes_read + 1);
		if (!tmp)
			return(free(result), perror("realloc"), 1);
		result = tmp;
		memmove(result + result_len, buffer, bytes_read);
		result_len += bytes_read;
		result[result_len] = '\0'; 
	}
	if (bytes_read < 0)
		return(free(result), perror("read"), 1);
	while ((position = memmem(result, result_len, find, find_len)))
		for (int i = 0; i < find_len; i++)
			position[i] = '*';
	printf("%s", result);
	free(result);
	return(0);
}
