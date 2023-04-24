/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:26:39 by gpimenta          #+#    #+#             */
/*   Updated: 2023/04/23 18:27:45 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	findouter(char *str, int i)
{
	int		flag;
	char	c;

	flag = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			c = str[i];
			i++;
			while (str[i])
			{
				if (str[i] == '$')
					flag = 1;
				if (str[i] == c && flag == 1)
					return (c);
				else if (str[i] == c && flag == 0)
					break ;
				i++;
			}
		}
		i++;
	}
	return (0);
}

int	check_expandable(char *str)
{
	char	c;

	if (ft_strchr(str, '\'') || ft_strchr(str, '\"'))
	{
		c = findouter(str, 0);
		if (c == '\"')
			return (1);
		else if (c == '\'')
			return (0);
	}
	return (1);
}

char	*ft_getenv(char *var, t_shell *shell)
{
	int		i;
	char	*res;
	char	*var2;

	i = 0;
	res = NULL;
	var2 = ft_strjoin_2(var, "=");
	while (shell->envp[i])
	{
		if (!ft_strncmp(var2, shell->envp[i], ft_strlen(var2)))
			res = ft_substr(shell->envp[i], ft_strlen(var2),
					ft_strlen(shell->envp[i]));
		i++;
	}
	free(var2);
	return (res);
}

void	expander(t_token *token, t_shell *shell)
{
	if (ft_strchr(token->name, '$') && check_expandable(token->name))
		token->name = expand_dollar(token->name, 0, 0, shell);
	if (ft_strchr(token->name, '$') && check_expandable(token->name))
		token->name = expand_error(token->name, 0);
	if (ft_strchr(token->name, '~'))
		expand_home(token);
	return ;
}

char	*expander_heredoc(char *str, t_shell *shell)
{
	if (ft_strchr(str, '$') && check_expandable(str))
		str = expand_dollar(str, 0, 0, shell);
	if (ft_strchr(str, '$') && check_expandable(str))
		str = expand_error(str, 0);
	return (str);
}
