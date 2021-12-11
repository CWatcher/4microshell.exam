#include <unistd.h>
#include <stdlib.h>

#define ERROR_FATAL "error: fatal"

int	slen(const char* s)
{
	int	l = 0;
	while (*s++)
		l++;
	return l;
}

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
