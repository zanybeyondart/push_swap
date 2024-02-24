/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:09:57 by zvakil            #+#    #+#             */
/*   Updated: 2024/02/23 09:03:49 by zvakil           ###   ########.fr       */
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
	printf("\nROATE A AND B\n");
	print_stacks(stacks);
	return (0);
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
		printf("\n%d to %d", marks->b_t_mid2, marks->b_b_min);

			// print_stacks(stacks);
			if (should_be(stacks))
			{
				if (rotate_efficient(stacks) <= stacks->len_b / 2)
				{
					while (1)
					{
						rotate_b(stacks);
						// printf("\n%d R\n", stacks->len_b);
						if (stacks->a[0] > stacks->b[0]
							&& stacks->a[0] < stacks->b[stacks->len_b - 1])
								break ;
					}
				}
				else
				{
					while (1)
					{
						rotate_r_b(stacks);
						// printf("\n%d RR\n", stacks->len_b);
						if (stacks->a[0] > stacks->b[0]
							&& stacks->a[0] < stacks->b[stacks->len_b - 1])
								break ;
					}
				}
			}
			push_b(stacks);
			if (stacks->len_b > 2 && stacks->b[0] < stacks->b[1]
				&& !secondhalf(stacks, marks, 0)
				&& stacks->b[0] < stacks->b[stacks->len_b - 1]
				&& stacks->b[0] < stacks->b[2])
				{
				rr(stacks, marks);
				}
			else if ((stacks->len_b > 2 && stacks->b[0] < stacks->b[1]
				&& stacks->b[0] < stacks->b[stacks->len_b - 1])
				&& stacks->b[0] < stacks->b[2])
				rotate_b(stacks);
			if ((stacks->len_b > 1 && stacks->b[0] < stacks->b[1]))
				{
				// if (!secondhalf(stacks, marks, 0) && stacks->a[0] > stacks->a[1])
				// 	ss(stacks);
				// else
					swap_b(stacks);
				}
		}
		else
		{
			if (stacks->a[0] > stacks->a[1] && !secondhalf(stacks, marks, 1)
				&& stacks->a[0] > stacks->a[stacks->len_a - 1] && stacks->a[0] != marks->a_b_max)
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
			// print_stacks(stacks);
		}
		// print_stacks(stacks);
	}
	return (0);
}
