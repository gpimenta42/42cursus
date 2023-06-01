/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:47:22 by gpimenta          #+#    #+#             */
/*   Updated: 2023/05/28 14:53:09 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	skip_spaces(char **arr, int j, int i)
{
	while (arr[j][i] && (arr[j][i] == 32 || (arr[j][i] == 9)))
		i++;
	return (i);
}

int	is_space(int j, int i)
{
	if (cub()->map[j][i] == 32 || cub()->map[j][i] == 9)
		return (1);
	return (0);
}

int	prev_wall(int j, int i)
{
	while (i >= 0 && (cub()->map[j][i] == 32
		|| cub()->map[j][i] == 9 || cub()->map[j][i] == 10))
		i--;
	return (i);
}

int	map_error(int err_num)
{
	if (err_num == 1)
		printf("Error\nInvalid line while parsing scene file\n");
	else if (err_num == 2)
		printf("Error\nEmpty or invalid map contents\n");
	else if (err_num == 3)
		printf("Error\nMap isn't surrounded by walls\n");
	else if (err_num == 4)
		printf("Error\nInvalid map composition\n");
	else if (err_num == 5)
		printf("Error\nInvalid or missing color information\n");
	else if (err_num == 6)
	{
		mlx_destroy_display(cub()->mlx);
		free(cub()->mlx);
		printf("Error\nInvalid or missing texture information\n");
	}
	else if (err_num == 7)
		printf("Error\nInvalid or missing texture information\n");
	free_map_elements();
	return (0);
}

int	get_len(char *str, int i)
{
	int	j;

	j = 0;
	while (str[i] && str[i] != 32 && str[i] != 9 && str[i] != 10)
	{
		i++;
		j++;
	}
	return (j);
}
