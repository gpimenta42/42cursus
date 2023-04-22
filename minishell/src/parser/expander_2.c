/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 14:02:53 by gpimenta          #+#    #+#             */
/*   Updated: 2023/04/22 15:28:17 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*non_alphanum(char *str, char *res, int *i)
{
	char	*var;

	var = ft_substr(str, *i, get_extent(str, *i));
	res = ft_strjoin_2(res, var);
	free(var);
	*i = get_index(str, *i);
	return (res);
}

char	*expand_dollar(char *str, int i, char *expanded_var, t_shell *shell)
{
	char	*var;
	char	*res;

	res = NULL;
	while (str[i])
	{
		if (str[i] == '$' && (ft_isalnum(str[i + 1]) || (str[i + 1] == '\''
					&& str[i + 2]) || (str[i + 1] == '\"' && str[i + 2])))
		{
			i++;
			var = ft_substr(str, i, get_var_size(str, i));
			expanded_var = ft_getenv(var, shell);
			if (expanded_var)
			{
				res = ft_strjoin_2(res, expanded_var);
				free(expanded_var);
			}
			i = get_after_var(str, i);
		}
		else
			res = non_alphanum(str, res, &i);
	}
	free(str);
	return (res);
}

void	expand_home(t_token *token)
{
	if (ft_strcmp(token->name, "~"))
		return ;
	free(token->name);
	token->name = ft_strdup(getenv("HOME"));
}

char	*expand_error(char *str, int i)
{
	char	*final;
	char	*exit_str;
	char	*res;

	final = NULL;
	while (str[i])
	{
		if (str[i] == '$' && str[i + 1] == '?')
		{
			exit_str = ft_itoa(g_global.exit_code);
			final = ft_strjoin_2(final, exit_str);
			free(exit_str);
			i += 2;
		}
		else
		{
			res = ft_substr(str, i, get_index_2(str, i));
			final = ft_strjoin_2(final, res);
			free(res);
			i = get_index_2(str, i);
		}
	}
	free(str);
	return (final);
}
