/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:41:50 by gpimenta          #+#    #+#             */
/*   Updated: 2023/02/10 14:58:32 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	list_len(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}

void	error_handler(int *pile)
{
	free(pile);
	ft_putstr_fd("Error\n", 2);
	exit (1);
}

int	check_sorted(int *pile, int size, char checker)
{
	int	i;

	i = 0;
	if (checker == 'a')
	{
		while (i < size - 1)
		{
			if (!(pile[i] < pile[i + 1]))
				return (0);
			i++;
		}
	}
	else if (checker == 'b')
	{
		while (i < size - 1)
		{
			if (!(pile[i] > pile[i + 1]))
				return (0);
			i++;
		}
	}
	return (1);
}

int	mediane_of_numbers(int *pivot, int *pile, int size)
{
	int	i;
	int	*new_array;

	i = -1;
	new_array = malloc(sizeof(int) * size);
	if (!new_array)
		return (0);
	while (++i < size)
		new_array[i] = pile[i];
	array_sorter(new_array, size);
	*pivot = new_array[size / 2];
	free(new_array);
	return (1);
}

void	array_sorter(int *array, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] > array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
			j++;
		}
		i++;
	}
}
