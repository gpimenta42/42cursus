/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:38:24 by gpimenta          #+#    #+#             */
/*   Updated: 2023/05/25 17:27:20 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <limits.h>
# include "minilibx-linux/mlx.h"
# include "libft/libft.h"

# define SCREEN_Y 1080
# define SCREEN_X 1920
# define WALL 0x000000
# define EMPTY_SPACE 0xC3BCC5
# define PLAYER 0x5B6586
# define RAYS 0xEADF8A
# define MINIMAP_PIXEL 8

typedef struct s_img
{
	void	*img;
	char	*address;
	int		bpp;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_texture
{
	void	*img;
	int		*address;
	int		bpp;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_texture;

typedef struct s_cub
{
	char			**map;
	char			**all;
	int				x_p;
	int				y_p;
	char			dir;
	char			*no_path;
	char			*so_path;
	char			*we_path;
	char			*ea_path;
	int				*rgb_f;
	int				*rgb_c;
	void			*mlx;
	void			*win;
	t_img			canvas;
	unsigned long	floor;
	unsigned long	ceiling;
	int				map_line;
	int				**texture;
	int				texture_width[4];
	int				texture_height[4];
	double			pos_x;
	double			pos_y;
	int				map_x;
	int				map_y;
	int				hit;
	double			dir_x;
	double			dir_y;
	double			pla_x;
	double			pla_y;
	double			ray_x;
	double			ray_y;
	double			delta_x;
	double			delta_y;
	double			side_x;
	double			side_y;
	int				step_x;
	int				step_y;
	int				side;
	int				texture_index;
	double			wall_dist;
	int				wall_y;
	int				pixel_y_start;
	int				pixel_y_end;
	int				texture_x;
	double			frame_time;
	double			move_speed;
	double			rot_speed;
	int				key_w;
	int				key_a;
	int				key_d;
	int				key_s;
	int				arrow_left;
	int				arrow_right;
	double			mouse_old_x;
}	t_cub;

t_cub			*cub(void);
void			game_init(void);
void			define_constants(void);
void			vectors(void);
void			draw_minimap(void);
void			paint(int x, int y, int color);
int				check_player(int y, int x);
int				mouse_move(int x);
int				key_release(int keycode);
int				key_press(int keycode);
int				quit_game(void);
void			hooks(void);
void			rotate(char c);
void			move_horizontal(char c);
void			move_vertical(char c);
void			raycast_walls(void);
void			set_map_vectors(void);
void			draw_wall_x(int x);
void			calculate_texture_x(void);
void			calculate_wall_distance_height(void);
void			rays_loop(void);
void			set_texture(void);
void			calculate_side(void);
void			calculate_ray_delta(int x);
void			draw_ceiling(void);
void			draw_floor(void);
void			pixel_put(int x, int y, unsigned long color);
int				drawing(void);
void			colors_loading(void);
unsigned long	convert_colors(int	*rgb);
int				textures_loading(void);
int				fill_texture(t_texture img, int i);
int				parse(char *str);
int				valid_elements(char **all);
int				map_allocation(char **all);
int				colors_allocator(char **all);
int				verify_color(char *str, char c, int i, int flag);
void			ft_free(char **arr, char *str);
int				limits_verifier(void);
int				verify_number(char **rgb);
int				ft_isdigit_str(char *str);
int				rgb_allocator(char **rgb, char c);
int				texture_allocator(char **all);
int				verify_path(char *str, char c);
int				get_len(char *str, int i);
int				map_error(int err_num);
int				composition_checker(void);
int				check_condition(int j, int i);
int				walled_checker(void);
int				prev_wall(int j, int i);
int				is_space(int j, int i);
int				skip_spaces(char **arr, int j, int i);
int				open_file(char *str);
int				check_file(char *str);
void			free_map_elements(void);
void			rotate_left(double old_dir_x, double old_pla_x);
void			rotate_right(double old_dir_x, double old_pla_x);
int				store_path(char *str, char c, int i);
void			*texture_to_image(t_texture *img, int i);
void			ft_free_int(int	**arr);


#endif
