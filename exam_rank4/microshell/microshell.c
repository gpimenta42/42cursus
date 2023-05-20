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
	/*s1 not *s1*/
	if (s2)
	{
		while (*s2)
			write(2, s2++, 1);
	}
	write (2, "\n", 1);
}

void	ft_exec(char **av, int i, int tmp_fd, char **envp)
{
	av[i] = NULL;
	dup2(tmp_fd, STDIN_FILENO);
	/*its a dup2*/
	close(tmp_fd);
	/*dont forget to close*/
	execve(av[0], av, envp);
	message_error("error: cannot execute ", av[0]);
}

int	main(int ac, char **av, char **envp)
{
	int		i;
	int		fd[2];
	int		tmp_fd;

	tmp_fd = dup(STDIN_FILENO);
	i = 0;
	(void)ac;
	while (av[i] && av[i + 1])
	{
		av = &av[i + 1];
		i = 0;
		while (av[i] && strcmp(av[i], ";") && strcmp(av[i], "|"))
			i++;
		if (!strcmp(av[0], "cd"))
		{
			if (i != 2)
				message_error("error: cd: bad arguments", NULL);
			else if (chdir(av[1]) == -1)
				message_error("error: cd: cannot change directory to ", av[1]);
		}
		else if (i != 0 && (av[i] == NULL || !strcmp(av[i], ";")))
		/* put av[i] == NULL first otherwise it will be segfault*/
		/*this has to be the 2nd condition --> because av[i] == NULL
		for the case ./minishel /bin/ls*/
		{
			if (fork() == 0)
			{
				ft_exec(av, i, tmp_fd, envp);
				return (1);
			}
			else
			{
				/*this has to be in an else*/
				close (tmp_fd);
				/*renovate tmp_fd*/
				while (waitpid(-1, NULL, WUNTRACED) != -1)
					;
				tmp_fd = dup(STDIN_FILENO);
			}
		}
		else if (i != 0 && !strcmp(av[i], "|"))
		{
			pipe(fd);
			if (fork() == 0)
			{
				dup2(fd[1], STDOUT_FILENO);
				close(fd[0]);
				close (fd[1]);
				ft_exec(av, i, tmp_fd, envp);
				return (1);
			}
			else
			{
				close(fd[1]);
				close (tmp_fd);
				tmp_fd = fd[0];
				/* its tmp_fd which will be fd[0]*/
				// fd[0] = STDIN_FILENO;
				// while (waitpid(-1, NULL, WUNTRACED) != -1)
				// 	;
			}
		}
	}
	close(tmp_fd);
}
