#include <unistd.h>
#include <string.h>
#include "utils.c"

char**	cmd;
char**	ep;
char	delim = ';';

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
	if ( pid < 0 )
		exit_me(ERROR_FATAL);
	return pid;
}
char** skip_cmd(char* av[])
{
	while( *av && strcmp(*av, ";") != 0 && strcmp(*av, "|") )
		av++;
	delim = ';';
	if (*av) {
		delim = **av;
		*av = NULL;
		av++;
	}
	return av;
}
int	main(int argc, char* argv[], char* envp[])
{
	(void) argc;
	ep = envp;
	for (cmd = ++argv; *argv; cmd = argv ){
		argv = skip_cmd(argv);
		waitpid(fork_cmd(), NULL, 0);
	}
}
