/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_enemies.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:31:04 by gpimenta          #+#    #+#             */
/*   Updated: 2023/03/09 12:01:26 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	move_up_enemy(t_vars *vars, int j)
{
	if (vars->map[vars->array_y_e[j] - 1][vars->array_x_e[j]] == '1' ||
		vars->map[vars->array_y_e[j] - 1][vars->array_x_e[j]] == 'E' ||
		vars->map[vars->array_y_e[j] - 1][vars->array_x_e[j]] == 'C' ||
		vars->map[vars->array_y_e[j] - 1][vars->array_x_e[j]] == 'B')
		return ;
	if (vars->map[vars->array_y_e[j] - 1][vars->array_x_e[j]] == 'P')
		end_game(vars, 0);
	vars->map[vars->array_y_e[j] - 1][vars->array_x_e[j]] = 'B';
	vars->map[vars->array_y_e[j]][vars->array_x_e[j]] = '0';
	texture_loading(&vars->floor, vars, vars->array_x_e[j], vars->array_y_e[j]);
	texture_loading(&vars->floor, vars, vars->array_x_e[j],
		vars->array_y_e[j] - 1);
	texture_loading(&vars->enemy, vars, vars->array_x_e[j],
		vars->array_y_e[j] - 1);
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->fimg_ptr, 0, 0);
	vars->array_y_e[j]--;
}

void	move_down_enemy(t_vars *vars, int j)
{
	if (vars->map[vars->array_y_e[j] + 1][vars->array_x_e[j]] == '1' ||
		vars->map[vars->array_y_e[j] + 1][vars->array_x_e[j]] == 'E' ||
		vars->map[vars->array_y_e[j] + 1][vars->array_x_e[j]] == 'C' ||
		vars->map[vars->array_y_e[j] + 1][vars->array_x_e[j]] == 'B')
		return ;
	if (vars->map[vars->array_y_e[j] + 1][vars->array_x_e[j]] == 'P')
		end_game(vars, 0);
	vars->map[vars->array_y_e[j] + 1][vars->array_x_e[j]] = 'B';
	vars->map[vars->array_y_e[j]][vars->array_x_e[j]] = '0';
	texture_loading(&vars->floor, vars, vars->array_x_e[j], vars->array_y_e[j]);
	texture_loading(&vars->floor, vars, vars->array_x_e[j],
		vars->array_y_e[j] + 1);
	texture_loading(&vars->enemy, vars, vars->array_x_e[j],
		vars->array_y_e[j] + 1);
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->fimg_ptr, 0, 0);
	vars->array_y_e[j]++;
}

void	move_right_enemy(t_vars *vars, int j)
{
	if (vars->map[vars->array_y_e[j]][vars->array_x_e[j] + 1] == '1' ||
		vars->map[vars->array_y_e[j]][vars->array_x_e[j] + 1] == 'E' ||
		vars->map[vars->array_y_e[j]][vars->array_x_e[j] + 1] == 'C' ||
		vars->map[vars->array_y_e[j]][vars->array_x_e[j] + 1] == 'B')
		return ;
	if (vars->map[vars->array_y_e[j]][vars->array_x_e[j] + 1] == 'P')
		end_game(vars, 0);
	vars->map[vars->array_y_e[j]][vars->array_x_e[j] + 1] = 'B';
	vars->map[vars->array_y_e[j]][vars->array_x_e[j]] = '0';
	texture_loading(&vars->floor, vars, vars->array_x_e[j], vars->array_y_e[j]);
	texture_loading(&vars->floor, vars, vars->array_x_e[j] + 1,
		vars->array_y_e[j]);
	texture_loading(&vars->enemy, vars, vars->array_x_e[j] + 1,
		vars->array_y_e[j]);
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->fimg_ptr, 0, 0);
	vars->array_x_e[j]++;
}

void	move_left_enemy(t_vars *vars, int j)
{
	if (vars->map[vars->array_y_e[j]][vars->array_x_e[j] - 1] == '1' ||
		vars->map[vars->array_y_e[j]][vars->array_x_e[j] - 1] == 'E' ||
		vars->map[vars->array_y_e[j]][vars->array_x_e[j] - 1] == 'C' ||
		vars->map[vars->array_y_e[j]][vars->array_x_e[j] - 1] == 'B')
		return ;
	if (vars->map[vars->array_y_e[j]][vars->array_x_e[j] - 1] == 'P')
		end_game(vars, 0);
	vars->map[vars->array_y_e[j]][vars->array_x_e[j] - 1] = 'B';
	vars->map[vars->array_y_e[j]][vars->array_x_e[j]] = '0';
	texture_loading(&vars->floor, vars, vars->array_x_e[j], vars->array_y_e[j]);
	texture_loading(&vars->floor, vars, vars->array_x_e[j] - 1,
		vars->array_y_e[j]);
	texture_loading(&vars->enemy, vars, vars->array_x_e[j] - 1,
		vars->array_y_e[j]);
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->fimg_ptr, 0, 0);
	vars->array_x_e[j]--;
}

void	enemy_movement(t_vars *vars, int j)
{
	static int	i;

	if (i == 1500)
	{
		while (vars->array_x_e[++j])
		{
			if (vars->x_p > vars->array_x_e[j])
				move_right_enemy(vars, j);
			else if (vars->x_p < vars->array_x_e[j])
				move_left_enemy(vars, j);
		}
	}
	else if (i == 3000)
	{
		while (vars->array_y_e[++j])
		{
			if (vars->y_p > vars->array_y_e[j])
				move_down_enemy(vars, j);
			else if (vars->y_p < vars->array_y_e[j])
				move_up_enemy(vars, j);
		}
		i = 0;
	}
	i++;
}
