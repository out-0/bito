#include "../includes/bito.h"

// Fetch the current terminal size
int	get_window_size(int *rows, int *cols)
{
	struct winsize	ws;
	
	if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == -1 || ws.ws_row == 0)
		return (-1);
	else
	{
		*rows = ws.ws_row;
		*cols = ws.ws_col;
	}
	return (0);
}
