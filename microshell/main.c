#include <unistd.h>
#include <string.h>
#include "utils.c"

char**	cmd;
char**	ep;

void	run_cmd()
{
	execve(cmd[0], cmd, ep);
	exit_me2("error: cannot execute ", cmd[0]);
}
pid_t	fork_cmd()
{
	pid_t	pid = fork();
	if ( pid == 0 )
		run_cmd();
	else if ( pid > 0)
		return pid;
	else
		exit_me(ERROR_FATAL);
}
int	main(int argc, char* argv[], char* envp[])
{
	cmd = ++argv;
	waitpid(fork_cmd(), NULL, 0);
}
