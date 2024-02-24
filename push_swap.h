/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 06:49:36 by zvakil            #+#    #+#             */
/*   Updated: 2024/02/17 11:03:33 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <strings.h>

typedef struct s_infos{
	int	a_t_mid;
	int	a_b_max;
	int	b_t_mid2;
	int	b_b_min;
	int	next_b;
}t_info;

typedef struct s_stacks{
	int	*a;
	int	*b;
	int	len_a;
	int	len_b;
	int	b_high;
	int	b_low;
	int	a_high;
	int	a_low;
	int	moves;
}t_stacks;

void		fill(t_stacks *stack, char **av);
void		print_stacks(t_stacks *stacks);
void		push_b(t_stacks *stacks);
void		swap_b(t_stacks *stacks);
void		rotate_b(t_stacks *stacks);
void		set_high_low(t_stacks *stacks);
void		set_high_low_a(t_stacks *stacks);
void		rotate_a(t_stacks *stacks);
void		swap_a(t_stacks *stacks);
void		setter(t_stacks *stacks, t_info *marks, int ac, char **av);
void		setter_2(t_stacks *stacks, t_info *marks, int ac, char **av);
void		lowest_on_bot(t_stacks *stacks);
void		rotate_r_b(t_stacks *stacks);
void		highest_on_bot(t_stacks *stacks);
void		push_a(t_stacks *stacks);
void		pre_push_b(t_stacks *stacks, int lim, t_info *marks);
void		rotate_r_a(t_stacks *stacks);
int			next_b(t_stacks *stacks, t_info *marks);
int			largest_number(char **av);
int			smallest_number(char **av);
int			secondhalf(t_stacks *stacks, t_info *marks, int number);
int			mid_number_a(int num, int low, char **av);
int			mid_number_b(int lowest, int highest, char **av, int ac);
int			stack_len(int *stack);
int			aligned(t_stacks *stacks, int ac);
int			phase_1(t_stacks *stacks, int ac, t_info *marks);
int			phase_2(t_stacks *stacks, int ac, t_info *marks);
int			no_b_in_a(t_stacks *stacks, t_info *marks);
int			should_be(t_stacks *stacks);
int			rotate_efficient(t_stacks *stacks);
void		ss(t_stacks *stacks);

#endif