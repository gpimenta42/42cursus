/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:00:02 by gpimenta          #+#    #+#             */
/*   Updated: 2023/02/10 14:58:17 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	rotate_a(t_piles *pile)
{
	int	temp;
	int	i;

	temp = pile->a[0];
	i = 0;
	while (i < pile->size_a - 1)
	{
		pile->a[i] = pile->a[i + 1];
		i++;
	}
	pile->a[i] = temp;
	ft_printf("ra\n");
}

void	rotate_b(t_piles *pile)
{
	int	temp;
	int	i;

	temp = pile->b[0];
	i = 0;
	while (i < pile->size_b - 1)
	{
		pile->b[i] = pile->b[i + 1];
		i++;
	}
	pile->b[i] = temp;
	ft_printf("rb\n");
}

void	reverse_rotate_a(t_piles *pile)
{
	int	temp;
	int	i;

	i = pile->size_a - 1;
	temp = pile->a[i];
	while (i)
	{
		pile->a[i] = pile->a[i - 1];
		i--;
	}
	pile->a[0] = temp;
	ft_printf("rra\n");
}

void	reverse_rotate_b(t_piles *pile)
{
	int	temp;
	int	i;

	i = pile->size_b - 1;
	temp = pile->b[i];
	while (i)
	{
		pile->b[i] = pile->b[i - 1];
		i--;
	}
	pile->b[0] = temp;
	ft_printf("rrb\n");
}
