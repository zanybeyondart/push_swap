/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:47:47 by zvakil            #+#    #+#             */
/*   Updated: 2023/12/08 21:42:06 by zvakil           ###   ########.fr       */
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
	temp_b[0] = 1;
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
}
