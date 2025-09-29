#include "../includes/bito.h"

// Read input from stdin
unsigned char	read_keys(void)
{
	unsigned char	key;
	ssize_t		status;

	status = read(STDIN_FILENO, &key, 1);
	if (status == -1)
		error_exit("read");
	return (key);
}
