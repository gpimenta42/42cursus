/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_handler_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 15:16:36 by gpimenta          #+#    #+#             */
/*   Updated: 2023/03/09 13:28:35 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

/*
int mlx_destroy_image(void *mlx_ptr, void *img_ptr)
int mlx_destroy_window(void *mlx_ptr, void *win_ptr)
int mlx_destroy_display(void *mlx_ptr)
*/

void	ft_free_end(t_vars *vars, int y)
{
	mlx_destroy_image(vars->mlx_ptr, vars->fimg_ptr);
	mlx_destroy_image(vars->mlx_ptr, vars->p_init.img_ptr);
	mlx_destroy_image(vars->mlx_ptr, vars->p_left.img_ptr);
	mlx_destroy_image(vars->mlx_ptr, vars->p_up.img_ptr);
	mlx_destroy_image(vars->mlx_ptr, vars->p_down.img_ptr);
	mlx_destroy_image(vars->mlx_ptr, vars->wall.img_ptr);
	mlx_destroy_image(vars->mlx_ptr, vars->exit.img_ptr);
	mlx_destroy_image(vars->mlx_ptr, vars->collect0.img_ptr);
	mlx_destroy_image(vars->mlx_ptr, vars->collect1.img_ptr);
	mlx_destroy_image(vars->mlx_ptr, vars->collect2.img_ptr);
	mlx_destroy_image(vars->mlx_ptr, vars->collect3.img_ptr);
	mlx_destroy_image(vars->mlx_ptr, vars->enemy.img_ptr);
	mlx_destroy_image(vars->mlx_ptr, vars->floor.img_ptr);
	mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
	mlx_destroy_display(vars->mlx_ptr);
	free(vars->mlx_ptr);
	while (vars->map[++y])
		free(vars->map[y]);
	free(vars->map);
	free(vars->array_x_e);
	free(vars->array_y_e);
}

int	end_game(t_vars *vars, int flag)
{
	ft_free_end(vars, -1);
	if (flag == 1)
		ft_putstr_fd("\033[0;32mSuccess, YOU WON!\n\033[0;32m", 1);
	else if (flag == 0)
		ft_putstr_fd("\033[0;31mYou lose, GAME OVER!\n\033[0;31m", 1);
	exit (0);
	return (1);
}

/*keycode
w 119
a 97
s 115
d 100
ESC 65307
*/

int	key_press_handler(int keycode, t_vars *vars)
{
	if (keycode == 119)
		move_up(vars);
	else if (keycode == 97)
		move_left(vars);
	else if (keycode == 115)
		move_down(vars);
	else if (keycode == 100)
		move_right(vars);
	else if (keycode == 65307)
		end_game(vars, -1);
	return (1);
}

int	orbs(t_vars *vars)
{
	static int	i;

	ft_write_move(vars);
	if (vars->e_counter)
		enemy_movement(vars, -1);
	if (i < 250)
		orbs_to_window(vars, 0);
	else if (i < 500)
		orbs_to_window(vars, 1);
	else if (i < 750)
		orbs_to_window(vars, 2);
	else if (i < 1000)
		orbs_to_window(vars, 3);
	if (i == 1000)
		i = 0;
	ft_write_move(vars);
	i++;
	return (1);
}

/*
int mlx_key_hook (void *win_ptr, int (*funct_ptr)(), void *param);
funct_ptr is a pointer to the function you want to be called with event.
This assignment is specific to the window defined by the  win_ptr  identifier.
The param  adress  will be passed to the function everytime it is called,
and should be used to store the parameters it might need.
When it catches an event, the MiniLibX calls the function with fixed parameters:
     key_hook(int keycode,void *param);
     mouse_hook(int button,int x,int y,void *param);
	 expose_hook(void *param);
     loop_hook(void *param);
*/

/*int mlx_hook(void *win_ptr, int x_event, int x_mask,
	int (*funct)(), void *param)
The mlx.h include defines mlx_hook() in the same manner mlx_*_hook work.
The event and mask values will be taken from the X11 include file X.h
*/

/*
Event
KeyPress => 02
DestroyNotify => 17

Masks
KeyPressMask => 1L<<0
*/

/*
int mlx_loop_hook(void *mlx_ptr, int (*funct_ptr)(), void *param);
The syntax for the mlx_loop_hook () function is identical but  the
given function will be called when no event occurs.
	loop_hook(void *param);
*/

/*
int mlx_loop ( void *mlx_ptr );
To receive events, you must use mlx_loop ().
This function never returns.
It is an infinite loop  that  waits for an event,
and then calls a user-defined function associated with this event.
A single parameter is needed, the connection identifier mlx_ptr
*/

void	ft_hook(t_vars *vars)
{
	ft_write_move(vars);
	mlx_hook(vars->win_ptr, 2, 1L, key_press_handler, vars);
	mlx_hook(vars->win_ptr, 17, 1L, end_game, vars);
	mlx_loop_hook(vars->mlx_ptr, orbs, vars);
	mlx_loop(vars->mlx_ptr);
}
	// mlx_loop_hook(vars->win_ptr, enemy, vars);
