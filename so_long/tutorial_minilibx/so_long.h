/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:50:27 by gpimenta          #+#    #+#             */
/*   Updated: 2023/02/28 20:18:44 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/*mlx_init*/
// include <mlx.h>
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

typedef struct s_flood
{
	int	check_c;
	int	check_e;
}	t_flood;

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
}	t_vars;

#endif
