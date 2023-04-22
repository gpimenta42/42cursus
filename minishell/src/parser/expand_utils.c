/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 14:01:04 by gpimenta          #+#    #+#             */
/*   Updated: 2023/04/22 15:28:13 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	get_extent(char *str, int i)
{
	int	count;

	count = 0;
	if (str[i] == '$')
	{
		i++;
		count++;
	}
	while (str[i])
	{
		if (str[i] == '$')
			break ;
		count++;
		i++;
	}
	return (count);
}

int	get_var_size(char *str, int i)
{
	int	count;

	count = 0;
	while (str[i])
	{
		if (ft_isalnum(str[i]))
			count++;
		else
			break ;
		i++;
	}
	return (count);
}

int	get_after_var(char *str, int i)
{
	while (str[i])
	{
		if (!ft_isalnum(str[i]))
			break ;
		i++;
	}
	return (i);
}

int	get_index(char *str, int i)
{
	if (str[i] == '$')
		i++;
	while (str[i])
	{
		if (str[i] == '$')
			break ;
		i++;
	}
	return (i);
}

int	get_index_2(char *str, int i)
{
	while (str[i])
	{
		if (str[i] == '$' && str[i + 1] == '?')
			break ;
		i++;
	}
	return (i);
}
