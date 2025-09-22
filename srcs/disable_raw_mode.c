#include "../includes/bito.h"

void	disable_raw_mode(void)
{
	tcsetattr(STDIN_FILENO, TCSANOW, &original_mode);
}
