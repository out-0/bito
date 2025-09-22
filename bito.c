#include "includes/bito.h"

int	main(void)
{
	int	ch;

	enable_raw_mode();	// Disable echo and buffering
	while (read(STDIN_FILENO, &ch, 1))
	{
		if ((char)ch == 'q')
			break;
		printf("%c", ch);
	}
	return (0);
}
