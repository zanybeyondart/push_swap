/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:09:57 by zvakil            #+#    #+#             */
/*   Updated: 2024/06/10 02:18:54 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	posit(int a)
{
	if (a < 0)
		return (a * -1);
	return (a);
}

int	*find_cheapest_move(t_stacks *stacks)
{
	int	i;
	int	*current;
	int	*cheapest;

	cheapest = NULL;
	i = 0;
	while (i < stacks->len_a && stacks->len_b > 1)
	{
		current = cal_moves(stacks, i);
		if (!cheapest || ischeaper(current, cheapest, 0, 0))
		{
			if (cheapest)
				free(cheapest);
			cheapest = current;
		}
		else
			free(current);
		i++;
	}
	return (cheapest);
}

void	phase_1(t_stacks *stacks)
{
	int	*cheapest;

	while (stacks->len_a != 0)
	{
		cheapest = find_cheapest_move(stacks);
		if (cheapest)
		{
			cheapestmove(stacks, cheapest);
			free(cheapest);
		}
		push_b(stacks);
	}
}

void	ft_strlcpy(char	*dst, const char *src, size_t size)
{
	size_t	a;

	a = 0;
	if (size > 0)
	{
		while (a < size - 1)
		{
			if (src[a] != '\0')
				dst[a] = src[a];
			else
				break ;
			a++;
		}
		dst[a] = '\0';
	}
}

int	countword(const char *s, char c)
{
	int	a;
	int	d;

	d = 0;
	a = 0;
	while (s[a] != '\0')
	{
		if (s[a] == c)
			a++;
		else
		{
			d++;
			while (s[a] != c && s[a] != '\0')
				a++;
		}
	}
	return (d);
}
