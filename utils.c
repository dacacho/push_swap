/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danierod <danierod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:26:20 by danierod          #+#    #+#             */
/*   Updated: 2023/03/22 14:16:19 by danierod         ###   ########.fr       */
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

int	bin_len(t_s *stack)
{
	t_s	*t;
	t_c	c;

	c.len = 0;
	c.bin = 0;
	c.i = 1;
	t = stack;
	c.n = t->idx;
	while (t)
	{
		if (t->next && t->next->idx > t->idx)
			c.n = t->next->idx;
		t = t->next;
	}
	while (c.n != 0)
	{
		c.rest = c.n % 2;
		c.n /= 2;
		c.bin += c.rest * c.i;
		c.i *= 10;
		c.len++;
	}
	return (c.len);
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
					error_check(stack, NULL);
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
