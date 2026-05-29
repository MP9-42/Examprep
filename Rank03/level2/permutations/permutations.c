#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void permute(char *sorted, char *current, int *used, int depth, int len)
{
	if (depth == len)
	{
		current[depth] = '\0';
		write(1, current, depth);
		write(1, "\n", 1);
		return;
	}
	for (int i = 0; i < len; i++)
	{
		if(!used[i])
		{
			used[i] = 1;
			current[depth] = sorted[i];
			permute(sorted, current, used, depth + 1, len);
			used[i] = 0;
		}
	}
}

void swap(char *a, char *b)
{
	char tmp = *a;
	*a = *b;
	*b = tmp;
}

void sort(char *str)
{
	int len = strlen(str);
	for (int i = 0; i < len - 1; i++)
		for (int j = i + 1; j < len; j++)
			if (str[j] < str[i])
				swap(&str[j], &str[i]);
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return(1);
	int len = strlen(argv[1]);
	char *str;
	if (!(str = malloc(sizeof(char) * len + 1)))
		return(1);
	for (int i = 0; i <= len; i++)
		str[i] = argv[1][i];
	char *sorted;
	if (!(sorted = malloc(sizeof(char) * len + 1)))
		return(1);
	strcpy(sorted, str);
	int *used;
	if (!(used = calloc(sizeof(int), len)))
		return(1);
	sort(sorted);
	permute(sorted, str, used, 0, len);
	free(used);
	free(sorted);
	free(str);
	return(0);	
}
