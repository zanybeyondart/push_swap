/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 06:49:36 by zvakil            #+#    #+#             */
/*   Updated: 2024/04/01 09:34:19 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <strings.h>

typedef struct s_stacks{
	int	*a;
	int	*b;
	int	len_a;
	int	len_b;
	int	b_high;
	int	b_low;
	int	moves;
}t_stacks;

// Setters.c
void		fill(t_stacks *stack, char **av);
int			largest_number(char **av);
int			smallest_number(char **av);
int			mid_number_a(int num, int low, char **av);
int			mid_number_b(int lowest, int highest, char **av, int ac);

// A Moves
void		rotate_r_a(t_stacks *stacks);
void		rotate_a(t_stacks *stacks);
void		swap_a(t_stacks *stacks);
void		push_a(t_stacks *stacks);

// B Moves
void		push_b(t_stacks *stacks);
void		swap_b(t_stacks *stacks);
void		rotate_b(t_stacks *stacks);
void		rotate_r_b(t_stacks *stacks);

// Both Moves
void		ss(t_stacks *stacks);
void		rrr(t_stacks *stacks);
int			rr(t_stacks *stacks);

// Utilities and Main
void		set_high_low(t_stacks *stacks);
void		lowest_on_bot(t_stacks *stacks);
void		phase_1(t_stacks *stacks, int ac);
void		print_move(char *word);
void		set_moves(t_stacks *stacks, int i, int *moves, int j);
int			posit(int a);
int			*cal_moves(t_stacks *stacks, int i);
int			ischeaper(int *current, int *cheapest, int t_cheap, int t_cur);
void		cheapestmove(t_stacks *stacks, int *cheapest);
int			ft_atoi(const char *str);
void		ft_strlcpy(char	*dst, const char *src, size_t size);
int			countword(const char *s, char c);

#endif