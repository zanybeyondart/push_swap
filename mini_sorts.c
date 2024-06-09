/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sorts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 18:25:30 by zvakil            #+#    #+#             */
/*   Updated: 2024/06/10 02:14:21 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stacks *stacks)
{
	if (stacks->a[0] > stacks->a[1] && stacks->a[1] < stacks->a[2]
		&& stacks->a[0] < stacks->a[2])
		swap_a(stacks);
	else if (stacks->a[0] > stacks->a[1] && stacks->a[1] > stacks->a[2])
	{
		swap_a(stacks);
		rotate_r_a(stacks);
	}
	else if (stacks->a[0] > stacks->a[1] && stacks->a[1] < stacks->a[2])
		rotate_a(stacks);
	else if (stacks->a[0] < stacks->a[1] && stacks->a[1] > stacks->a[2])
	{
		if (stacks->a[0] < stacks->a[2])
		{
			swap_a(stacks);
			rotate_a(stacks);
		}
		else
			rotate_r_a(stacks);
	}
}

void	sort_four(t_stacks *stacks)
{
	int	i;
	int	low_index;
	int	low;

	i = 0;
	low = stacks->a[0];
	low_index = 0;
	while (i < stacks->len_a)
	{
		if (stacks->a[i] < low)
		{
			low = stacks->a[i];
			low_index = i;
		}
		i++;
	}
	if (low_index == 3)
		rotate_r_a(stacks);
	else
		while (low_index--)
			rotate_a(stacks);
	push_b(stacks);
	sort_three(stacks);
	push_a(stacks);
}

void	sort_five(t_stacks *stacks)
{
	int	i;
	int	low_index;
	int	low;

	i = 0;
	low = stacks->a[0];
	low_index = 0;
	while (i < stacks->len_a)
	{
		if (stacks->a[i] < low)
		{
			low = stacks->a[i];
			low_index = i;
		}
		i++;
	}
	if (low_index <= 2)
		while (low_index--)
			rotate_a(stacks);
	else
		while (low_index++ < stacks->len_a)
			rotate_r_a(stacks);
	push_b(stacks);
	sort_four(stacks);
	push_a(stacks);
}

void	mini_sort(t_stacks *stacks)
{
	if (stacks->len_a == 3)
		sort_three(stacks);
	else if (stacks->len_a == 4)
		sort_four(stacks);
	else if (stacks->len_a == 5)
		sort_five(stacks);
}
