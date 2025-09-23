#include "includes/bito.h"

int	main(void)
{
	unsigned char	ch;

	enable_raw_mode();	// Disable echo and buffering
	while (read(STDIN_FILENO, &ch, 1) && ch != 'q')
	{
		if (iscntrl(ch))
			printf("%d cntrl =%c\n", ch, ch);
		else
			printf("%d -> %c\n", ch, ch);
	}
	return (0);
}
