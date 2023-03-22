/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danierod <danierod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:26:20 by danierod          #+#    #+#             */
/*   Updated: 2023/03/21 16:48:29 by danierod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	node_pos(t_s *stack, int idx)
{
	t_s	*t;
	t_c	c;

	t = stack;
	c.i = 0;
	while (t)
	{
		if (t->idx == idx)
			return (c.i);
		if (t->next)
		{
			t = t->next;
			c.i++;
		}
	}
	return (c.i);
}

int	list_len(t_s **stack)
{
	t_s	*t;
	int	i;

	t = *stack;
	i = 0;
	while (t != NULL)
	{
		i++;
		t = t->next;
	}
	return (i);
}

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

int	dub_check(t_s *stack)
{
	t_s	*t1;
	t_s	*t2;
	t_c	c;

	t2 = stack;
	while (t2 != NULL)
	{
		c.c = 0;
		t1 = stack;
		c.n = t2->val;
		while (t1 != NULL)
		{
			if (c.n == t1->val)
			{
				c.c++;
				if (c.c > 1)
					error_check();
			}
			t1 = t1->next;
		}
		t2 = t2->next;
	}
	return (1);
}

int	not_sorted(t_s *stack_a, t_s *stack_b)
{
	t_s	*t;

	if (stack_b)
		return (1);
	t = stack_a;
	while (t != NULL)
	{
		if (t->val > t->next->val)
			return (1);
		t = t->next;
		if (t->next == NULL)
			return (0);
	}
	return (0);
}
