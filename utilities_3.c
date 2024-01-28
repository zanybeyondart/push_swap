/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 07:28:46 by zvakil            #+#    #+#             */
/*   Updated: 2024/01/27 23:14:37 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	should_be(t_stacks *stacks)
{
	// if ()
	if (stacks->len_b < 3)
		return (0);
	set_high_low(stacks);
	// printf("%d	%d	%d %d %d\n", stacks->a[0], stacks->b[0], stacks->b[stacks->len_b - 1], stacks->b_low, stacks->b_high);
	if (stacks->a[0] > stacks->b[0] && stacks->a[0] < stacks->b[stacks->len_b - 1])
		return (0);
	if (stacks->a[0] < stacks->b[0] && stacks->a[0] > stacks->b[1])
		return (0);
	if (stacks->a[0] < stacks->b[0] 
		&& stacks->a[0] < stacks->b[stacks->len_b - 1]
		&& stacks->a[0] < stacks->b_low)
		{
		lowest_on_bot(stacks);
		return (0);
		}
	if (stacks->a[0] > stacks->b[0]
		&& stacks->a[0] > stacks->b[stacks->len_b - 1]
		&& stacks->a[0] > stacks->b_high)
		{
		lowest_on_bot(stacks);
		return (0);
		}
	// if ((stacks->b[0] == stacks->b_high
	// 	&& stacks->b[stacks->len_b - 1] == stacks->b_low) 
	// 	|| (stacks->b[0] == stacks->b_low
	// 	&& stacks->b[stacks->len_b - 1] == stacks->b_high))
	// 	{
	// 		// printf("GOES\n");
	// 	return (1);
	// 	}
	return (1);
}

int	next_b(t_stacks *stacks, t_info *marks)
{
	int	i;

	i = 0;
	while (i < stacks->len_a)
	{
		if (secondhalf(stacks, marks, i))
		{
			marks->next_b = stacks->a[i];
			break ;
		}
		i++;
	}
	return (1);
}

void	highest_on_bot(t_stacks *stacks)
{
	int	highest;
	int	high_index;
	int	i;

	i = 0;
	high_index = 0;
	highest = stacks->a[0];
	while (i < stacks->len_a)
	{
		if (stacks->a[i] > highest)
		{
			highest = stacks->a[i];
			high_index = i;
		}
		i++;
	}
	if (high_index < (stacks->len_a / 2))
		while (stacks->a[stacks->len_a - 1] != highest)
			rotate_a(stacks);
	else
		while (stacks->a[stacks->len_a - 1] != highest)
			rotate_r_a(stacks);
}

int	phase_2(t_stacks *stacks, int ac, t_info *marks)
{
	int	i;

	i = 0;
	// highest_on_bot(stacks);
			// print_stacks(stacks);

	while (aligned(stacks, ac))
	{
		// print_stacks(stacks);
		if (stacks->a[0] > stacks->a[1])
		{
			swap_a(stacks);
		}
		else if (stacks->a[stacks->len_a - 1] > stacks->a[0] 
			&& stacks->a[stacks->len_a -1] < stacks->a[1])
			{
						// print_stacks(stacks);
				rotate_r_a(stacks);
						// print_stacks(stacks);
				swap_a(stacks);
						// print_stacks(stacks);
			}
		else
			rotate_a(stacks);
	}
	 highest_on_bot(stacks);
}
