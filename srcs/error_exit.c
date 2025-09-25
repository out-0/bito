#include "../includes/bito.h"

// Print the message followed by the error from 'errno' global
void	error_exit(char *message)
{
	perror(message);
	exit (1);
}
