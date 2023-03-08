/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 15:11:37 by gpimenta          #+#    #+#             */
/*   Updated: 2023/03/08 21:30:51 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_free(char **temp)
{
	int	y;

	y = -1;
	while (temp[++y])
		free(temp[y]);
	free(temp);
}

int	check_collectable_reachable(char **temp)
{
	int	x;
	int	y;

	y = 0;
	while (temp[y])
	{
		x = 0;
		while (temp[y][x])
		{
			if (temp[y][x] == 'C' || temp[y][x] == 'B')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

void	flood_fill(t_vars *vars, int y, int x, char **temp)
{
	if (temp[y][x] == '1' || temp[y][x] == 'P')
		return ;
	else if (temp[y][x] == '0' || temp[y][x] == 'C' || temp[y][x] == 'B')
		temp[y][x] = 'P';
	else if (temp[y][x] == 'E')
	{
		vars->flood.check_e++;
		temp[y][x] = 'P';
	}
	flood_fill(vars, y + 1, x, temp);
	flood_fill(vars, y - 1, x, temp);
	flood_fill(vars, y, x + 1, temp);
	flood_fill(vars, y, x - 1, temp);
}

t_list	new_node(int x, int y)
{
	t_list	new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node.x = x;
	new_node.y = y;
	new_node.next = 0;
	return (new_node);
}

void	add_list(int x, int y, t_list *list)
{
	t_list	*tmp;

	if (!list)
	{
		list = new_node(x, y);
		return ;
	}
	tmp = list;
	else
	{
		while (tmp->next != 0)
			tmp = tmp->next;
		tmp->next = new_node;
	}
}

void	check_enemy(t_vars *vars)
{

	y = -1;
	while (vars->map[++y])
	{
		x = 0;
		while (vars->map[y][x])
		{
			if (vars->map[y][x] == 'B')
				new_node(x, y, vars->list);
			x++;
		}
	}
}

void	check_positions(t_vars *vars)
{
	int	x;
	int	y;

	y = -1;
	vars->move = 0;
	while (vars->map[++y])
	{
		x = 0;
		while (vars->map[y][x])
		{
			if (vars->map[y][x] == 'P')
			{
				vars->x_p = x;
				vars->y_p = y;
			}
			// else if (vars->map[y][x] == 'B')
			// {
			// 	vars->x_e = x;
			// 	vars->y_e = y;
			// }
			x++;
		}
	}
	check_enemy(vars);
}

int	valid_path_checker(t_vars *vars)
{
	char	**temp;
	int		y;

	y = -1;
	vars->flood.check_e = 0;
	temp = malloc(sizeof(char *) * (vars->y_map + 1));
	if (!temp)
		return (0);
	while (vars->map[++y])
		temp[y] = ft_strdup(vars->map[y]);
	temp[y] = 0;
	check_positions(vars);
	flood_fill(vars, vars->y_p + 1, vars->x_p, temp);
	flood_fill(vars, vars->y_p - 1, vars->x_p, temp);
	flood_fill(vars, vars->y_p, vars->x_p + 1, temp);
	flood_fill(vars, vars->y_p, vars->x_p - 1, temp);
	if (vars->flood.check_e == 0 || !check_collectable_reachable(temp))
	{
		ft_free(temp);
		return (0);
	}
	ft_free(temp);
	return (1);
}
