/* 
Assignment name  : microshell
Expected files   : microshell.c
Allowed functions: malloc, free, write, close, fork, waitpid, signal, kill, exit, chdir, execve, dup, dup2, pipe, strcmp, strncmp
--------------------------------------------------------------------------------------

Write a program that will behave like executing a shell command
- The command line to execute will be the arguments of this program
- Executable's path will be absolute or relative but your program must not build a path (from the PATH variable for example)
- You must implement "|" and ";" like in bash
	- we will never try a "|" immediately followed or preceded by nothing or "|" or ";"
- Your program must implement the built-in command cd only with a path as argument (no '-' or without parameters)
	- if cd has the wrong number of argument your program should print in STDERR "error: cd: bad arguments" followed by a '\n'
	- if cd failed your program should print in STDERR "error: cd: cannot change directory to path_to_change" followed by a '\n' with path_to_change replaced by the argument to cd
	- a cd command will never be immediately followed or preceded by a "|"
- You don't need to manage any type of wildcards (*, ~ etc...)
- You don't need to manage environment variables ($BLA ...)
- If a system call, except execve and chdir, returns an error your program should immediatly print "error: fatal" in STDERR followed by a '\n' and the program should exit
- If execve failed you should print "error: cannot execute executable_that_failed" in STDERR followed by a '\n' with executable_that_failed replaced with the path of the failed executable (It should be the first argument of execve)
- Your program should be able to manage more than hundreds of "|" even if we limit the number of "open files" to less than 30.

for example this should work:
$>./microshell /bin/ls "|" /usr/bin/grep microshell ";" /bin/echo i love my microshell
microshell
i love my microshell
$>

Hints:
Don't forget to pass the environment variable to execve

Hints:
Do not leak file descriptors!
*/


#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void	message_error(char *s1, char *s2)
{
	while (s1 && *s1)
		write (2, s1++, 1);
	if (s2)
	{
		while (*s2)
			write (2, s2++, 1);
	}
	write (2, "\n", 1);
}

int	exec(char **av, int i, int fd, char **envp)
{
	dup2(fd, STDIN_FILENO);
	close(fd);
	av[i] = NULL;
	execve(av[0], av, envp);
	message_error("error: cannot execute ", av[0]);
	return (1);
}

int main(int ac, char **av, char **envp)
{
	int	i;
	int	fd;
	int	pipe_fd[2];

	(void)ac;
	fd = dup(STDIN_FILENO);
	i = 0;
	while (av[i] && av[i + 1])
	{
		av = &av[i + 1];
		i = 0;
		while (av[i] && strcmp(av[i], ";") && strcmp(av[i], "|"))
			i++;
		if (!strcmp(av[0], "cd"))
		{
			if (i != 2)
				message_error("error: cd: bad arguments", 0);
			else if (chdir(av[i]) == -1)
				message_error("error: cd: cannot change directory to ", av[i]);
		}
		else if (i != 0 && (av[i] == NULL || !strcmp(av[i], ";")))
		{
			if (fork() == 0)
			{
				exec(av, i, fd, envp);
				return (1);
			}
			close (fd);
			waitpid(-1, NULL, WUNTRACED);
			fd = dup(STDIN_FILENO);
		}
		else if (i != 0 && !strcmp(av[i], "|"))
		{
			pipe(pipe_fd);
			if (fork() == 0)
			{
				dup2(pipe_fd[1], STDOUT_FILENO);
				close (pipe_fd[0]);
				close (pipe_fd[1]);
				exec(av, i, fd, envp);
				return (1);
			}
			waitpid(-1, NULL, WUNTRACED);
			close (pipe_fd[1]);
			close (fd);
			fd = pipe_fd[0];
		}
	}
	close (fd);
}
