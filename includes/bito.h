#ifndef BITO_H
# define BITO_H

#include <unistd.h>	// For read systemcall
#include <stdio.h>	// For printf
#include <termios.h>	// For tools and struct to handle terminal
#include <stdlib.h>	// For atexit register function

// The struct to change the terminal behavior
extern struct termios	original_mode;

void	enable_raw_mode(void);
void	disable_raw_mode(void);

#endif
