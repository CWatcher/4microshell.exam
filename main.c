#include <stdio.h>

#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

char**	cmd;
char**	ep;
char	delim = ';';
pid_t	pid;
int		pipe_fds[2];
int		fd0 = STDIN_FILENO;
int		fd1 = STDOUT_FILENO;

void	exec_cmd()
{
	if (!*cmd)
		exit(2);
	execve(*cmd, cmd, ep);
	exit_me2("error: cannot execute ", *cmd);
}
void	fork_cmd()
{
	pid = fork();
	if ( pid < 0 )
		exit_me(ERROR_FATAL);
	if (pid == 0) {
		if ( dup2(fd0, STDIN_FILENO) != STDIN_FILENO )
			exit_me(ERROR_FATAL);
		if ( dup2(fd1, STDOUT_FILENO) != STDOUT_FILENO )
			exit_me(ERROR_FATAL);
	}
	if ( fd0 != STDIN_FILENO && close(fd0) != 0 )
		exit_me(ERROR_FATAL);
	if ( fd1 != STDOUT_FILENO && close(fd1) != 0 )
		exit_me(ERROR_FATAL);
	if (pid == 0)
		exec_cmd();
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
void builtin_cd()
{
	if ( !cmd[1] || cmd[2] )
		put_err("error: cd: bad arguments");
	if ( chdir(cmd[1]) != 0 )
		put_err2("error: cd: cannot change directory to ", cmd[1]);
}
int	main(int argc, char* argv[], char* envp[])
{
	(void) argc;
	ep = envp;
	for (cmd = ++argv; *argv; cmd = argv) {
		argv = skip_cmd(argv);
		// put_err_multi(cmd);
		// fprintf(stderr, "delim = %c\n---\n", delim);
		if (delim == '|') {
			if ( pipe(pipe_fds) != 0 )
				exit_me(ERROR_FATAL);
			fd1 = pipe_fds[1];
		}
		else
			fd1 = STDOUT_FILENO;
		if ( *cmd && strcmp(*cmd, "cd") == 0 )
			builtin_cd();
		else
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
