/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 11:19:55 by gpimenta          #+#    #+#             */
/*   Updated: 2023/04/24 10:45:20 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_global	g_global;

void	nl_signal(int signal)
{
	if (g_global.in_heredoc)
	{
		g_global.stop_heredoc = 1;
		g_global.exit_code = 130;
		write (1, "\n", 1);
		exit (1);
	}
	if (g_global.in_cmd)
	{
		write (1, "\n", 1);
		rl_replace_line("", 0);
		rl_redisplay();
		g_global.exit_code = 130;
		return ;
	}
	g_global.exit_code = 130;
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

void	handle_line(char *line, t_shell *shell)
{
	shell->tab = NULL;
	shell->tab = split_outer_spaces(line);
	shell->tab = split_redir(shell->tab, 0);
	shell->line = parser(shell->tab, shell->line, &shell->line, shell);
	if (!lexer_token(shell->line))
	{
		ft_free_line(shell->line, shell->tab);
		set_prompt(shell);
		return ;
	}
	if (shell->line && shell->line->token)
		execution(shell);
	ft_free_line(shell->line, shell->tab);
	set_prompt(shell);
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
	add_history(line);
	if (!lexer(line))
	{
		free(line);
		set_prompt(shell);
		return ;
	}
	handle_line(line, shell);
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
	get_shlvl(&shell);
	set_shlvl(shell.shlvl + 1, &shell);
	signals_handler();
	set_prompt(&shell);
}
