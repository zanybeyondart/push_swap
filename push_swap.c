/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 06:49:04 by zvakil            #+#    #+#             */
/*   Updated: 2024/04/01 09:33:19 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" /////////////DONT FORGET ATOI

char	*wordassign(const char *s, int len)
{
	char	*s2;

	s2 = (char *)malloc(sizeof(char) * (len + 1));
	if (!s2)
		return (NULL);
	ft_strlcpy(s2, s, len + 1);
	return (s2);
}

char	**ft_split(const char *s, char c)
{
	int		v[2];
	int		start;
	char	**result;

	if (!s)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * ((countword (s, c)) + 1));
	if (!result)
		return (NULL);
	v[0] = 0;
	v[1] = 0;
	while (s[v[0]] != '\0' && v[1] < (countword (s, c)))
	{
		if (s[v[0]] == c)
			v[0]++;
		else
		{
			start = v[0];
			while (s[v[0]] != c && s[v[0]] != '\0')
				v[0]++;
			result[v[1]++] = wordassign ((char *) s + start, v[0] - start);
		}
	}
	result[v[1]] = NULL;
	return (result);
}


void	setter(t_stacks *stacks, int ac, char **av)
{
	char	**nums;

	stacks->len_a = ac - 1;
	stacks->len_b = 0;
	stacks->a = (int *)malloc(sizeof(int) * stacks->len_a);
	stacks->b = NULL;
	if (ac == 2)
	{
		nums = ft_split(av[1], ' ');
		fill(stacks, nums);
		free(nums);
	}
	else
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

	stacks = malloc(sizeof(t_stacks));
	stacks->moves = 0;
	setter(stacks, ac, av);
	phase_1(stacks, ac);
	lowest_on_bot(stacks);
	while (stacks->len_b != 0)
		push_a(stacks);
	if (cool(stacks))
		printf("\nGG\n%d\n", stacks->moves);
	free(stacks->a);
	free(stacks->b);
	free(stacks);
	return (0);
}
