/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:09:57 by zvakil            #+#    #+#             */
/*   Updated: 2024/04/01 09:36:25 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	largest_number(char **av)
{
	int	i;
	int	number;
	int	j;

	i = 1;
	j = 2;
	number = ft_atoi(av[1]);
	while (av[j] != NULL)
	{
		if (number < ft_atoi(av[j]))
		{
			number = ft_atoi(av[j]);
			i = j;
		}
		j++;
	}
	return (number);
}

int	smallest_number(char **av)
{
	int	i;
	int	number;
	int	j;

	i = 1;
	j = 2;
	number = ft_atoi(av[1]);
	while (av[j] != NULL)
	{
		if (ft_atoi(av[i]) > ft_atoi(av[j]))
		{
			number = ft_atoi(av[j]);
			i = j;
		}
		j++;
	}
	return (number);
}

int	mid_number_a(int num, int max, char **av)
{
	int	i;
	int	mid_a;

	i = 1;
	mid_a = max;
	while (av[i] != NULL)
	{
		if (ft_atoi(av[i]) < mid_a && ft_atoi(av[i]) > num)
			mid_a = ft_atoi(av[i]);
		i++;
	}
	return (mid_a);
}

int	mid_number_b(int lowest, int highest, char **av, int ac)
{
	int	i;
	int	high_prev;
	int	counter;

	i = 1;
	high_prev = highest;
	counter = 0;
	while (counter < ac / 2)
	{
		highest = high_prev;
		high_prev = lowest;
		i = 1;
		while (av[i] != NULL)
		{
			if (ft_atoi(av[i]) < highest && ft_atoi(av[i]) > high_prev)
				high_prev = ft_atoi(av[i]);
			i++;
		}
		counter++;
	}
	return (high_prev);
}

void	fill(t_stacks *stack, char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (j != stack->len_a)
		stack->a[j++] = ft_atoi(av[i++]);
}
