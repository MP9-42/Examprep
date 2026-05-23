#include <unistd.h>

void solve(char *str, int pos, int len, int open_rem, int close_rem, int balance)
{
	if (pos == len)
	{
		if (balance == 0)
		{
			write(1, str, len);
			write(1, "\n", 1);
		}
		return ;
	}
	if (str[pos] == '(')
	{
		if (open_rem > 0)
		{
			str[pos] = ' ';
			solve(str, pos + 1, len, open_rem - 1, close_rem, balance);
			str[pos] = '(';
		}
		solve(str, pos + 1, len, open_rem, close_rem, balance + 1);
	}
	else if (str[pos] == ')')
	{
		if (close_rem > 0)
		{
			str[pos] = ' ';
			solve(str, pos + 1, len, open_rem, close_rem - 1, balance);
			str[pos] = ')';
		}
		solve(str, pos + 1, len, open_rem, close_rem, balance - 1);
	}
	else
		solve(str, pos + 1, len, open_rem, close_rem, balance);
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return(1);
	int len = 0;
	while (argv[1][len])
		len++;
	char str[len + 1];
	for (int i = 0; i <= len; i++)
		str[i] = argv[1][i];
	int open_rem = 0, close_rem = 0;
	for (int i = 0; i < len; i++)
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
	}
	solve(str, 0, len, open_rem, close_rem, 0);
	return(0);
}
