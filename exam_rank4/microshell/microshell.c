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
