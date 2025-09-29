#include "../includes/bito.h"

t_my_config	editor;

// Entering the raw to disblay buffering input,
// and disabling echoing
void	enable_raw_mode(void)
{
	struct termios raw;
	// Get a copy of the actuall terminos flags settings
	if (tcgetattr(STDIN_FILENO, &editor.original_termios) == -1)
		error_exit("tcgetattr");

	raw = editor.original_termios;

	// Register the reset function with the original mods
	atexit(disable_raw_mode);
	// Turn off and switch some input/output/local/control_chars  flags
	raw.c_iflag &= ~(IXON | ICRNL | INLCR | BRKINT | INPCK | ISTRIP);
	raw.c_oflag &= ~(OPOST);
	raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
	raw.c_cflag &= ~(CSIZE);
	raw.c_cflag |= (CS8);

	raw.c_cc[VMIN] = 1;	// Return each byte as available
	raw.c_cc[VTIME] = 0;	// no timeout

	// write the new change of attr to the terminal
	if (tcsetattr(STDIN_FILENO, TCSANOW, &raw) == -1)
		error_exit("tcsetattr");
}
