/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 13:56:28 by gpimenta          #+#    #+#             */
/*   Updated: 2023/04/22 15:28:19 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	redirections_classifier(t_token **lst_token)
{
	t_token	*current;

	current = *lst_token;
	while (current)
	{
		if (current->type == 4 && !ft_strcmp(current->name, "<")
			&& current->next != NULL && ft_strcmp(current->next->name, ">"))
			current->next->type = 4;
		else if (current->type == 5 && (!ft_strcmp(current->name, ">")
				|| !ft_strcmp(current->name, ">>")) && current->next != NULL)
			current->next->type = 5;
		else if (current->type == 6 && (!ft_strcmp(current->name, "<<"))
			&& current->next != NULL)
			current->next->type = 6;
		current = current->next;
	}
}

/*
types
	int 1 word
	int 2 builtin
	int 3 expand
	int 4 infile
	int	5 outfile
	int	6 heredoc
*/

int	token_type(char *str)
{
	int	type;

	if (!ft_strcmp(str, "echo") || !ft_strcmp(str, "exit")
		|| !ft_strcmp(str, "cd") || !ft_strcmp(str, "pwd")
		|| !ft_strcmp(str, "env") || !ft_strcmp(str, "export")
		|| !ft_strcmp(str, "unset"))
		type = 2;
	else if (ft_strrchr(str, '$') || !ft_strcmp(str, "~"))
		type = 3;
	else if (!ft_strcmp(str, "<"))
		type = 4;
	else if (!ft_strcmp(str, ">") || !ft_strcmp(str, ">>"))
		type = 5;
	else if (!ft_strcmp(str, "<<"))
		type = 6;
	else
		type = 1;
	return (type);
}

t_token	*token_creator(t_token **lst_token, char *str,
						t_line *line, t_shell *shell)
{
	line->token = malloc(sizeof(t_token));
	if (!line->token)
		return (NULL);
	line->token->name = ft_strdup(str);
	line->token->type = token_type(str);
	expander(line->token, shell);
	line->token->next = NULL;
	if (line->token->name)
		ft_tokenlst_add_back(lst_token, line->token);
	else
	{
		free(line->token->name);
		free(line->token);
		line->token = NULL;
	}
	return (line->token);
}

t_line	*create_line(char **tab, t_line *line, int i, t_shell *shell)
{
	t_token		*lst_token;
	t_token		*first_token;
	static int	j;

	lst_token = NULL;
	line = malloc(sizeof(t_line));
	if (!line)
		return (NULL);
	while (tab[++i] && ft_strcmp(tab[i], "|"))
	{
		if (!lst_token)
		{
			line->token = token_creator(&lst_token, tab[i], line, shell);
			first_token = line->token;
		}
		else
			line->token = token_creator(&lst_token, tab[i], line, shell);
	}
	redirections_classifier(&lst_token);
	line->i = j;
	j++;
	line->next = NULL;
	line->token = first_token;
	return (line);
}

t_line	*parser(char **tab, t_line *line, t_line **lst_line, t_shell *shell)
{
	t_line	*first_line;
	int		flag;

	flag = 0;
	first_line = NULL;
	while (*tab)
	{
		if (flag == 0)
		{
			if (!line)
			{
				line = create_line(tab, line, -1, shell);
				first_line = line;
			}
			else
				line = create_line(tab, line, -1, shell);
			ft_line_add_back(lst_line, line);
			flag = 1;
		}
		else if (!ft_strcmp(*tab, "|"))
			flag = 0;
		tab++;
	}
	return (first_line);
}
