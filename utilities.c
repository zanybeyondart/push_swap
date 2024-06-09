/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:09:57 by zvakil            #+#    #+#             */
/*   Updated: 2024/06/10 01:59:02 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_move(char *word)
{
	int	i;

	i = 0;
	while (word[i] != '\0')
		write(1, &word[i++], 1);
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

int	ft_isdigit(int a)
{
	if (a >= '0' && a <= '9')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int	a;
	int	b;
	int	neg;

	neg = 0;
	b = 0;
	a = 0;
	while ((str[a] >= 9 && str[a] <= 13) || str[a] == ' ')
		a++;
	if (str[a] == '+' || str[a] == '-')
	{
		if (str[a] == '-')
			neg = 1;
		a++;
	}
	while (ft_isdigit(str[a]))
	{
		b = b * 10 + (str[a] - 48);
		a++;
	}
	if (neg == 1)
		return (b * -1);
	else
		return (b);
}
