#include <unistd.h>
#include <string.h>
#include "utils.c"

char**	cmd;
char**	ep;
char	delim = ';';
pid_t	pid;
int		pipe_fds[2];
int		fd0 = STDIN_FILENO;
int		fd1 = STDOUT_FILENO;

void	run_cmd()
{
	execve(cmd[0], cmd, ep);
	exit_me2("error: cannot execute ", cmd[0]);
}
void	fork_cmd()
{
	pid = fork();
	if ( pid < 0 )
		exit_me(ERROR_FATAL);
	if ( pid == 0 )
		run_cmd();
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
		fork_cmd();
		if (delim == ';')
			waitpid(pid, NULL, 0);
	}
}
