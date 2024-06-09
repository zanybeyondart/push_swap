/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 16:26:05 by zvakil            #+#    #+#             */
/*   Updated: 2024/06/10 02:14:40 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_int(char **arg)
{
	int	i;
	int	j;

	i = 0;
	while (arg[i])
	{
		j = 0;
		if (arg[i][j] == '-' || arg[i][j] == '+')
			j++;
		while (arg[i][j])
		{
			if (!ft_isdigit(arg[i][j]))
			{
				print_move("Error\n");
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	check_dup(t_stacks *stacks, char **args)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!stacks->a)
		return ;
	while (i < stacks->len_a)
	{
		j = i + 1;
		while (j < stacks->len_a)
		{
			if (stacks->a[i] == stacks->a[j])
			{
				free_args(args);
				free(stacks->a);
				free(stacks->b);
				free(stacks);
				print_move("Error\n");
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	check_args(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j] == ' ')
			j++;
		if (av[i][j] == '\0')
		{
			print_move("Invalid Arguments\n");
			exit(1);
		}
		i++;
	}
}

char	**parsing(char **av)
{
	int		i;
	char	*joined;
	char	**splitted;

	i = 0;
	joined = ft_strdup("");
	if (joined == NULL)
		return (free(joined), NULL);
	while (av[++i])
	{
		joined = ft_strjoin(joined, av[i]);
		joined = ft_strjoin(joined, " ");
	}
	splitted = ft_split(joined, ' ');
	if (splitted == NULL)
		return (free(joined), NULL);
	free(joined);
	i = 0;
	check_args(splitted);
	check_int(splitted);
	return (splitted);
}
