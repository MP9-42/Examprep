#include <unistd.h>
#include <string.h>
#include <stdio.h>

void solve(char *str, int position, int open_rem, int close_rem, int balance, int len)
{
	if (position == len)
	{
		if (balance == 0)
		{
			write(1, str, len);
			write(1, "\n", 1);
		}
		return ;
	}
	if (str[position] == '(')
	{
		if (open_rem > 0)
		{
			str[position] = ' ';
			solve(str, position + 1, open_rem - 1, close_rem, balance, len);
			str[position] = '(';
		}
		solve(str, position + 1, open_rem, close_rem, balance + 1, len);
	}
	else if (str[position] == ')')
	{
		if (close_rem > 0)
		{
			str[position] = ' ';
			solve(str, position + 1, open_rem, close_rem - 1, balance, len);
			str[position] = ')';
		}
		if (balance > 0)
			solve(str, position + 1, open_rem, close_rem, balance - 1, len);
	}
	else
		solve(str, position + 1, open_rem, close_rem, balance, len);
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	int len = 0;
	while (argv[1][len])
		len++;
	char str[len + 1];
	for (int i = 0; i <= len; i++)
		str[i] = argv[1][i];
	int open_rem = 0, close_rem = 0;
	int i = 0;
	while(str[i] == ')')
	{
		str[i] = ' ';
		i++;
	}
	while (str[len] == '(')
	{
		str[len] = ' ';
		len--;
	}
	while (i < len)
	{
		if (str[i] == '(')
				open_rem++;
		else if (str[i] == ')')
		{
			if (open_rem > 0)
				open_rem--;
			else
				close_rem++;
		}
		i++;
	}
	solve(str, 0, open_rem, close_rem, 0, len);
	return(0);
}
