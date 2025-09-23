#include "../includes/bito.h"

struct termios original_mode;

// Entering the raw to disblay buffering input, and disabling echoing
void	enable_raw_mode(void)
{
	struct termios raw;
	// Get a copy of the actuall terminos flags settings
	tcgetattr(STDIN_FILENO, &original_mode);

	raw = original_mode;

	// Register the reset function with the original mods
	atexit(disable_raw_mode);

	raw.c_iflag = raw.c_iflag & ~(IXON | ICRNL);	// Turn off input flags
	raw.c_lflag = raw.c_lflag & ~(ECHO | ICANON | IEXTEN | ISIG);	//Turn off some local flags
	raw.c_cc[VMIN] = 1;	// Return each byte as available
	raw.c_cc[VTIME] = 0;	// no timeout

	// write the new change of attr to the terminal
	tcsetattr(STDIN_FILENO, TCSANOW, &raw);
}
