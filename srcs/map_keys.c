#include "../includes/bito.h"

void	map_keys(void)
{
	unsigned char	ch;

	while (1)
	{
		ch = read_keys();
		if (ch == CTRL_KEY('q'))
			exit(0);
		write(1, &ch, 1);
	}
}
