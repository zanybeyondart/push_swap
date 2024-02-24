/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 07:28:46 by zvakil            #+#    #+#             */
/*   Updated: 2024/02/21 09:55:13 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_efficient(t_stacks *stacks)
{
	int	i;
	int	pos;

	pos = 0;
	i = 0;

	while (i < stacks->len_b)
	{
		if (stacks->len_b > 2
			&& (stacks->a[0] < stacks->b[i] && stacks->a[0] > stacks->b[i + 1]))
			return (i);
		i++;
	}
	return (0);
}

int	p2conds(t_stacks *stacks, t_info *marks, int cond)
{
	if (cond == 1)
	{
		if ((stacks->b[0] > stacks->a[stacks->len_a - 1]
				&& stacks->b[0] < stacks->a[0])
			|| stacks->b[0] == marks->a_b_max
			|| (stacks->b[0] < stacks->a[0]
				&& stacks->a[stacks->len_a - 1] == stacks->a_high))
			return (1);
	}
	if (cond == 2)
	{
		if (stacks->b[0] > stacks->a[0] && stacks->b[0] < stacks->a[1])
			return (1);
	}
	return (0);
}

int	rotate_efficient_p2(t_stacks *stacks, t_info *marks)
{
	int	i;

	i = 0;

	while (i < stacks->len_a - 1)
	{
		if ((stacks->b[0] > stacks->a[i] && stacks->b[0] < stacks->a[i + 1])
			|| (stacks->a[i] == stacks->a_high && stacks->b[0] < stacks->a[i + 1]))
		{
			return (i);
		}
		i++;
	}
	return (0);
}

int	should_be(t_stacks *stacks)
{
	if (stacks->len_b < 3)
		return (0);
	set_high_low(stacks);
	if (stacks->a[0] > stacks->b[0]
		&& stacks->a[0] < stacks->b[stacks->len_b - 1])
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
	while (aligned(stacks, ac))
	{
		if (stacks->a[0] > stacks->a[1])
		{
			swap_a(stacks);
		}
		else if (stacks->a[stacks->len_a - 1] > stacks->a[0]
			&& stacks->a[stacks->len_a - 1] < stacks->a[1])
		{
			rotate_r_a(stacks);
			swap_a(stacks);
		}
		else if (stacks->a[0] > stacks->b[0])
		{
			push_b(stacks);
		}
		else if (stacks->a[0] < stacks->b[0])
		{
			push_b(stacks);
			swap_b(stacks);
		}
		else
		{
			rotate_a(stacks);
		}
	}
	highest_on_bot(stacks);
	while (stacks->b[0] != marks->b_t_mid2)
	{
		set_high_low_a(stacks);
		if (p2conds(stacks, marks, 1))
		{
			push_a(stacks);
		}
		else if (p2conds(stacks, marks, 2))
		{
			push_a(stacks);
			swap_a(stacks);
		}
		else
		{
			// printf("\n\n%d\n\n", rotate_efficient_p2(stacks, marks));
			if (rotate_efficient_p2(stacks, marks) <= stacks->len_a / 2)
			{
				while (1)
				{
					// print_stacks(stacks);
					rotate_a(stacks);
					// printf("\n%d R\n", stacks->len_a);
					// print_stacks(stacks);
					if (p2conds(stacks, marks, 1) || p2conds(stacks, marks, 2))
					{
						break ;
					}
				}
			}
			else
			{
				while (1)
				{
					// printf("\n%d RR\n", stacks->len_a);
					rotate_r_a(stacks);
					// print_stacks(stacks);
					if (p2conds(stacks, marks, 1) || p2conds(stacks, marks, 2))
						break ;
				}
			}
		}
		if (stacks->b[0] == marks->a_t_mid && stacks->b[1] == marks->b_t_mid2)
			break ;
	}
		// print_stacks(stacks);
		highest_on_bot (stacks);
	return (0);
}