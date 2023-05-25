/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:39:44 by gpimenta          #+#    #+#             */
/*   Updated: 2023/05/25 16:53:17 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	rays_loop(void)
{
	cub()->hit = 0;
	while (cub()->hit == 0)
	{
		if (cub()->side_x < cub()->side_y)
		{
			cub()->side_x += cub()->delta_x;
			cub()->map_x += cub()->step_x;
			cub()->side = 0;
		}
		else
		{
			cub()->side_y += cub()->delta_y;
			cub()->map_y += cub()->step_y;
			cub()->side = 1;
		}
		if (cub()->map[cub()->map_y][cub()->map_x] == '1')
		{
			cub()->hit = 1;
			set_texture();
		}
	}
}

void	calculate_wall_distance_height(void)
{
	if (cub()->side == 1)
		cub()->wall_dist = cub()->side_y - cub()->delta_y;
	else
		cub()->wall_dist = cub()->side_x - cub()->delta_x;
	cub()->wall_y = (int)(SCREEN_Y / cub()->wall_dist);
	cub()->pixel_y_start = (SCREEN_Y / 2) - (cub()->wall_y / 2);
	if (cub()->pixel_y_start < 0)
		cub()->pixel_y_start = 0;
	cub()->pixel_y_end = (SCREEN_Y / 2) + (cub()->wall_y / 2);
	if (cub()->pixel_y_end >= SCREEN_Y)
		cub()->pixel_y_end = SCREEN_Y - 1;
}

void	calculate_texture_x(void)
{
	double	wall_x;

	if (cub()->side == 0)
		wall_x = cub()->pos_y + (cub()->wall_dist * cub()->ray_y);
	else
		wall_x = cub()->pos_x + (cub()->wall_dist * cub()->ray_x);
	wall_x -= floor(wall_x);
	cub()->texture_x = (int)(wall_x * (double)cub()->texture_width[cub()->texture_index]);
	if (cub()->side == 1 && cub()->ray_y < 0)
		cub()->texture_x = cub()->texture_width[cub()->texture_index] - cub()->texture_x - 1;
}

void	draw_wall_x(int x)
{
	double			step;
	double			texture_pos;
	int				y;
	int				texture_y;
	unsigned int	color;

	step = 1.0 * cub()->texture_height[cub()->texture_index] / cub()->wall_y;
	texture_pos = (cub()->pixel_y_start - SCREEN_Y / 2
			+ cub()->wall_y / 2) * step;
	y = cub()->pixel_y_start;
	while (y < cub()->pixel_y_end)
	{
		texture_y = (int) texture_pos & (cub()->texture_height[cub()->texture_index] - 1);
		texture_pos += step;
		color = cub()->texture[cub()->texture_index]
		[cub()->texture_height[cub()->texture_index] * texture_y + cub()->texture_x];
		if (cub()->side == 1)
			color = (color >> 1) & 8355711;
		pixel_put(x, y, color);
		y++;
	}
}
