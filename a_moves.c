/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 09:45:02 by zvakil            #+#    #+#             */
/*   Updated: 2024/06/09 21:36:06 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stacks *stacks)
{
	int	temp;
	int	i;

	i = 0;
	temp = stacks->a[0];
	while (i < stacks->len_a - 1)
	{
		stacks->a[i] = stacks->a[i + 1];
		i++;
	}
	stacks->a[stacks->len_a - 1] = temp;
	stacks->moves++;
	print_move("ra\n");
}

void	swap_a(t_stacks *stacks)
{
	int	temp;

	temp = stacks->a[0];
	stacks->a[0] = stacks->a[1];
	stacks->a[1] = temp;
	stacks->moves++;
	print_move("sa\n");
}

void	rotate_r_a(t_stacks *stacks)
{
	int	temp;
	int	i;

	i = stacks->len_a - 1;
	temp = stacks->a[stacks->len_a - 1];
	while (i >= 1)
	{
		stacks->a[i] = stacks->a[i - 1];
		i--;
	}
	stacks->a[0] = temp;
	stacks->moves++;
	print_move("rra\n");
}

void	push_a(t_stacks *stacks)
{
	int	*temp_a;
	int	*temp_b;
	int	i;
	int	j;

	i = 0;
	j = 1;
	temp_a = (int *)malloc(sizeof(int) * (stacks->len_a + 1));
	temp_b = (int *)malloc(sizeof(int) * (stacks->len_b - 1));
	temp_a[0] = stacks->b[0];
	while (i < stacks->len_a)
		temp_a[j++] = stacks->a[i++];
	i = 0;
	j = 1;
	while (j < stacks->len_b)
		temp_b[i++] = stacks->b[j++];
	stacks->len_a++;
	stacks->len_b--;
	free(stacks->a);
	free(stacks->b);
	stacks->a = temp_a;
	stacks->b = temp_b;
	stacks->moves++;
	print_move("pa\n");
}
