/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 07:28:46 by zvakil            #+#    #+#             */
/*   Updated: 2024/06/10 01:57:16 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*cal_moves(t_stacks *stacks, int i)
{
	int	*moves;

	moves = malloc(sizeof(int) * 2);
	moves[0] = 0;
	moves[1] = 0;
	set_high_low(stacks);
	set_moves(stacks, i, moves, 0);
	if (i <= stacks->len_a / 2)
		moves[0] = i;
	else
		moves[0] = i - stacks->len_a;
	return (moves);
}

void	set_moves(t_stacks *stacks, int i, int *moves, int j)
{
	int	index_b;

	index_b = 0;
	while (index_b < stacks->len_b - 1)
	{
		if (stacks->a[i] < stacks->b[index_b]
			&& stacks->a[i] > stacks->b[index_b + 1])
			if (index_b + 1 <= stacks->len_b / 2)
				moves[1] = index_b + 1;
		else
			moves[1] = (index_b + 1) - stacks->len_b;
		else if (stacks->a[i] > stacks->b_high || stacks->a[i] < stacks->b_low)
		{
			while (stacks->b[j] != stacks->b_high && j < stacks->len_b)
				j++;
			if (j <= stacks->len_b / 2)
				moves[1] = j ;
			else
				moves[1] = j - stacks->len_b;
		}
		if (moves[1] != 0)
			break ;
		index_b++;
	}
}

int	ischeaper(int *current, int *cheapest, int t_cheap, int t_cur)
{
	if ((cheapest[0] < 0 && cheapest[1] < 0)
		|| (cheapest[0] > 0 && cheapest[1] > 0))
	{
		if (posit(cheapest[0]) >= posit(cheapest[1]))
			t_cheap = posit(cheapest[0]);
		else
			t_cheap = posit(cheapest[1]);
	}
	else
		t_cheap = posit(cheapest[0]) + posit(cheapest[1]);
	if ((current[0] < 0 && current[1] < 0)
		|| (current[0] > 0 && current[1] > 0))
	{
		if (posit(current[0]) >= posit(current[1]))
			t_cur = posit(current[0]);
		else
			t_cur = posit(current[1]);
	}
	else
		t_cur = posit(current[0]) + posit(current[1]);
	if (t_cur < t_cheap)
		return (1);
	else
		return (0);
}

void	ab_moves(t_stacks *stacks, int *cheapest)
{
	while (cheapest[0] > 0 && cheapest[1] > 0)
	{
		if (cheapest[0] == 0 || cheapest[1] == 0)
			break ;
		rr(stacks);
		cheapest[0]--;
		cheapest[1]--;
	}
	while (cheapest[0] < 0 && cheapest[1] < 0)
	{
		if (cheapest[0] == 0 || cheapest[1] == 0)
			break ;
		rrr(stacks);
		cheapest[0]++;
		cheapest[1]++;
	}
}

void	cheapestmove(t_stacks *stacks, int *cheapest)
{
	ab_moves(stacks, cheapest);
	while (cheapest[0] != 0 || cheapest[1] != 0)
	{
		if (cheapest[0] < 0)
		{
			rotate_r_a(stacks);
			cheapest[0]++;
		}
		else if (cheapest[0] > 0)
		{
			cheapest[0]--;
			rotate_a(stacks);
		}
		if (cheapest[1] < 0)
		{
			rotate_r_b(stacks);
			cheapest[1]++;
		}
		else if (cheapest[1] > 0)
		{
			cheapest[1]--;
			rotate_b(stacks);
		}
	}
}
