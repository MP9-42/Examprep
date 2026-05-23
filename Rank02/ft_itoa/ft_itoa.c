#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

int nbnb(int num)
{
	int i = 0;
	if (num < 0)
	{
		num *= -1;
		i++;
	}
	while(num / 10 > 0)
	{
		num /= 10;
		i++;
	}
	i++;
	return(i);
}

char *ft_itoa(int num)
{
	if (num == 0)
		return("0");
	if (num == INT_MIN)
		return("-2147483648");
	int len = nbnb(num);
	char *str = malloc(sizeof(char) * len + 1);
	if (!str)
		return(NULL);
	str[len] = '\0';
	len--;
	int nb = num;
	if (num < 0)
	{
		str[0] = '-';
		nb *= -1;
		while(len > 0)
		{
			str[len] = nb % 10 + '0';
			len--;
			nb /= 10;
		}
	}
	else
	{
		while(len >= 0)
		{
			str[len] = nb % 10 + '0';
			len--;
			nb /= 10;
		}
	}
	return(str);
}

int main(void)
{
	int i = INT_MAX;
	char *str = ft_itoa(i);
	printf("%s\n", str);
	free(str);
	return(0);
}
