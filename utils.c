#include <unistd.h>
#include <stdlib.h>

void put_err(char* s)
{
	while (*s)
		write(STDERR_FILENO, s++, 1);
	write(STDERR_FILENO, "\n", 1);
}

void put_err2(char* s, char* arg)
{
	while (*s)
		write(STDERR_FILENO, s++, 1);
	while (*arg)
		write(STDERR_FILENO, arg++, 1);
	write(STDERR_FILENO, "\n", 1);
}

void exit_me(char *s)
{
	put_err(s);
	exit(1);
}

void exit_me2(char* s, char* arg)
{
	put_err2(s, arg);
	exit(EXIT_FAILURE);
}
