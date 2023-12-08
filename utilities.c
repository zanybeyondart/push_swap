/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:09:57 by zvakil            #+#    #+#             */
/*   Updated: 2023/12/08 16:29:17 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill(t_stacks *stack, char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (j != stack->len_a)
		stack->a[j++] = atoi(av[i++]);
}

int	aligned(int *a, int ac)
{
	int	i;

	i = 0;
	while (i < ac - 2)
	{
		if (a[i] < a[i + 1])
			i++;
		else
			return (1);
	}
	return (0);
}

void	print_stacks(t_stacks *stacks)
{
	int i = 0;
	int j = 0;
	printf("\nA	B\n");
	while(i < stacks->len_a)
	{
		printf("%d	", stacks->a[i++]);
		if(j < stacks->len_b)
			printf("%d	\n", stacks->b[j++]);
		else
			printf("X\n");
	}
}
