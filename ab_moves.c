/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ab_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 06:32:11 by zvakil            #+#    #+#             */
/*   Updated: 2024/04/01 07:47:58 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stacks *stacks)
{
	int	temp_b;
	int	temp;

	temp = stacks->a[0];
	stacks->a[0] = stacks->a[1];
	stacks->a[1] = temp;
	temp_b = stacks->b[0];
	stacks->b[0] = stacks->b[1];
	stacks->b[1] = temp_b;
	stacks->moves++;
	print_move("ss\n");
}

void	rrr(t_stacks *stacks)
{
	int	temp;
	int	i;
	int	temp_b;
	int	i_b;

	i = stacks->len_a - 1;
	temp = stacks->a[stacks->len_a - 1];
	while (i >= 1)
	{
		stacks->a[i] = stacks->a[i - 1];
		i--;
	}
	stacks->a[0] = temp;
		stacks->moves++;
	i_b = stacks->len_b - 1;
	temp_b = stacks->b[stacks->len_b - 1];
	while (i_b >= 1)
	{
		stacks->b[i_b] = stacks->b[i_b - 1];
		i_b--;
	}
	stacks->b[0] = temp_b;
		stacks->moves++;
	print_move("rrr\n");
}

int	rr(t_stacks *stacks)
{
	int	temp_b;
	int	i_b;
	int	temp;
	int	i;

	i_b = 0;
	temp_b = stacks->b[0];
	i = 0;
	temp = stacks->a[0];
	while (i_b < stacks->len_b - 1)
	{
		stacks->b[i_b] = stacks->b[i_b + 1];
		i_b++;
	}
	while (i < stacks->len_a - 1)
	{
		stacks->a[i] = stacks->a[i + 1];
		i++;
	}
	stacks->b[stacks->len_b - 1] = temp_b;
	stacks->a[stacks->len_a - 1] = temp;
	stacks->moves++;
	print_move("rr\n");
	return (0);
}
