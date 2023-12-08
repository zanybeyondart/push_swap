/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 06:49:04 by zvakil            #+#    #+#             */
/*   Updated: 2023/12/09 02:38:36 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pre_push_b(t_stacks *stacks, int lim)
{
	int	temp;
	int	i;

	if (stacks->len_b <= 1)
		return ;
	while (1)
	{
		align(stacks);
		if (lim > stacks->b[0] && lim < stacks->b[stacks->len_b - 1])
			return ;
		i = 0;
	}
}

int	main(int ac, char **av)
{
	int			i;
	t_info		marks;
	t_stacks	*stacks;

	stacks = malloc(sizeof(t_stacks));
	stacks->len_a = ac - 1;
	stacks->len_b = 0;
	stacks->a = (int *)malloc(sizeof(int) * stacks->len_a);
	stacks->b = NULL;
	fill(stacks, av);
	marks.b_b_min = smallest_number(av);
	marks.a_b_max = largest_number(av);
	marks.b_t_mid2 = mid_number_b(marks.b_b_min, marks.a_b_max, av, ac);
	marks.a_t_mid = mid_number_a(marks.b_t_mid2, marks.a_b_max, av);
	while (aligned(stacks->a, ac))
	{
		print_stacks(stacks);
		if (stacks->a[0] >= marks.b_b_min && stacks->a[0] <= marks.b_t_mid2)
		{
			pre_push_b(stacks, stacks->a[0]);
			push_b(stacks);
		}
	}
	free(stacks->a);
	free(stacks->b);
	free(stacks);
	return (0);
}
