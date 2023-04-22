/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 11:19:55 by gpimenta          #+#    #+#             */
/*   Updated: 2023/04/22 13:57:19 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_global	g_global;

void	nl_signal(int signal)
{
	if (g_global.in_heredoc)
	{
		g_global.stop_heredoc = 1;
		write (1, "\n", 1);
		exit (1);
	}
	if (g_global.in_cmd)
	{
		rl_replace_line("", 0);
		rl_redisplay();
		return ;
	}
	write (1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	(void)signal;
}

/*
Ctrl + C --SIGINT(ERRUPT) - new line
Ctrl + \ -- nothing - SIGQUIT
Ctrl + D -- EOF
*/

void	signals_handler(void)
{
	signal(SIGINT, nl_signal);
	signal(SIGQUIT, SIG_IGN);
}

void	parsing(char *line, t_shell *shell)
{
	char	**tab;

	tab = NULL;
	add_history(line);
	tab = split_outer_spaces(line);
	tab = split_redir(tab, 0);
	shell->line = parser(tab, shell->line, &shell->line, shell);
	if (shell->line && shell->line->token)
		create_pipe(shell);
	ft_free_line(shell->line, tab);
	return ;
}

void	set_prompt(t_shell *shell)
{
	char	*prompt;
	char	*line;

	shell->line = NULL;
	g_global.in_cmd = 0;
	prompt = get_prompt(shell);
	line = readline(prompt);
	free(prompt);
	if (!line)
	{
		printf("exit\n");
		free_minishell(shell->line, shell);
		return ;
	}
	if (!lexer(line))
	{
		free(line);
		set_prompt(shell);
		return ;
	}
	parsing(line, shell);
	set_prompt(shell);
}

int	main(int ac, char **av, char **envp)
{
	t_shell	shell;

	(void)av;
	(void)ac;
	if (ac != 1)
	{
		ft_putstr_fd("Invalid number of arguments!\n", 2);
		exit (1);
	}
	shell.envp = copy_env(envp);
	shell.export = get_sorted_env(&shell);
	signals_handler();
	set_prompt(&shell);
}
