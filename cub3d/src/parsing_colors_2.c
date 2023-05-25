/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_colors_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:07:37 by gpimenta          #+#    #+#             */
/*   Updated: 2023/05/24 19:20:07 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_isdigit_str(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] < '0' || str[i] > '9')
			return (0);
	return (1);
}

int	verify_number(char **rgb)
{
	int	i;

	i = -1;
	while (rgb[++i])
	{
		if (!ft_isdigit_str(rgb[i]))
			return (0);
	}
	return (1);
}
