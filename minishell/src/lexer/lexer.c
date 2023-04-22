/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 13:55:27 by gpimenta          #+#    #+#             */
/*   Updated: 2023/04/22 15:28:28 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	skip_quotes(char *line, int i)
{
	int	j;

	j = ft_strlen(line) - 1;
	while (j >= 0)
	{
		if (i != j && line[i] == line[j])
			return (j);
		j--;
	}
	return (0);
}
/*
there has to be even number of the first quote found.
*/

int	closed_quotes(char *line, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == c)
			count++;
		i++;
	}
	if (count % 2 == 0)
		return (1);
	return (0);
}

int	print_error(int n)
{
	if (n == 1)
		ft_putstr_fd("syntax error, input not closed\n", 2);
	else if (n == 2)
		ft_putstr_fd("syntax error near unexpected token '|\n", 2);
	else if (n == 3)
		ft_putstr_fd("syntax error near unexpected token '< or '>\n", 2);
	else if (n == 4)
		ft_putstr_fd("syntax error near unexpected token `&\n", 2);
	else if (n == 5)
		ft_putstr_fd("syntax error, prohibited character\n", 2);
	g_global.exit_code = 2;
	return (0);
}

int	redirections_errors(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '<' && line[i + 1] == '|')
			return (1);
		else if (line[i] == '>' && (line[i + 1] == '<' || line[i + 1] == '|'))
			return (1);
		if (line[i] == '<' && (line[i + 1] == 32 || line[i + 1] == 9
				|| line[i + 1] == '<') && (line[i + 2] == '<'
				|| line[i + 2] == '>'))
			return (1);
		else if (line[i] == '>' && (line[i + 1] == 32 || line[i + 1] == 9
				|| line[i + 1] == '>')
			&& (line[i + 2] == '>' || line[i + 2] == '<'))
			return (1);
		i++;
	}
	return (0);
}

int	lexer(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] == '\"' || line[i] == '\'')
		{
			if (!closed_quotes(line, line[i]))
				return (print_error(1));
			i = skip_quotes(line, i);
		}
		else if (line[0] == '|' || line[ft_strlen(line) - 1] == '|'
			|| (line[i] == '|' && line[i + 1] == '|'))
			return (print_error(2));
		else if ((line[i] == '<' || line[i] == '>')
			&& redirections_errors(line))
			return (print_error(3));
		else if (line[i] == '&')
			return (print_error(4));
		else if (line[i] == '\\' || line[i] == ';' || line[i] == '('
			|| line[i] == ')')
			return (print_error(5));
	}
	return (1);
}
