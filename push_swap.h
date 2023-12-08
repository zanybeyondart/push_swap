/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 06:49:36 by zvakil            #+#    #+#             */
/*   Updated: 2023/12/08 16:48:46 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_infos{
	int	a_t_mid;
	int	a_b_max;
	int	b_t_mid2;
	int	b_b_min;
}t_info;

typedef struct s_stacks{
	int	*a;
	int	*b;
	int	len_a;
	int	len_b;
}t_stacks;

void		fill(t_stacks *stack, char **av);
void		print_stacks(t_stacks *stacks);
void		push_b(t_stacks *stacks);
int			largest_number(char **av);
int			smallest_number(char **av);
int			mid_number_a(int num, int low, char **av);
int			mid_number_b(int lowest, int highest, char **av, int ac);
int			stack_len(int *stack);
int			aligned(int *a, int ac);

#endif