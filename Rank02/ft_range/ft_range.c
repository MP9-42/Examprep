#include <stdlib.h>
#include <stdio.h>

int *ft_range(int start, int end)
{
	int counter = 0;
	int *array = NULL;
	int i = start;
	counter = 0;
	i = start;
	if (start < end)
	{
		while(i <= end)
		{
			counter++;
			i++;
		}
		i = start;
		array = (int *)malloc(sizeof(int) * counter);
		if (!array)
			return(NULL);
		counter = 0;
		while(i <= end)
		{
			array[counter] = i;
			i++;
			counter++;
		}
	}
	else if(start > end)
	{
		while(i >= end)
		{
			counter++;
			i--;
		}
		array = (int *)malloc(sizeof(int) * counter);
		if (!array)
			return(NULL);
		i = start;
		counter = 0;
		while (i >= end)
		{
			array[counter] = i;
			i--;
			counter++;
		}
	}
	else
		array[0] = i;
	return(array);
}

// int main()
// {
// 	int i = 0;
// 	int *numbers = ft_range(-3, 25);

// 	while (i <= 28)
// 	{
// 		printf("%d\n", numbers[i]);
// 		i++;
// 	}
// 	return(0);
// }