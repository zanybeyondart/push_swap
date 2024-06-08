/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:09:57 by zvakil            #+#    #+#             */
/*   Updated: 2024/04/01 09:33:42 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	posit(int a)
{
	if (a < 0)
		return (a * -1);
	return (a);
}

void	phase_1(t_stacks *stacks, int ac)
{
	int	i;
	int	*current;
	int	*cheapest;

	while (stacks->len_a != 0)
	{
	i = 0;
	cheapest = NULL;
	current = NULL;
		while (i < stacks->len_a && stacks->len_b > 1)
		{
			current = cal_moves(stacks, i);
			if (cheapest == NULL)
				cheapest = current;
			else if (ischeaper(current, cheapest, 0, 0))
			{
				free(cheapest);
				cheapest = current;
			}
			i++;
		}
		if (cheapest)
			cheapestmove(stacks, cheapest);
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