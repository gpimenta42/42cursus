/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_outer_spaces.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 14:42:41 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/04/22 15:18:15 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_substrlen(char *str, int i, char c)
{
	int	quoted;

	quoted = 0;
	while (str[i])
	{
		if (ft_isquote(str[i]) && quoted == 0)
		{
			c = str[i];
			quoted = 1;
		}
		else if (str[i] == c && quoted == 1)
			quoted = 0;
		else if (!ft_isquote(str[i]) && !ft_isspace(str[i]))
			;
		else if (ft_isspace(str[i]) && quoted == 0)
			break ;
		i++;
	}
	return (i);
}

int	strcount(char *str, int i, int count)
{
	char	c;

	while (str[++i])
	{
		if (ft_isquote(str[i]))
		{
			if (i == 0 || ft_isspace(str[i - 1]))
				count++;
			c = str[i++];
			while (str[i] && str[i] != c)
				i++;
		}
		else if (!ft_isquote(str[i]) && !ft_isspace(str[i])
			&& (i == 0 || ft_isspace(str[i - 1])))
			count++;
		if ((size_t)i == ft_strlen(str))
			break ;
	}
	return (count);
}

char	*malloc_word(char *str, int start)
{
	int		length;
	int		i;
	char	*word;
	char	c;

	i = 0;
	c = 0;
	length = ft_substrlen(str, start, c) - start;
	word = malloc(sizeof(char) * (length + 1));
	while (i < length)
	{
		word[i] = str[start + i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**split_mode(char **strs, char *str, int i, int j)
{
	char	c;

	while (str[++i])
	{
		if (ft_isquote(str[i]))
		{
			if (i == 0 || ft_isspace(str[i - 1]))
				strs[j++] = malloc_word(str, i);
			c = str[i++];
			while (str[i] && str[i] != c)
				i++;
		}
		else if (!ft_isquote(str[i]) && !ft_isspace(str[i])
			&& (i == 0 || ft_isspace(str[i - 1])))
			strs[j++] = malloc_word(str, i);
		if ((size_t)i == ft_strlen(str))
			break ;
	}
	strs[j] = NULL;
	return (strs);
}

char	**split_outer_spaces(char *str)
{
	char	**strs;
	int		i;
	int		j;

	i = -1;
	j = 0;
	strs = malloc(sizeof(char *) * (strcount(str, -1, 0) + 1));
	if (!strs)
		return (NULL);
	strs = split_mode(strs, str, i, j);
	return (strs);
}
