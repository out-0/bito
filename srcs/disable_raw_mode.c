#include "../includes/bito.h"

void	disable_raw_mode(void)
{
	// Set those original setting back to the terminal
	tcsetattr(STDIN_FILENO, TCSANOW, &original_mode);
}
