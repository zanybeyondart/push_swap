/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:47:47 by zvakil            #+#    #+#             */
/*   Updated: 2024/01/28 21:08:11 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_stacks *stacks)
{
	int	*temp_a;
	int	*temp_b;
	int	i;
	int	j;

	i = 0;
	j = 1;
	temp_a = (int *)malloc(sizeof(int) * (stacks->len_a - 1));
	temp_b = (int *)malloc(sizeof(int) * (stacks->len_b + 1));
	temp_b[0] = stacks->a[0];
	while (i < stacks->len_b)
		temp_b[j++] = stacks->b[i++];
	i = 0;
	j = 1;
	while (j < stacks->len_a)
		temp_a[i++] = stacks->a[j++];
	stacks->len_a--;
	stacks->len_b++;
	free(stacks->a);
	free(stacks->b);
	stacks->a = temp_a;
	stacks->b = temp_b;
	stacks->moves++;
}

void	swap_b(t_stacks *stacks)
{
	int	temp;

	temp = stacks->b[0];
	stacks->b[0] = stacks->b[1];
	stacks->b[1] = temp;
		stacks->moves++;

}

void	rotate_b(t_stacks *stacks)
{
	int	temp;
	int	i;

	i = 0;
	temp = stacks->b[0];
	while (i < stacks->len_b - 1)
	{
		stacks->b[i] = stacks->b[i + 1];
		i++;
	}
	stacks->b[stacks->len_b - 1] = temp;
		stacks->moves++;

}

void	rotate_r_b(t_stacks *stacks)
{
	int	temp;
	int	i;

	i = stacks->len_b - 1;
	temp = stacks->b[stacks->len_b - 1];
	while (i >= 1)
	{
		stacks->b[i] = stacks->b[i - 1];
		i--;
	}
	stacks->b[0] = temp;
		stacks->moves++;
}

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
}
