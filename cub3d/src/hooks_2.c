/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:10:11 by gpimenta          #+#    #+#             */
/*   Updated: 2023/05/24 17:55:46 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_vertical(char c)
{
	if (c == 'w')
	{
		if (cub()->map[(int) cub()->pos_y]
			[(int)(cub()->pos_x + cub()->dir_x * cub()->move_speed)] != '1')
			cub()->pos_x += cub()->dir_x * cub()->move_speed;
		if (cub()->map[(int)(cub()->pos_y + cub()->dir_y * cub()->move_speed)]
			[(int)cub()->pos_x] != '1')
			cub()->pos_y += cub()->dir_y * cub()->move_speed;
	}
	else if (c == 's')
	{
		if (cub()->map[(int) cub()->pos_y]
			[(int)(cub()->pos_x - cub()->dir_x * cub()->move_speed)] != '1')
			cub()->pos_x -= cub()->dir_x * cub()->move_speed;
		if (cub()->map[(int)(cub()->pos_y - cub()->dir_y * cub()->move_speed)]
			[(int)cub()->pos_x] != '1')
			cub()->pos_y -= cub()->dir_y * cub()->move_speed;
	}
}

void	move_horizontal(char c)
{
	if (c == 'a')
	{
		if (cub()->map[(int)cub()->pos_y]
			[(int)(cub()->pos_x + cub()->dir_y * cub()->move_speed)] != '1')
			cub()->pos_x += cub()->dir_y * cub()->move_speed;
		if (cub()->map[(int)(cub()->pos_y - cub()->dir_x * cub()->move_speed)]
			[(int)cub()->pos_x] != '1')
			cub()->pos_y -= cub()->dir_x * cub()->move_speed;
	}
	else if (c == 'd')
	{
		if (cub()->map[(int)cub()->pos_y]
			[(int)(cub()->pos_x - cub()->dir_y * cub()->move_speed)] != '1')
			cub()->pos_x -= cub()->dir_y * cub()->move_speed;
		if (cub()->map[(int)(cub()->pos_y + cub()->dir_x * cub()->move_speed)]
			[(int)cub()->pos_x] != '1')
			cub()->pos_y += cub()->dir_x * cub()->move_speed;
	}
}

void	rotate_left(double old_dir_x, double old_pla_x)
{
	cub()->dir_x = cub()->dir_x * cos(-cub()->rot_speed)
	- cub()->dir_y * sin(-cub()->rot_speed);
	cub()->dir_y = old_dir_x * sin(-cub()->rot_speed)
	+ cub()->dir_y * cos(-cub()->rot_speed);
	cub()->pla_x = cub()->pla_x * cos(-cub()->rot_speed)
	- cub()->pla_y * sin(-cub()->rot_speed);
	cub()->pla_y = old_pla_x * sin(-cub()->rot_speed)
	+ cub()->pla_y * cos(-cub()->rot_speed);
}

void	rotate_right(double old_dir_x, double old_pla_x)
{
	cub()->dir_x = cub()->dir_x * cos(cub()->rot_speed)
	- cub()->dir_y * sin(cub()->rot_speed);
	cub()->dir_y = old_dir_x * sin(cub()->rot_speed)
	+ cub()->dir_y * cos(cub()->rot_speed);
	cub()->pla_x = cub()->pla_x * cos(cub()->rot_speed)
	- cub()->pla_y * sin(cub()->rot_speed);
	cub()->pla_y = old_pla_x * sin(cub()->rot_speed)
	+ cub()->pla_y * cos(cub()->rot_speed);
}

void	rotate(char c)
{
	double	old_dir_x;
	double	old_pla_x;

	old_dir_x = cub()->dir_x;
	old_pla_x = cub()->pla_x;
	if (c == 'l')
		rotate_left(old_dir_x, old_pla_x);
	else if (c == 'r')
		rotate_right(old_dir_x, old_pla_x);
}
