/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danierod <danierod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:26:20 by danierod          #+#    #+#             */
/*   Updated: 2023/03/21 17:23:24 by danierod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack
{
	int				val;
	int				idx;
	struct s_stack	*next;
}	t_s;

typedef struct s_count
{
	int				rest;
	int				bin;
	int				i;
	int				c;
	int				n;
	int				len;
	long int		nb;
	char			*s;
}	t_c;

///////////////////////////////////////////////////////////////////

int		node_pos(t_s *stack, int idx);
int		bin_len(t_s *stack);
int		msg(char *str);
void	error_check(void);
int		list_len(t_s **stack);
void	idx(t_s *stack);
int		dub_check(t_s *stack);
int		not_sorted(t_s *stack_a, t_s *stack_b);
int		ft_atoi(char *str, t_c c);

///////////////////////////////////////////////////////////////////

int		radix_msd(t_s **stack_a, t_s **stack_b, int f);
int		radix_lsd(t_s **stack_a, t_s **stack_b, int f);
int		medium_algorithm_init(t_s **stack_a, t_s **stack_b, t_c c);
int		medium_algorithm_finish(t_s **stack_a, t_s **stack_b, int f);
int		small_algorithm(t_s **stack_a, t_s **stack_b, int f);

///////////////////////////////////////////////////////////////////

int		p_operator(t_s **one, t_s **two, char *str);
int		pa(t_s **a, t_s **b, int f);
int		pb(t_s **a, t_s **b, int f);

//////////////////////////////////////////////////////////////////

int		s_operator(t_s **s, char *str);
int		sa(t_s **a, int f);
int		sb(t_s **b, int f);
int		ss(t_s **a, t_s **b, int f);

/////////////////////////////////////////////////////////////////

int		r_operator(t_s **s, char *str);
int		ra(t_s **a, int f);
int		rb(t_s **b, int f);
int		rr(t_s **a, t_s **b, int f);

/////////////////////////////////////////////////////////////////

int		rr_operator(t_s **s, char *str);
int		rra(t_s **a, int f);
int		rrb(t_s **b, int f);
int		rrr(t_s **a, t_s **b, int f);

////////////////////////////////////////////////////////////////

void	print_list(t_s **t1, t_s **t2, void (*f)());

#endif