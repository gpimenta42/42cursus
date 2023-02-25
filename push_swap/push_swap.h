/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:50:41 by gpimenta          #+#    #+#             */
/*   Updated: 2023/02/22 21:30:17 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_piles
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
	int	pivot;
}	t_piles;

int		list_len(char **av);
void	error_handler(int *pile);
int		push_swap_atoi(char *str, int *pile);
void	check_doubles(int *pile, int size);
int		check_sorted(int *pile, int size, char checker);
void	array_sorter(int *array, int size);
int		mediane_of_numbers(int *pivot, int *pile, int size);
void	sort_three_b(t_piles *pile, int size);
int		quicksort_pile_b(t_piles *pile, int size, int count_r, int pushed);
void	sort_three_a(t_piles *pile, int size, int sent, int sent_back);
int		quicksort_pile_a(t_piles *pile, int size, int count_r, int pushed);
void	two_three_case_pile_a(t_piles *pile, int size);
void	sort(t_piles *pile, int size);
void	push_swap(char **av);

/*Instructions*/

void	push_b(t_piles *pile);
void	push_a(t_piles *pile);
void	swap_a(t_piles *pile);
void	swap_b(t_piles *pile);
void	rotate_a(t_piles *pile);
void	rotate_b(t_piles *pile);
void	reverse_rotate_a(t_piles *pile);
void	reverse_rotate_b(t_piles *pile);

#endif