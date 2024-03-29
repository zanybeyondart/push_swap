/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:09:57 by zvakil            #+#    #+#             */
/*   Updated: 2024/02/22 08:09:25 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//  Initiate Stack A
void	fill(t_stacks *stack, char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (j != stack->len_a)
		stack->a[j++] = atoi(av[i++]);
}

// Checks if stack A is aligned
int	aligned(t_stacks *stacks, int ac)
{
	int	i;

	i = 0;
	while (i < stacks->len_a - 1)
	{
		if (stacks->a[i] < stacks->a[i + 1])
			i++;
		else
			break ;
	}
	i++;
	if (i == stacks->len_a - 1 && stacks->a[i] > stacks->a[0])
		return (1);
	while (i < stacks->len_a - 1)
	{
		if (stacks->a[i] < stacks->a[i + 1])
			i++;
		else
			return (1);
		if (i == stacks->len_a - 1
			&& stacks->a[i] > stacks->a[0])
			return (1);
	}
	return (0);
}

void	print_stacks(t_stacks *stacks)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	// return ;
	printf("\nA	B\n");
	while (1)
	{
		if (i < stacks->len_a)
			printf("%d	", stacks->a[i++]);
		else
			printf("X	");
		if (j < stacks->len_b)
			printf("%d	\n", stacks->b[j++]);
		else
			printf("X\n");
		if (i >= stacks->len_a && j >= stacks->len_b)
			break ;
	}
}

void	set_high_low(t_stacks *stacks)
{
	int	i;

	i = 0;
	stacks->b_high = stacks->b[i];
	stacks->b_low = stacks->b[i];
	while (i < stacks->len_b)
	{
		if (stacks->b[i] > stacks->b_high)
			stacks->b_high = stacks->b[i];
		if (stacks->b[i] < stacks->b_low)
			stacks->b_low = stacks->b[i];
		i++;
	}
}	

void	lowest_on_bot(t_stacks *stacks)
{
	int	highest;
	int	high_index;
	int	i;

	i = 0;
	high_index = 0;
	highest = stacks->b[0];
	while (i < stacks->len_b)
	{
		if (stacks->b[i] > highest)
		{
			highest = stacks->b[i];
			high_index = i;
		}
		i++;
	}
	if (high_index <= (stacks->len_b / 2))
		while (stacks->b[0] != highest)
			rotate_b(stacks);
	else
		while (stacks->b[0] != highest)
			rotate_r_b(stacks);
}

void	set_high_low_a(t_stacks *stacks)
{
	int	i;

	i = 0;
	stacks->a_high = stacks->a[i];
	stacks->a_low = stacks->a[i];
	while (i < stacks->len_a)
	{
		if (stacks->a[i] > stacks->a_high)
			stacks->a_high = stacks->a[i];
		if (stacks->a[i] < stacks->a_low)
			stacks->a_low = stacks->a[i];
		i++;
	}
}