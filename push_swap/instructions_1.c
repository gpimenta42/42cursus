/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 16:57:34 by gpimenta          #+#    #+#             */
/*   Updated: 2023/02/10 15:09:53 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	push_b(t_piles *pile)
{
	int	i;

	if (pile->size_a)
	{
		pile->size_b++;
		i = pile->size_b - 1;
		while (i > 0)
		{
			pile->b[i] = pile->b[i - 1];
			i--;
		}
		pile->b[0] = pile->a[0];
		pile->size_a--;
		i = -1;
		while (++i < pile->size_a)
			pile->a[i] = pile->a[i + 1];
		ft_printf("pb\n");
	}
	else
		return ;
}

void	push_a(t_piles *pile)
{
	int	i;

	if (pile->size_b)
	{
		pile->size_a++;
		i = pile->size_a - 1;
		while (i > 0)
		{
			pile->a[i] = pile->a[i - 1];
			i--;
		}
		pile->a[0] = pile->b[0];
		pile->size_b--;
		i = -1;
		while (++i < pile->size_b)
			pile->b[i] = pile->b[i + 1];
		ft_printf("pa\n");
	}
	else
		return ;
}

void	swap_a(t_piles *pile)
{
	int	temp;

	temp = pile->a[0];
	pile->a[0] = pile->a[1];
	pile->a[1] = temp;
	ft_printf("sa\n");
}

void	swap_b(t_piles *pile)
{
	int	temp;

	temp = pile->b[0];
	pile->b[0] = pile->b[1];
	pile->b[1] = temp;
	ft_printf("sb\n");
}
