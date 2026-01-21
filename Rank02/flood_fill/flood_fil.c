#include "flood_fill.h"

int matrixlen(char **matrix)
{
	int i = 0;
	while(matrix[i] != NULL)
		i++;
	return(i);
}

void holycross(char **tab, t_point standpoint, t_point size, char fill)
{
	int px = standpoint.x + 1;
	int mx = standpoint.x - 1;
	int py = standpoint.y + 1;
	int my = standpoint.y - 1;
	if(tab[py][(standpoint.x)] == 'F'
		|| tab[py][(standpoint.x)] == fill && py <= size.y)
		tab[standpoint.y + 1][standpoint.x] = 'F';
	if((tab[(standpoint.y)][(standpoint.x) + 1] == 'F'
		|| tab[(standpoint.y)][(standpoint.x) + 1] == fill) && )

}
void  flood_fill(char **tab, t_point size, t_point begin)
{
	char start;
	int x = begin.x;
	int y = begin.y;

	t_point	truth = begin;
	start = tab[y][x];
	while(x >= 0)
	{
		while (y >= 0)
		{
			while(y <= size.y)
			{
				while(x <= size.x)
				{
					if(tab[y][x] == start || tab[y][x] == 'F')
					{
						tab[y][x] = 'F';
						x++;
					}
					else
						y++;
				}
				if(tab[y][x] == '\0')
					x--;
				
			}
		}
	}
}

int main(void)
{
	// char **area;
	// t_point size = {8, 5};
	// t_point begin = {2, 2};
	char *zone[] = {
		"11111111",
		"10001001",
		"10010001",
		"10110001",
		"11100001",
		NULL
	};
	printf("%d\n", matrixlen(zone));
	// area = make_area(zone);

	// flood_fill(area, size, begin);
	// putc('\n');
	// print_tab(area);
	return (0);
}
