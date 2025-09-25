#include "../includes/bito.h"

// Set those original setting back to the terminal
void	disable_raw_mode(void)
{
	if (tcsetattr(STDIN_FILENO, TCSANOW, &original_mode) == -1)
		error_exit("tcsetattr");
}
