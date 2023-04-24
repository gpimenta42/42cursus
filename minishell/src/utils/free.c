/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 12:20:56 by gpimenta          #+#    #+#             */
/*   Updated: 2023/04/24 12:59:36 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_all_close(t_shell *shell, char **arr, int flag)
{
	free(shell->pid);
	free_minishell(shell->line, shell);
	ft_free_tab(shell->tab);
	ft_free_tab(arr);
	if (flag == 1)
	{
		close(STDIN_FILENO);
		close(STDOUT_FILENO);
	}
}

void	ft_free_tab(char **arr)
{
	int	i;

	i = -1;
	if (!arr)
		return ;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

void	ft_free_line(t_line	*line, char **tab)
{
	t_token	*token_tmp;
	t_line	*line_tmp;
	int		i;

	while (line)
	{
		while (line->token)
		{
			token_tmp = line->token->next;
			free(line->token->name);
			free(line->token);
			line->token = token_tmp;
		}
		line_tmp = line->next;
		free(line);
		line = line_tmp;
	}
	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

void	free_arrays(t_shell *shell)
{
	int	i;

	i = -1;
	while (shell->envp[++i])
		free(shell->envp[i]);
	free(shell->envp);
	i = -1;
	while (shell->export[++i])
		free(shell->export[i]);
	free(shell->export);
}

void	free_minishell(t_line *line, t_shell *shell)
{
	t_token	*token_tmp;
	t_line	*line_tmp;

	if (line)
	{
		while (line)
		{
			while (line->token)
			{
				token_tmp = line->token->next;
				free(line->token->name);
				free(line->token);
				line->token = token_tmp;
			}
			line_tmp = line->next;
			free(line);
			line = line_tmp;
		}
	}
	free_arrays(shell);
}
