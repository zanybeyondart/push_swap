/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 06:49:04 by zvakil            #+#    #+#             */
/*   Updated: 2024/01/22 22:51:51 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	no_b_in_a(t_stacks *stacks, t_info *marks)
{
	int	i;

	i = 0;
	while (i < stacks->len_a)
	{
		if (stacks->a[i] >= marks->b_b_min && stacks->a[i] <= marks->b_t_mid2)
			return (1);
		i++;
	}
	return (0);
}

void	pre_push_b(t_stacks *stacks, int lim, t_info *marks)
{
	int					temp;
	int					i;

	if (stacks->len_b <= 1)
		return ;
	set_high_low(stacks);
	while (1)
	{
		if (lim < stacks->b_low || lim > stacks->b_high)
		{
			lowest_on_bot(stacks);
			return ;
		}
		if (lim > stacks->b[0] && lim < stacks->b[stacks->len_b - 1])
			return ;
		rotate_b(stacks);
		print_stacks(stacks);
	}
}

int cool(t_stacks *stacks)
{
	int i = 0;
	while (i < stacks->len_a - 1)
	{
		if (stacks->a[i] > stacks->a[i + 1])
			return (0);
		else
			i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_info		*marks;
	t_stacks	*stacks;

	stacks = malloc(sizeof(t_stacks));
	marks = malloc(sizeof(t_info));
	stacks->moves = 0;
	setter(stacks, marks, ac, av);
	phase_1(stacks, ac, marks);
	lowest_on_bot(stacks);
	phase_2(stacks, ac, marks);
	while (stacks->len_b != 0)
		push_a(stacks);
	print_stacks(stacks);
	if (cool(stacks))
		printf("\nGG\n");
	else
	{
		print_stacks(stacks);
		printf("\nNAH\n");
	}
	printf("\n\n %d || %d\n\n", stacks->len_a, stacks->moves);
	free(stacks->a);
	free(stacks->b);
	free(stacks);

	return (0);
}
