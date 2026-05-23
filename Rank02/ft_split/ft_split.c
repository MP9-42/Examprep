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
char *ft_strdup(char *str, int len)
{
	int i = 0;
	char *dup = malloc(sizeof(char) * len + 1);
	if (!dup)
		return(NULL);
	dup[len] = '\0';
	len--;
	while (i <= len)
	{
		dup[i] = str[i];
		i++;
	}
	return(dup);
}

int word_count(char *str)
{
	int i = 0;
	int count = 0;
	while (str[i] != '\0')
	{
		while(ft_isspace(str[i]) == 1 && str[i] != '\0')
			i++;
		count++;
		while (ft_isspace(str[i]) == 0 && str[i] != '\0')
			i++;
	}
	i--;
	if (ft_isspace(str[i]) == 1)
		count--;
	return(count);
}

void get_words(char *str, char **words)
{
	int begin = 0;
	int end = 0;
	int bi = 0;
	while (str[end] != '\0')
	{
		while(ft_isspace(str[begin]) == 1 && str[begin] != '\0')
			begin++;
		end = begin;
		while (ft_isspace(str[end]) == 0 && str[end] != '\0')
			end++;
		words[bi] = ft_strdup(&str[begin], end - begin);
		if (!words[bi])
		{
			while (bi >= 0)
			{
				free(words[bi]);
				bi--;
				return ;
			}
		}
		bi++;
		begin = end;
	}
	words[bi] = NULL;
}

char **ft_split(char *str)
{
	int wordcount = word_count(str);
	char **words = malloc(sizeof(char *) * wordcount + 1);
	if (!words)
		return(NULL);
	get_words(str, words);
	return(words);
}

int main(int argc, char **argv)
{
	if (argc < 1)
		return(1);
	int bi = 0;
	char **words = ft_split(argv[1]);
	while(words[bi] != NULL)
	{
		printf("%s\n", words[bi]);
		bi++;
	}
	printf("%d\n", ft_strlen(words[bi]));
	return(0);
}
