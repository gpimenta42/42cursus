/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_redir_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 14:05:38 by gpimenta          #+#    #+#             */
/*   Updated: 2023/04/22 14:05:47 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	get_index_j(char *str, int j, char c)
{
	while (str[j])
	{
		if (str[j] == c)
			break ;
		j++;
	}
	return (j);
}

int	count_redir(char **tab, int i, int j)
{
	int		count;
	int		each;
	char	c;

	count = 0;
	while (tab[++i])
	{
		each = 0;
		j = -1;
		while (tab[i][++j])
		{
			if (tab[i][j] == '\'' || tab[i][j] == '\"')
			{
				c = tab[i][j++];
				j = get_index_j(tab[i], j, c);
			}
			else if ((tab[i][j] == '>' || tab[i][j] == '<' || tab[i][j] == '|'))
				each++;
		}
		if (each)
			count += (each * 2) + 1;
	}
	return (count);
}

int	tab_len(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	ft_getsize(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			c = str[i++];
			while (str[i])
			{
				if (str[i] == c)
					break ;
				i++;
			}
		}
		else if (str[i] == '>' || str[i] == '<' || str[i] == '|')
			break ;
		i++;
	}
	return (i);
}
