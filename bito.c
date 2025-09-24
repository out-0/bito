#include "includes/bito.h"

int	main(void)
{
	unsigned char	ch;

	enable_raw_mode();	// Disable echo and buffering
	while (read(STDIN_FILENO, &ch, 1) && ch != 'q')
	{
		//write(1, &ch, 1);
		if (iscntrl(ch))
			printf("%d (CTRL) = 0x%X", ch, ch);
		else
			printf("%d -> %c", ch, ch);
		fflush(stdout); // Flush the printf buffer to print immediatly
	}
	return (0);
}
