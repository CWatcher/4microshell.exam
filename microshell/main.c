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
	if (pid == 0) {
		if ( dup2(fd0, STDIN_FILENO) != STDIN_FILENO )
			exit_me(ERROR_FATAL);
		if ( dup2(fd0, STDIN_FILENO) != STDIN_FILENO )
			exit_me(ERROR_FATAL);
	}
	if ( fd0 != STDIN_FILENO && close(fd0) != 0 )
		exit_me(ERROR_FATAL);
	if ( fd1 != STDOUT_FILENO && close(fd1) != 0 )
		exit_me(ERROR_FATAL);
	if (pid == 0)
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
		if (delim == '|') {
			if ( pipe(pipe_fds) != 0 )
				exit_me(ERROR_FATAL);
			fd1 = pipe_fds[1];
		}
		else
			fd1 = STDOUT_FILENO;
		fork_cmd();
		if (delim == '|')
			fd0 = pipe_fds[0];
		else
		{
			fd0 = STDIN_FILENO;
			waitpid(pid, NULL, 0);
		}
	}
}
