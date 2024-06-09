/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:09:57 by zvakil            #+#    #+#             */
/*   Updated: 2024/06/10 02:33:05 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

char	*wordassign(const char *s, int len)
{
	char	*s2;

	s2 = (char *)malloc(sizeof(char) * (len + 1));
	if (!s2)
		return (NULL);
	ft_strlcpy(s2, s, len + 1);
	return (s2);
}

int	is_valid_number(const char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!ft_isdigit(str[i]))
		return (0);
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] != '\0')
		return (0);
	return (1);
}

int	*ft_atoi_check(const char *str)
{
	int			i;
	long long	num;
	int			neg;
	int			*result;

	result = malloc(sizeof(int) * 2);
	neg = 1;
	i = 0;
	num = 0;
	result[0] = 0;
	result[1] = 0;
	if (!is_valid_number(str))
		return (result[1] = -1, result);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			neg = -1;
	while (ft_isdigit(str[i]))
	{
		num = num * 10 + (str[i++] - '0');
		if (num > INT_MAX || (neg == -1 && -1 * num < INT_MIN))
			return (result[1] = -1, result);
	}
	return (result[0] = num * neg, result);
}

void	fill(t_stacks *stack, char **av)
{
	int	j;
	int	*num;

	j = 0;
	while (av[j])
	{
		num = ft_atoi_check(av[j]);
		if (num[1] == -1)
		{
			free(num);
			free_args(av);
			free(stack->a);
			free(stack->b);
			free(stack);
			print_move("Error\n");
			exit(1);
		}
		stack->a[j] = num[0];
		j++;
	}
}
