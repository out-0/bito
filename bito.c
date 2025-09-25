#include "includes/bito.h"

int	main(void)
{
	unsigned char	ch;
	int		status;

	enable_raw_mode();	// Disable echo and buffering
	while (1)
	{
		status = read(STDIN_FILENO, &ch, 1);
		if (status < 0)
			break;
		if (ch == 'q')
			break;
		//write(1, &ch, 1);
		if (iscntrl(ch))
			printf("%d (CTRL) = 0x%X ", ch, ch);
		else
			printf("%d -> %c ", ch, ch);
		fflush(stdout); // Flush the printf buffer to print immediatly
	}
	return (0);
}
