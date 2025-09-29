#include "../includes/bito.h"

void	init_editor(void)
{
	if (get_window_size(&editor.screen_rows, &editor.screen_cols) == -1)
		error_exit("get-window-size");
}
