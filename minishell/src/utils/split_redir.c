/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:31:55 by gpimenta          #+#    #+#             */
/*   Updated: 2023/04/22 14:05:24 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*extract_sign(char *str, char *res, int *k)
{
	int		j;
	char	c;

	j = 0;
	c = str[*k];
	while (str[*k] && (str[*k] == c))
	{
		res[j++] = str[*k];
		(*k)++;
	}
	res[j] = '\0';
	return (res);
}

char	*extract_str(char *str, char *res, int *k, int j)
{
	char	c;

	while (str[*k] && (str[*k] != '>' && str[*k] != '<' && str[*k] != '|'))
	{
		res[j++] = str[*k];
		if (str[*k] == '\'' || str[*k] == '\"')
		{
			c = str[(*k)++];
			while (str[*k])
			{
				res[j++] = str[*k];
				if (str[*k] == c)
					break ;
				(*k)++;
			}
		}
		(*k)++;
	}
	res[j] = '\0';
	return (res);
}

char	*ft_extract(char *str, int *k)
{
	char	*res;

	if (str[*k] == '>' || str[*k] == '<' || str[*k] == '|')
	{
		res = ft_calloc(sizeof(char), 3);
		return (extract_sign(str, res, k));
	}
	else
	{
		res = ft_calloc(sizeof(char), ft_getsize(str + (*k)) + 1);
		res = extract_str(str, res, k, 0);
	}
	return (res);
}

char	**split_redir(char **tab, int j)
{
	char	**n_tab;
	int		i;
	int		k;

	i = -1;
	n_tab = malloc(sizeof(char *) * (tab_len(tab)
				+ count_redir(tab, -1, -1) + 1));
	if (!n_tab)
		return (NULL);
	while (tab[++i])
	{
		if (ft_strchr_2(tab[i], '>') || ft_strchr_2(tab[i], '<')
			|| ft_strchr_2(tab[i], '|'))
		{
			k = 0;
			while (tab[i][k])
				n_tab[j++] = ft_extract(tab[i], &k);
		}
		else
			n_tab[j++] = ft_strdup(tab[i]);
	}
	n_tab[j] = 0;
	ft_free_tab(tab);
	return (n_tab);
}
