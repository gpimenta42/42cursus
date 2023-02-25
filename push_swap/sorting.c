/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:43:08 by gpimenta          #+#    #+#             */
/*   Updated: 2023/02/22 21:30:44 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	two_three_case_pile_a(t_piles *pile, int size)
{
	if (size == 2)
		swap_a(pile);
	else if (pile->a[0] > pile->a[1] && pile->a[0] > pile->a[2])
	{
		if (pile->a[1] < pile->a[2])
			rotate_a(pile);
		else if (pile->a[1] > pile->a[2])
		{
			swap_a(pile);
			reverse_rotate_a(pile);
		}
	}
	else if (pile->a[1] > pile->a[0] && pile->a[1] > pile->a[2])
	{
		if (pile->a[0] > pile->a[2])
			reverse_rotate_a(pile);
		else if (pile->a[0] < pile->a[2])
		{
			swap_a(pile);
			rotate_a(pile);
		}
	}
	else if (pile->a[0] > pile->a[1] && pile->a[2] > (pile->a[0] && pile->a[1]))
		swap_a(pile);
}

int	quicksort_pile_a(t_piles *pile, int size, int count_r, int pushed)
{
	if (check_sorted(pile->a, size, 'a'))
		return (1);
	if (size <= 3)
	{
		sort_three_a(pile, size, 0, 0);
		return (1);
	}
	if (!mediane_of_numbers(&pile->pivot, pile->a, size))
		return (0);
	while (pushed < size / 2)
	{
		if (pile->a[0] < pile->pivot && ++pushed)
			push_b(pile);
		else if (pile->a[pile->size_a - 1] < pile->pivot && ++pushed)
		{
			reverse_rotate_a(pile);
			push_b(pile);
		}
		else if (++count_r)
			rotate_a(pile);
	}
	while (count_r-- && size < pile->size_a)
		reverse_rotate_a(pile);
	return (quicksort_pile_a(pile, size - pushed, 0, 0)
		&& quicksort_pile_b(pile, pushed, 0, 0));
}

/* sort_three_a is for the case that in stack of 3
the highest number being at position [0] or [1] instead of [2]
like ex: 7 8 6 or 6 4 5
*/

void	sort_three_a(t_piles *pile, int size, int sent, int sent_back)
{
	if (size == 2 && pile->a[0] > pile->a[1])
		swap_a(pile);
	if (size == 3)
	{
		if (pile->a[0] > (pile->a[1] && pile->a[2])
			|| pile->a[1] > (pile->a[0] && pile->a[2]))
		{
			while (!sent_back || !check_sorted(pile->a, size, 'a'))
			{
				if (pile->a[0] > pile->a[1])
					swap_a(pile);
				else if (sent == 0)
				{
					rotate_a(pile);
					sent = 1;
				}
				else if (++sent_back)
					reverse_rotate_a(pile);
			}
		}
		else if (pile->a[2] > (pile->a[0] && pile->a[1])
			&& pile->a[0] > pile->a[1])
			swap_a(pile);
	}
}

int	quicksort_pile_b(t_piles *pile, int size, int count_r, int pushed)
{
	if (check_sorted(pile->b, size, 'b'))
		while (size--)
			push_a(pile);
	if (size <= 3)
	{
		sort_three_b(pile, size);
		return (1);
	}
	if (!mediane_of_numbers(&pile->pivot, pile->b, size))
		return (0);
	while (pushed + 1 <= size / 2 + size % 2)
	{
		if (pile->b[0] >= pile->pivot && ++pushed)
			push_a(pile);
		else if (++count_r)
			rotate_b(pile);
	}
	while (count_r-- && size - pushed != pile->size_b)
		reverse_rotate_b(pile);
	return (quicksort_pile_a(pile, pushed, 0, 0)
		&& quicksort_pile_b(pile, size - pushed, 0, 0));
}

/* sort_three_b is for the case that the highest number of 3 in stack B,
(the one that should be at the top of stack B to push_a),
is at the bottom of the upper 3 in stack B, at position stack_b[2].
ex: 7 6 8
*/

void	sort_three_b(t_piles *pile, int size)
{
	if (size == 1)
		push_a(pile);
	else if (size == 2)
	{
		if (pile->b[0] < pile->b[1])
			swap_b(pile);
		while (size--)
			push_a(pile);
	}
	else if (size == 3)
	{
		while (size)
		{
			if ((size == 3 || size == 2) && pile->b[0] < pile->b[1])
				swap_b(pile);
			else if (size == 1 && pile->a[0] > pile->a[1])
				swap_a(pile);
			else
			{
				push_a(pile);
				size--;
			}
		}
	}
}
