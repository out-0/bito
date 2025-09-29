#ifndef BITO_H
# define BITO_H

#include <unistd.h>	// For read systemcall
#include <stdio.h>	// For printf
#include <termios.h>	// For tools and struct to handle terminal
#include <stdlib.h>	// For atexit register function
#include <ctype.h>	// For control characters
#include <sys/ioctl.h>	// For get window size

# define CTRL_KEY(k) ((k) & 31)	// Map letter to its CTRL-key ASCII code (usally 0-26)

// The struct of terminal config and settings
typedef struct s_my_config
{
	int	screen_rows;
	int	screen_cols;
	struct termios	original_termios;
}	t_my_config;

extern	t_my_config	editor;

void		enable_raw_mode(void);
void		disable_raw_mode(void);
void		error_exit(char *message);

unsigned char	read_keys(void);
void		map_keys(unsigned char);

// Escape secence for terminal task actions
void		refresh_screen(void);

void		customize_rows_lines(void);
int		get_window_size(int *row, int *cols);

void		set_init_editor(void);

#endif
