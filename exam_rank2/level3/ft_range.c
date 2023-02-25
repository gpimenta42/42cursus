/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:34:28 by gpimenta          #+#    #+#             */
/*   Updated: 2023/02/17 20:20:35 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : ft_range
Expected files   : ft_range.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_range(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at start and end at end (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 1, 2 and 3.
- With (-1, 2) you will return an array containing -1, 0, 1 and 2.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing 0, -1, -2 and -3.
*/

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int start, int end)
{
	int *array;
	long int size;
	long int i;

	i = 0;
	size = end - start;
	if (size < 0)
		size *= -1;
	size++;
	array = malloc(sizeof(int) * size);
	if (!array)
		return 0;
	if (start == end)
		array[0] = start;
	if (start < end)
	{
		while (i < size)
		{
			array[i] = start;
			start++;
			i++;
		}
	}
	else if (start > end)
	{
		while (i < size)
		{
			array[i] = start;
			start--;
			i++;

		}
	}
	return (array);
}

int main()
{
	int *array;
	int i;
	int start = -1;
	int end = 2;
	long int size;


	i = 0;
	size = end - start;
	if (size < 0)
		size *= -1;
	size++;
	array = ft_range(start, end);
	while (i < size)
	{
		printf("%d\n", array[i]);
		i++;
	}
}
