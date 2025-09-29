#include "../includes/bito.h"

void	customize_rows_lines(t_screen_buffer *sb)
{
	for (int i = 0; i < editor.screen_rows; i++)
	{
		sbuffer_append(sb, "~", 1);
		if (i != editor.screen_rows - 1)
			sbuffer_append(sb, "\r\n", 2);
	}
}
