#include "../includes/bito.h"

// To map each key to corispendent behavior
void	map_keys(unsigned char key)
{

	if (key == CTRL_KEY('q'))
	{
		write(1, "\x1b[2J", 4);
		write(1, "\x1b[H", 3);
		exit(0);
	}
	if (key == CTRL_KEY('\r'))
		write(1, "\r\n", 2);
	//	printf("%d", ch);
	//	fflush(stdout);
	else write(1, &key, 1);
}
