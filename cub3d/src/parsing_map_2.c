/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:25:06 by gpimenta          #+#    #+#             */
/*   Updated: 2023/05/25 14:25:20 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_condition(int j, int i)
{
	if (j > 0 && cub()->map[j + 1] != 0 && is_space(j, i)
		&& ((cub()->map[j][skip_spaces(cub()->map, j, i)] != '1'
			&& cub()->map[j][skip_spaces(cub()->map, j, i)] != '\0')
			|| (i != 0 && cub()->map[j][i - 1] != '1' && !is_space(j, i - 1))
			|| (cub()->map[j - 1][i] != '1' && !is_space(j - 1, i))
			|| (cub()->map[j + 1][i] != '1' && !is_space(j + 1, i))))
		return (1);
	return (0);
}
