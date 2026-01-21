#include <stdlib.h>
#include <stdio.h>

char makenum(int i)
{
	char c = '\0';
	if (i < 10)
		c = '0' + i;
	return(c);
}
char *ft_itoa(int num)
{
	int counter = 0;
	int nb = num;
	if (num < 0)
	{
		nb *= -1;
		counter++;
	}
	while (nb % 10 > 0)
	{
		nb /= 10;
		counter++;
	}
	printf("%d\n", counter);
	char *str = malloc(sizeof(char) * counter + 1);
	if (!str)
		return(NULL);
	if (num < 0)
	{
		str[0] = '-';
		num *= -1;
	}
	str[counter] = '\0';
	counter--;
	int num = 0;
	while(num != 0)
	{
		str[counter] = makenum(num / 10);
		num = num / 10;
		counter--;
	}
	return(str);
}

int main()
{
	int i = 25756;
	char *str = ft_itoa(i);

	printf("%s\n", str);
	return(0);
}