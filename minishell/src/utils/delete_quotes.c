/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 11:55:53 by gpimenta          #+#    #+#             */
/*   Updated: 2023/04/21 17:20:38 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include <stdio.h>

char	*delete_quotes(char *str, int i, int j)
{
	char	c;
	char	*final;

	final = calloc(sizeof(char), ft_strlen(str) + 1);
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			c = str[i++];
			while (str[i])
			{
				if (str[i] != c)
					final[j++] = str[i];
				else if (str[i] == c)
					break ;
				i++;
			}
		}
		else
			final[j++] = str[i];
		i++;
	}
	final[j] = '\0';
	free(str);
	return (final);
}
