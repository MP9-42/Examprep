#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int bit = 7;
	char 	c = '\0';
	while(bit >= 0)
	{
		c = (octet >> bit & 1) + '0';
		bit--;
		write(1, &c, 1);
	}
}

int main()
{
	print_bits(2);
	return(0);
}