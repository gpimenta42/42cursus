/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_outer_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 14:04:13 by gpimenta          #+#    #+#             */
/*   Updated: 2023/04/22 14:04:23 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_isspace(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	ft_isquote(char c)
{
	if (c == '\"' || c == '\'')
		return (1);
	return (0);
}
