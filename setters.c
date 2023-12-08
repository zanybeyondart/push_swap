/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:09:57 by zvakil            #+#    #+#             */
/*   Updated: 2023/12/02 14:58:00 by zvakil           ###   ########.fr       */
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
	number = atoi(av[1]);
	while (av[j] != NULL)
	{
		if (number < atoi(av[j]))
		{
			number = atoi(av[j]);
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
	number = 0;
	while (av[j] != NULL)
	{
		if (atoi(av[i]) > atoi(av[j]))
		{
			number = atoi(av[j]);
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
		if (atoi(av[i]) < mid_a && atoi(av[i]) > num)
			mid_a = atoi(av[i]);
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
			if (atoi(av[i]) < highest && atoi(av[i]) > high_prev)
				high_prev = atoi(av[i]);
			i++;
		}
		counter++;
	}
	return (high_prev);
}
