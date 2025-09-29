#include "../includes/bito.h"

void	customize_rows_lines(void)
{
	for (int i = 0; i < editor.screen_rows; i++)
		write(1, "~\r\n", 3);
}
