/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:12:29 by gpimenta          #+#    #+#             */
/*   Updated: 2023/05/25 14:38:03 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_player(int y, int x)
{
	if (cub()->map[y][x] == 'N' || cub()->map[y][x] == 'S'
		|| cub()->map[y][x] == 'W' || cub()->map[y][x] == 'E')
		return (1);
	return (0);
}

int	check_y(int condition)
{
	if (condition == 0)
		return ((int)(cub()->pos_y + cub()->dir_y));
	else if (condition == 1)
		return ((int)(cub()->pos_y + cub()->dir_y + cub()->pla_y));
	else if (condition == 2)
		return ((int)(cub()->pos_y + cub()->dir_y - cub()->pla_y));
	return (1);
}

int	check_x(int condition)
{
	if (condition == 0)
		return ((int)(cub()->pos_x + cub()->dir_x));
	else if (condition == 1)
		return ((int)(cub()->pos_x + cub()->dir_x + cub()->pla_x));
	else if (condition == 2)
		return ((int)(cub()->pos_x + cub()->dir_x - cub()->pla_x));
	return (1);
}

int	not_wall(int i)
{
	if (cub()->map[check_y(i)][check_x(i)] != '1')
		return (1);
	return (0);
}

void	draw_minimap(void)
{
	int	x;
	int	y;

	y = -1;
	while (cub()->map[++y])
	{
		x = -1;
		while (cub()->map[y][++x])
		{
			if (cub()->map[y][x] == '1')
				paint(x, y, WALL);
			else if (cub()->map[y][x] == '0' || check_player(y, x))
				paint(x, y, EMPTY_SPACE);
			if ((y == check_y(0) && x == check_x(0) && not_wall(0))
				|| (y == check_y(1) && x == check_x(1) && not_wall(1))
				|| (y == check_y(2) && x == check_x(2) && not_wall(2)))
				paint(x, y, RAYS);
			if (y == (int)cub()->pos_y && x == (int)cub()->pos_x)
				paint(x, y, PLAYER);
		}
	}
}
