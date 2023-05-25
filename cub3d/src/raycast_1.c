/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:07:35 by gpimenta          #+#    #+#             */
/*   Updated: 2023/05/23 18:41:39 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	calculate_ray_delta(int x)
{
	double	camera_x;

	camera_x = (2 * x / (double)SCREEN_X) - 1;
	cub()->ray_x = cub()->dir_x + (camera_x * cub()->pla_x);
	cub()->ray_y = cub()->dir_y + (camera_x * cub()->pla_y);
	if (cub()->ray_x == 0)
		cub()->delta_x = 1e30;
	else
		cub()->delta_x = fabs(1 / cub()->ray_x);
	if (cub()->ray_y == 0)
		cub()->delta_y = 1e30;
	else
		cub()->delta_y = fabs(1 / cub()->ray_y);
}

void	calculate_side(void)
{
	if (cub()->ray_x < 0)
	{
		cub()->side_x = (cub()->pos_x - cub()->map_x) * cub()->delta_x;
		cub()->step_x = -1;
	}
	else
	{
		cub()->side_x = (1.0 + cub()->map_x - cub()->pos_x) * cub()->delta_x;
		cub()->step_x = 1;
	}
	if (cub()->ray_y < 0)
	{
		cub()->side_y = (cub()->pos_y - cub()->map_y) * cub()->delta_y;
		cub()->step_y = -1;
	}
	else
	{
		cub()->side_y = (1.0 + cub()->map_y - cub()->pos_y) * cub()->delta_y;
		cub()->step_y = 1;
	}
}

void	set_texture(void)
{
	if (cub()->side == 1)
	{
		if (cub()->map_y > cub()->pos_y)
			cub()->texture_index = 1;
		else
			cub()->texture_index = 0;
	}
	else if (cub()->side == 0)
	{
		if (cub()->map_x > cub()->pos_x)
			cub()->texture_index = 3;
		else
			cub()->texture_index = 2;
	}
}

void	set_map_vectors(void)
{
	cub()->map_x = (int) cub()->pos_x;
	cub()->map_y = (int) cub()->pos_y;
}

void	raycast_walls(void)
{
	int	x;

	x = -1;
	while (++x < SCREEN_X)
	{
		set_map_vectors();
		calculate_ray_delta(x);
		calculate_side();
		rays_loop();
		calculate_wall_distance_height();
		calculate_texture_x();
		draw_wall_x(x);
	}
}
