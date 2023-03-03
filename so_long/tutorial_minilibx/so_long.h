/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:50:27 by gpimenta          #+#    #+#             */
/*   Updated: 2023/03/03 17:28:17 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/*mlx_init*/
# include "minilibx-linux/mlx.h"
/*malloc*/
# include <stdlib.h>
/*read*/
# include <unistd.h>
/*open*/
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
/*coded ft_printf and libft*/
# include "libft/libft.h"
# include <stdio.h>

# define SPRITE_SIZE 50

typedef struct s_flood
{
	int	check_c;
	int	check_e;
}	t_flood;

// typedef struct s_win
// {
// 	void	*mlx_ptr;
// 	void	*win_ptr;
// 	int		y;
// 	int		x;
// }	t_win;

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		x;
	int		y;
	int		bpp;
	int		endian;
	int		line_len;
	char	*pixel_ptr;
}	t_img;

typedef struct s_vars
{
	char	**map;
	int		y_map;
	int		x_map;
	int		x_p;
	int		y_p;
	int		p_counter;
	int		e_counter;
	int		c_counter;
	t_flood	flood;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*w_ptr;
	char	*w_address;
	int		bpp;
	int		line_len;
	int		endian;
	t_img	p_init;
	t_img	wall;
	t_img	floor;
	t_img	collect;
	t_img	exit;
}	t_vars;

#endif
