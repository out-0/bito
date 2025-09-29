#include "../includes/bito.h"

// Clear screen & Print the message followed by the error from 'errno' global
void	error_exit(char *message)
{
	write(1, "\x1b[2J", 4);
	write(1, "\x1b[H", 3);

	perror(message);
	exit (1);
}
