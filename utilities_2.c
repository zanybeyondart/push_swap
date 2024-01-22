/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:09:57 by zvakil            #+#    #+#             */
/*   Updated: 2024/01/22 22:55:54 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rr(t_stacks *stacks, t_info *marks)
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
}

int	aligned_b(t_stacks *stacks)
{
	int	i;

	i = 0;
	while (i < stacks->len_b - 1)
	{
		if (stacks->b[i] < stacks->b[i + 1])
			i++;
		else
			return (1);
	}
	return (0);
}

int	secondhalf(t_stacks *stacks, t_info *marks, int number)
{
	if (stacks->a[number] >= marks->b_b_min
		&& stacks->a[number] <= marks->b_t_mid2)
		return (1);
	else
		return (0);
}

int	rr_btr(t_stacks *stacks, t_info *marks)
{
	if (stacks->len_b > 1 && marks->next_b < stacks->b[0]
		&& marks->next_b > stacks->a[stacks->len_a - 1])
		return (1);
	else
		return (0);
}

int	phase_1(t_stacks *stacks, int ac, t_info *marks)
{
	while (no_b_in_a(stacks, marks) && next_b(stacks, marks))
	{
		if (secondhalf(stacks, marks, 0))
		{
			if (stacks->len_b > 2 && !(stacks->a[0] < stacks->b[0]
				&& stacks->a[0] > stacks->b[1]) && !(stacks->a[0] < stacks->b[0]
				&& stacks->a[0] < stacks->b[stacks->len_b - 1])
				&& (stacks->a[0] != marks->b_t_mid2 && stacks->a[0] != marks->b_b_min)
				&& stacks->a[0] < stacks->b[0] && stacks->a[0] > stacks->b[stacks->len_b - 1])
				while (1)
				{
				// printf("Z %d\n %d\n %d\n", stacks->a[0], stacks->b[0], stacks->b[1]);
				rotate_r_b(stacks);
				if (stacks->a[0] > stacks->b[0] && stacks->a[0] < stacks->b[stacks->len_b - 1])
				// if (1)
				break;
				}
			// if ((stacks->len_b > 2 && stacks->a[0] > stacks->b[stacks->len_b - 1]
			// 	&& stacks->a[0] < stacks->b[stacks->len_b - 2])
			// 	|| (stacks->len_b > 2 && stacks->a[0] == marks->b_b_min && stacks->b[stacks->len_b - 1] == marks->b_t_mid2))
			// 	rotate_r_b(stacks);
			push_b(stacks);
			// WITHOUT THIS 9 MOVES
			if ((stacks->len_b > 2 && stacks->b[0] < stacks->b[1]
				&& stacks->b[0] > stacks->b[stacks->len_b -1])
				|| (stacks->len_b == 2 && stacks->b[0] < stacks->b[1]))
				{
				swap_b(stacks);
				// printf("\n\nFRST LOOP\n\n");
				// print_stacks(stacks);
				}
			if (stacks->len_b > 1 && stacks->b[0] < stacks->b[1]
				&& !secondhalf(stacks, marks, 0)
				&& stacks->b[0] < stacks->b[stacks->len_b - 1])
				{
				rr(stacks, marks);
				// printf("\n\nSCND LOOP\n\n");
				// print_stacks(stacks);
				}
			else if (stacks->len_b > 1 && stacks->b[0] < stacks->b[1]
				&& stacks->b[0] < stacks->b[stacks->len_b - 1])
				{
				rotate_b(stacks);
				// printf("\n\nSCND LOOP\n\n");
				// print_stacks(stacks);
				}
			// 	printf("\nPUSH FINAL\n");
		}
		else
		{
			if (stacks->a[0] > stacks->a[1] && !secondhalf(stacks, marks, 1))
			{
			swap_a(stacks);
			}
			if (stacks->len_b > 2 && rr_btr(stacks, marks))
			{
				rr(stacks, marks);
				// print_stacks(stacks);
			}
			else
				rotate_a(stacks);
			// 	printf("\nPUSH FINAL A\n");
			// print_stacks(stacks);
		}
		// printf("stuck\n");
		// print_stacks(stacks);
	}
}
