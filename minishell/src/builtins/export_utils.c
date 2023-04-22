/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 14:19:26 by gpimenta          #+#    #+#             */
/*   Updated: 2023/04/22 15:29:10 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	index_var(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			break ;
		i++;
	}
	return (i);
}

char	*var_extrator(char *str)
{
	char	*var;
	int		i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	var = malloc(sizeof(char) * (i + 1));
	if (!var)
		return (NULL);
	i = -1;
	while (str[++i] && str[i] != '=')
		var[i] = str[i];
	var[i] = '\0';
	return (var);
}

char	*name_substr(char *str)
{
	char	*name;
	int		i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '=')
			break ;
	}
	name = ft_substr(str, ++i, ft_strlen(str));
	return (name);
}

char	*set_declared_env(char *str)
{
	char	*final;

	final = ft_strjoin("declare -x ", str);
	return (final);
}
