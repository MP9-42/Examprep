#include <stdio.h>
#include <stdlib.h>

void	sort_int_tab(int *tab, unsigned int size)
{
	int tmp;
	unsigned int i;
	unsigned int j;

	i = 0;
	while (i < size - 1)
	{
		j = i;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int main(void)
{
	int tab[] = {122, 53453, 42342, 53455, 3, 53453, 34534523, 0};
	int size = 7;
	sort_int_tab(tab, size);
	while(size - 1 >= 0)
	{
		printf("%d\n", tab[size - 1]);
		size--;
	}
	return(0);
}