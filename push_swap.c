/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 06:49:04 by zvakil            #+#    #+#             */
/*   Updated: 2024/06/10 02:14:53 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
}

void	free_program(char **args, t_stacks *stacks)
{
	free_args(args);
	free(stacks->a);
	free(stacks->b);
	free(stacks);
}

void	setter(t_stacks *stacks, char **av)
{
	int		i;

	i = 0;
	while (av[i])
		i++;
	stacks->len_a = i;
	stacks->len_b = 0;
	stacks->a = (int *)malloc(sizeof(int) * stacks->len_a);
	stacks->b = NULL;
	fill(stacks, av);
}

int	cool(t_stacks *stacks)
{
	int	i;

	i = 0;
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
	t_stacks	*stacks;
	char		**args;

	args = NULL;
	if (ac >= 2)
	{
		args = parsing(av);
		stacks = malloc(sizeof(t_stacks));
		stacks->moves = 0;
		setter(stacks, args);
		check_dup(stacks, args);
		if (!cool(stacks) && stacks->len_a == 2)
			swap_a(stacks);
		else if (!cool(stacks) && stacks->len_a > 5)
		{
			phase_1(stacks);
			lowest_on_bot(stacks);
			while (stacks->len_b != 0)
				push_a(stacks);
		}
		else if (!cool(stacks) && stacks->len_a <= 5)
			mini_sort(stacks);
		free_program(args, stacks);
	}
	return (0);
}
