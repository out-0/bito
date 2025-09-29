#include "includes/bito.h"

int	main(void)
{

	enable_raw_mode();	// Disable echo and buffering
	init_editor();		// Editor setting
	while (1)
	{
		refresh_screen();
		unsigned char ch = read_keys();
		map_keys(ch);	// read and process keys-pressed
	}

	return (0);
}
