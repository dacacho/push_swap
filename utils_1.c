/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danierod <danierod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:26:20 by danierod          #+#    #+#             */
/*   Updated: 2023/03/21 17:07:01 by danierod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	error_check(void)
{
	write(1, "error\n", 6);
	exit(0);
}
