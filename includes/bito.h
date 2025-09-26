#ifndef BITO_H
# define BITO_H

#include <unistd.h>	// For read systemcall
#include <stdio.h>	// For printf
#include <termios.h>	// For tools and struct to handle terminal
#include <stdlib.h>	// For atexit register function
#include <ctype.h>	// For control characters

# define CTRL_KEY(k) ((k) & 31)	// Map letter to its CTRL-key ASCII code (usally 0-26)

// The struct to change the terminal behavior
extern struct termios	original_mode;

void	enable_raw_mode(void);
void	disable_raw_mode(void);
void	error_exit(char *message);

unsigned char	read_keys(void);
void	map_keys(void);

#endif
