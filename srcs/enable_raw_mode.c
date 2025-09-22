#include "../includes/bito.h"

struct termios original_mode;

// Entering the raw to disblay buffering input, and disabling echoing
void	enable_raw_mode(void)
{
	struct termios raw;
	// Get a copy of the actuall terminos flags settings
	tcgetattr(STDIN_FILENO, &original_mode);

	raw = original_mode; // Copy original settings so can modify
	// Register the reset function with the original mods
	atexit(disable_raw_mode);
	// Change the flag of echoing and disable it
	raw.c_lflag &= ~(ECHO);
	// write the new change of attr to the terminal
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}
