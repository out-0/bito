#include "../includes/bito.h"

// To match the buffer text in memory with text layer of data user see, so screen is refreshed each key and draw the correct text.
void    refresh_screen()
{
	t_screen_buffer sb;

	init_buffer(&sb);

	sbuffer_append(&sb, "\x1b[2J", 4);	// For clear Screen
	sbuffer_append(&sb, "\x1b[H", 3);	// Move cursor

	customize_rows_lines(&sb);	// Draw tildes
	sbuffer_append(&sb, "\x1b[H", 3);
	
	write(STDOUT_FILENO, sb.data, sb.len);
	free_buffer(&sb);
}
