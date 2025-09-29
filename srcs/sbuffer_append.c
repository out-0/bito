#include "../includes/bito.h"

void	sbuffer_append(t_screen_buffer *sb, const char *data, size_t len)
{
	char	*new_data;

	new_data = realloc(sb->data, sb->len + len);
	if (!new_data)
		return;
	memcpy(&new_data[sb->len], data, len);
	sb->data = new_data;
	sb->len += len;
}

void	init_buffer(t_screen_buffer *sb)
{
	sb->data = NULL;
	sb->len = 0;
}

void	free_buffer(t_screen_buffer *sb)
{
	free(sb->data);
	sb->data = NULL;
	sb->len = 0;
}
