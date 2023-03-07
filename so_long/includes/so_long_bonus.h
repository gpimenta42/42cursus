/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:50:27 by gpimenta          #+#    #+#             */
/*   Updated: 2023/03/07 18:43:40 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "minilibx-linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft/libft.h"

# define PIXEL 50

typedef struct s_flood
{
	int	check_c;
	int	check_e;
}	t_flood;

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		x;
	int		y;
}	t_img;

typedef struct s_vars
{
	char	**map;
	int		y_map;
	int		x_map;
	int		x_p;
	int		y_p;
	int		x_e;
	int		y_e;
	int		p_counter;
	int		e_counter;
	int		c_counter;
	int		move;
	t_flood	flood;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*fimg_ptr;
	char	*fimg_address;
	int		bpp;
	int		line_len;
	int		endian;
	t_img	p_init;
	t_img	p_left;
	t_img	p_up;
	t_img	p_down;
	t_img	wall;
	t_img	floor;
	t_img	collect[3];
	t_img	enemy;
	t_img	exit;
}	t_vars;

/*map validation*/
void	ber_file(char *str);
void	open_ber_file(char *str, t_vars *vars);
void	check_positions(t_vars *vars);
void	flood_fill(t_vars *vars, int y, int x, char **temp);
int		check_collectable_reachable(char **temp);
int		valid_path_checker(t_vars *vars);
void	ft_free(char **temp);
void	map_error(t_vars *vars);
int		rectangular_checker(t_vars *vars);
int		walled_checker(t_vars *vars);
int		composition_checker(t_vars *vars, int y, int x);
void	map_checker(t_vars *vars);
/*image_display*/
void	window_init(t_vars *vars);
void	put_pixel_to_window(t_vars *vars, int x, int y, unsigned int color);
void	texture_loading(t_img *type, t_vars *vars, int x_pos, int y_pos);
void	image_to_window(t_vars *vars, int x, int y);
void	image_init_1(t_vars *vars);
void	image_init_2(t_vars *vars);
void	address_finder(t_vars *vars);
void	address_finder_2(t_vars *vars);
/*movements and events*/
char	*ft_itoa(int nbr);
void	ft_write_move(t_vars *vars);
void	move_up(t_vars *vars);
void	move_down(t_vars *vars);
void	move_left(t_vars *vars);
void	move_right(t_vars *vars);
int		end_game(t_vars *vars, int flag);
int		key_press_handler(int keycode, t_vars *vars);
void	ft_hook(t_vars *vars);

#endif
