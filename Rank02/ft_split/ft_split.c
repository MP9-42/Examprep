#include <stdlib.h>
#include <stdio.h>

int ft_strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return(i);
}

int ft_isspace(char c)
{
	if ((c >= 7 && c <= 13 )|| c == ' ')
		return(1);
	return(0);
}

int		word_count(char *str)
{
	int i = 0;
	int	words = 0;

	while(str[i] != '\0')
	{
		if (str[i] <= 32)
		{
			while (ft_isspace(str[i]) == 1)
				i++;
		}
		else
		{
			words++;
			while (ft_isspace(str[i]) == 0)
				i++;
		}
	}
	return(words);
}

char *ft_strdup(char *str, int len)
{
	int i = 0;
	char *word = malloc(sizeof(char) * len + 1);
	if (!word)
		return(NULL);
	while (i <= len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return(word);
}
char **do_words(char *str, char **words)
{
	int start = 0;
	int wordcount = word_count(str);
	int end = 0;
	int bi = 0;

	while (str[start] != '\0' && bi < wordcount)
	{
		while (ft_isspace(str[start]) == 1)
			start++;
		end = start;
		while (ft_isspace(str[end]) == 0)
			end++;
		words[bi] = ft_strdup(&str[start], end - start);
		if (!words[bi])
		{
			while (bi >= 0)
			{
				free(words[bi]);
				bi--;
			}
			free(words);
		}
		bi++;
		start = end;
	}
	return(words);
}

char **ft_split(char *str)
{
	char **words = NULL;
	int i = word_count(str);

	words = malloc(sizeof(char *) * i + 1);
	if(!words)
		return(NULL);
	words = do_words(str, words);
	return(words);
}

int main()
{
	char **words = NULL;
	char *str = "Wa lol 1 325345 ";
	int i = word_count(str);

	words = ft_split(str);
	int i2 = 0;
	while (words[i2])
	{
		printf("%s\n", words[i2]);
		i2++;
	}
	while (words[i] != NULL)
		i++;
	while (i >= 0)
	{
		free(words[i]);
		i--;
	}
	free(words);
	return (0);
}
