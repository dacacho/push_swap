/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danierod <danierod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:26:20 by danierod          #+#    #+#             */
/*   Updated: 2023/03/22 14:16:33 by danierod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	idx(t_s *stack)
{
	t_s	*t1;
	t_s	*t2;

	t1 = stack;
	while (t1)
	{
		t1->idx = 0;
		t2 = stack;
		while (t2)
		{
			if (t1->val > t2->val)
				t1->idx++;
			t2 = t2->next;
		}
		t1 = t1->next;
	}
}

int	small_algorithm(t_s **stack_a, t_s **stack_b, int f)
{
	t_c	c;

	c.len = list_len(stack_a);
	if (c.len == 2 && not_sorted(*stack_a, *stack_b))
		return (sa(stack_a, f));
	else if (c.len == 3 && not_sorted(*stack_a, *stack_b))
	{
		if ((*stack_a)->idx > (*stack_a)->next->idx
			&& (*stack_a)->idx > (*stack_a)->next->next->idx)
			ra(stack_a, f);
		else if ((*stack_a)->idx < (*stack_a)->next->idx
			&& (*stack_a)->next->idx > (*stack_a)->next->next->idx)
			rra(stack_a, f);
		if ((*stack_a)->idx > (*stack_a)->next->idx)
			return (sa(stack_a, f));
	}
	return (0);
}

int	medium_algorithm_finish(t_s **stack_a, t_s **stack_b, int f)
{
	pb(stack_a, stack_b, f);
	small_algorithm(stack_a, stack_a, f);
	if ((*stack_b)->idx < (*stack_b)->next->idx)
		sb(stack_b, f);
	pa(stack_a, stack_b, f);
	pa(stack_a, stack_b, f);
	return (0);
}

int	medium_algorithm_init(t_s **stack_a, t_s **stack_b, t_c c)
{
	c.n = node_pos(*stack_a, 0);
	if (c.n < 3)
	{
		while (c.n-- != 0)
			ra(stack_a, 1);
	}
	else if (c.n > 2)
	{
		while (c.n++ != 5)
			rra(stack_a, 1);
	}
	pb(stack_a, stack_b, 1);
	c.i = node_pos(*stack_a, 1);
	if (c.i < 3)
	{
		while (c.i-- != 0)
			ra(stack_a, 1);
	}
	else if (c.i > 2)
	{
		while (c.i++ != 4)
			rra(stack_a, 1);
	}
	return (medium_algorithm_finish(stack_a, stack_b, 1));
}

int	radix_msd(t_s **stack_a, t_s **stack_b, int f)
{
	t_c	c;

	c.len = list_len(stack_a);
	c.i = 0;
	c.c = 0;
	while (c.i < 33 && not_sorted(*stack_a, *stack_b))
	{
		c.n = 0;
		while (c.n < c.len && not_sorted(*stack_a, *stack_b))
		{
			if ((*stack_a)->idx >> c.i & 1)
				c.c += ra(stack_a, f);
			else
				c.c += pb(stack_a, stack_b, f);
			c.n++;
		}
		while (*stack_b)
			c.c += pa(stack_a, stack_b, f);
		c.i++;
	}
	return (c.c);
}
