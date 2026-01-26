#include <stdio.h>

unsigned int lcm(unsigned int a, unsigned int b)
{
	int i = 1;

	if (a == 0 || b == 0)
		return(0);
	while(i % a > 0 || i % b > 0)
		i++;
	return(i);
}

int main()
{
	printf("%d\n", lcm(12, 6));
	return(0);
}