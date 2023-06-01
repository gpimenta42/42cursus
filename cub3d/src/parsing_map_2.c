/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:25:06 by gpimenta          #+#    #+#             */
/*   Updated: 2023/05/28 14:51:26 by jaiveca-         ###   ########.fr       */
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

int	check_any_other_wall(char **all, int j)
{
	while (all[j])
	{
		if (all[j][skip_spaces(all, j, 0)] == '1'
			|| all[j][skip_spaces(all, j, 0)] == '0')
			return (1);
		j++;
	}
	return (0);
}

void	free_map_elements(void)
{
	if (cub()->rgb_c)
		free(cub()->rgb_c);
	if (cub()->rgb_f)
		free(cub()->rgb_f);
	if (cub()->no_path)
		free(cub()->no_path);
	if (cub()->so_path)
		free(cub()->so_path);
	if (cub()->we_path)
		free(cub()->we_path);
	if (cub()->ea_path)
		free(cub()->ea_path);
	if (cub()->map)
		ft_free(cub()->map, NULL);
	if (cub()->all)
		ft_free(cub()->all, NULL);
	if (cub()->texture)
		ft_free_int(cub()->texture);
}
