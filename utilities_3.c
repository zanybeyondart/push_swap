/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 07:28:46 by zvakil            #+#    #+#             */
/*   Updated: 2024/01/21 04:47:20 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
