#include "../includes/bito.h"

// Set those original setting back to the terminal
void	disable_raw_mode(void)
{
	if (tcsetattr(STDIN_FILENO, TCSANOW, &editor.original_termios) == -1)
		error_exit("tcsetattr");
}
