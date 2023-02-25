/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:01:30 by gpimenta          #+#    #+#             */
/*   Updated: 2023/02/22 18:52:06 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	main(int ac, char **av)
{
	char	**tab;
	int		i;

	i = 0;
	if (ac > 1)
	{
		av++;
		if (ac == 2)
		{
			tab = ft_split(*av, ' ');
			push_swap(tab);
			while (tab[i])
			{
				free(tab[i]);
				i++;
			}
			free(tab);
		}
		else
			push_swap(av);
	}
	return (0);
}

void	push_swap(char **av)
{
	t_piles	pile;
	int		size;
	int		i;

	size = list_len(av);
	pile.size_a = size;
	pile.size_b = 0;
	pile.a = malloc(sizeof(int) * size);
	if (!pile.a)
		return ;
	pile.b = malloc(sizeof(int) * size);
	if (!pile.b)
	{
		free(pile.a);
		return ;
	}
	i = -1;
	while (++i < size)
		pile.a[i] = push_swap_atoi(av[i], pile.a);
	check_doubles(pile.a, size);
	sort(&pile, size);
	free(pile.a);
	free(pile.b);
}

int	push_swap_atoi(char *str, int *pile)
{
	int				i;
	unsigned int	number;
	int				sign;

	i = 0;
	number = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			sign = -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			error_handler(pile);
		number = (str[i] - 48) + (number * 10);
		i++;
	}
	if ((number > 2147483647 && sign) || (number > 2147483648 && sign == -1))
		error_handler(pile);
	return (number * sign);
}

void	check_doubles(int *pile, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (pile[i] == pile[j])
				error_handler(pile);
			j++;
		}
		i++;
	}
}

void	sort(t_piles *pile, int size)
{
	if (!check_sorted(pile->a, pile->size_a, 'a'))
	{
		if (size == 2 || size == 3)
			two_three_case_pile_a(pile, size);
		else
			quicksort_pile_a(pile, size, 0, 0);
	}
	return ;
}
