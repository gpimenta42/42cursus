/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:46:16 by gpimenta          #+#    #+#             */
/*   Updated: 2023/05/25 14:53:47 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	walled_checker(void)
{
	int	i;
	int	j;

	j = -1;
	while (cub()->map[++j])
	{
		i = -1;
		while (cub()->map[j][++i])
		{
			if (j == 0 && cub()->map[0][i] != '1' && !is_space(0, i))
				return (0);
			if (check_condition(j, i))
				return (0);
			if (j > 0 && cub()->map[j + 1] != 0 && cub()->map[j][i + 1] == '\0'
			&& cub()->map[j][prev_wall(j, i)] != '1')
				return (0);
			if (cub()->map[j + 1] == 0 && cub()->map[j][i] != '1'
			&& (cub()->map[j][i] < 9 || cub()->map[j][i] > 13)
			&& cub()->map[j][i] != 32)
				return (0);
		}
	}
	return (1);
}

int	check_char(int j, int i, int condition)
{
	if (condition == 0)
	{
		if (cub()->map[j][i] != '1' && !is_space(j, i)
			&& cub()->map[j][i] != '0' && cub()->map[j][i] != 'S'
			&& cub()->map[j][i] != 'N' && cub()->map[j][i] != 'W'
				&& cub()->map[j][i] != 'E')
			return (1);
	}
	else if (condition == 1)
	{
		if (cub()->map[j][i] == 'S' || cub()->map[j][i] == 'N'
			|| cub()->map[j][i] == 'W' || cub()->map[j][i] == 'E')
			return (1);
	}
	return (0);
}

int	composition_checker(void)
{
	int	j;
	int	i;
	int	player_count;

	j = -1;
	player_count = 0;
	while (cub()->map[++j])
	{
		i = -1;
		while (cub()->map[j][++i])
		{
			if (check_char(j, i, 0))
				return (0);
			else if (check_char(j, i, 1))
			{
				player_count++;
				cub()->y_p = j;
				cub()->x_p = i;
				cub()->dir = cub()->map[j][i];
			}
		}
	}
	if (player_count != 1)
		return (0);
	return (1);
}

int	map_size(char **all)
{
	int	j;
	int	count;
	int	flag;

	j = -1;
	count = 0;
	flag = 0;
	while (all[++j])
	{
		if (all[j][skip_spaces(all, j, 0)] == '1')
		{
			if (flag == 0)
			{
				flag = 1;
				cub()->map_line = j;
			}
			count++;
		}
	}
	return (count);
}

int	map_allocation(char **all)
{
	int	j;
	int	i;
	int	count;

	i = -1;
	cub()->map = NULL;
	count = map_size(all);
	cub()->map = malloc(sizeof(char *) * (count + 1));
	if (!cub()->map)
		return (0);
	j = -1;
	while (all[++j])
		if (all[j][skip_spaces(all, j, 0)] == '1'
			|| all[j][skip_spaces(all, j, 0)] == '0')
			cub()->map[++i] = ft_strdup(all[j]);
	cub()->map[++i] = 0;
	if (!cub()->map)
		return (0);
	return (1);
}
