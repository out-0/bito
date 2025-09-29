#ifndef BITO_H
# define BITO_H

#include <unistd.h>	// For read systemcall
#include <stdio.h>	// For printf
#include <termios.h>	// For tools and struct to handle terminal
#include <stdlib.h>	// For atexit register function
#include <ctype.h>	// For control characters
#include <sys/ioctl.h>	// For get window size

#include <string.h>	// For memcpy()

# define CTRL_KEY(k) ((k) & 31)	// Map letter to its CTRL-key ASCII code (usally 0-26)

// The struct of terminal config and settings
typedef struct s_my_config
{
	int	screen_rows;
	int	screen_cols;
	struct termios	original_termios;
}	t_my_config;

// Screen buffer hold the data will be displayed
typedef struct s_screen_buffer
{
	char	*data;
	size_t	len;
}	t_screen_buffer;

extern	t_my_config	editor;

// Handle raw mode setting
void		enable_raw_mode(void);
void		disable_raw_mode(void);
void		error_exit(char *message);

// Handle read()
unsigned char	read_keys(void);
void		map_keys(unsigned char);

// Escape secence for terminal task actions
void		refresh_screen(void);

// Handle window of the screen
void		customize_rows_lines(t_screen_buffer *sb);
int		get_window_size(int *row, int *cols);
void		init_editor(void);

// Handle data content with buffer
void		sbuffer_append(t_screen_buffer *sb, const char *data, size_t len);
void		init_buffer(t_screen_buffer *sb);
void		free_buffer(t_screen_buffer *sb);

#endif
