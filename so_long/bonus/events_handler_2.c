/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_handler_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 15:17:45 by gpimenta          #+#    #+#             */
/*   Updated: 2023/03/09 12:03:01 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	move_up(t_vars *vars)
{
	if (vars->map[vars->y_p - 1][vars->x_p] == '1' ||
		(vars->map[vars->y_p - 1][vars->x_p] == 'E' && vars->c_counter))
		return ;
	if (vars->map[vars->y_p - 1][vars->x_p] == 'C')
		vars->c_counter--;
	if (vars->map[vars->y_p - 1][vars->x_p] == 'B')
		end_game(vars, 0);
	else if (vars->map[vars->y_p - 1][vars->x_p] == 'E' && !vars->c_counter)
		end_game(vars, 1);
	texture_loading(&vars->floor, vars, vars->x_p, vars->y_p);
	texture_loading(&vars->floor, vars, vars->x_p, vars->y_p - 1);
	texture_loading(&vars->p_up, vars, vars->x_p, vars->y_p - 1);
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->fimg_ptr, 0, 0);
	vars->map[vars->y_p][vars->x_p] = '0';
	vars->map[vars->y_p - 1][vars->x_p] = 'P';
	vars->y_p--;
	vars->move++;
	ft_write_move(vars);
}

void	move_down(t_vars *vars)
{
	if (vars->map[vars->y_p + 1][vars->x_p] == '1' ||
		(vars->map[vars->y_p + 1][vars->x_p] == 'E' && vars->c_counter))
		return ;
	if (vars->map[vars->y_p + 1][vars->x_p] == 'C')
		vars->c_counter--;
	if (vars->map[vars->y_p + 1][vars->x_p] == 'B')
		end_game(vars, 0);
	else if (vars->map[vars->y_p + 1][vars->x_p] == 'E' && !vars->c_counter)
		end_game(vars, 1);
	texture_loading(&vars->floor, vars, vars->x_p, vars->y_p);
	texture_loading(&vars->floor, vars, vars->x_p, vars->y_p + 1);
	texture_loading(&vars->p_down, vars, vars->x_p, vars->y_p + 1);
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->fimg_ptr, 0, 0);
	vars->map[vars->y_p][vars->x_p] = '0';
	vars->map[vars->y_p + 1][vars->x_p] = 'P';
	vars->y_p++;
	vars->move++;
	ft_write_move(vars);
}

void	move_left(t_vars *vars)
{
	if (vars->map[vars->y_p][vars->x_p - 1] == '1' ||
		(vars->map[vars->y_p][vars->x_p - 1] == 'E' && vars->c_counter))
		return ;
	if (vars->map[vars->y_p][vars->x_p - 1] == 'C')
		vars->c_counter--;
	if (vars->map[vars->y_p][vars->x_p - 1] == 'B')
		end_game(vars, 0);
	else if (vars->map[vars->y_p][vars->x_p - 1] == 'E' && !vars->c_counter)
		end_game(vars, 1);
	texture_loading(&vars->floor, vars, vars->x_p, vars->y_p);
	texture_loading(&vars->floor, vars, vars->x_p - 1, vars->y_p);
	texture_loading(&vars->p_left, vars, vars->x_p - 1, vars->y_p);
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->fimg_ptr, 0, 0);
	vars->map[vars->y_p][vars->x_p] = '0';
	vars->map[vars->y_p][vars->x_p - 1] = 'P';
	vars->x_p--;
	vars->move++;
	ft_write_move(vars);
}

void	move_right(t_vars *vars)
{
	if (vars->map[vars->y_p][vars->x_p + 1] == '1' ||
		(vars->map[vars->y_p][vars->x_p + 1] == 'E' && vars->c_counter))
		return ;
	if (vars->map[vars->y_p][vars->x_p + 1] == 'C')
		vars->c_counter--;
	if (vars->map[vars->y_p][vars->x_p + 1] == 'B')
		end_game(vars, 0);
	else if (vars->map[vars->y_p][vars->x_p + 1] == 'E' && !vars->c_counter)
		end_game(vars, 1);
	texture_loading(&vars->floor, vars, vars->x_p, vars->y_p);
	texture_loading(&vars->floor, vars, vars->x_p + 1, vars->y_p);
	texture_loading(&vars->p_init, vars, vars->x_p + 1, vars->y_p);
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->fimg_ptr, 0, 0);
	vars->map[vars->y_p][vars->x_p] = '0';
	vars->map[vars->y_p][vars->x_p + 1] = 'P';
	vars->x_p++;
	vars->move++;
	ft_write_move(vars);
}
