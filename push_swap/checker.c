/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 20:21:41 by gpimenta          #+#    #+#             */
/*   Updated: 2023/02/10 15:25:02 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	list_len(char **av)
{
	int i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}

void	instruction_sorter(t_piles *pile, char *str)
{
	if (!ft_strcmp(str, "pa\n"))
		push_a(pile, 1);
}

void	stdin_reader(t_piles *pile)
{
	char *str;

	str = get_next_line(0);
	while (str)
	{
		instruction_sorter(pile, str);
		free(str);
		get_next_line(0);
	}

}

void	args_reader(char **args)
{
	t_piles pile;
	int size;

	size = arg_len;
	pile.a = malloc(sizeof(int) * size);
	if (!pile.a)
		return ;
	pile.size_a = size;
	pile.b = malloc(sizeof(int) * size);
	if (!pile.b)
	{
		free (pile.a);
		return ;
	}
	pile.size_b = 0;
	stdin_reader(&pile);
}

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		av++;
		if (ac == 2)
			av = ft_split(*av, " ");
		args_reader(av);
	}
}
