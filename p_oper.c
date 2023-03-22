/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_oper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danierod <danierod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:26:20 by danierod          #+#    #+#             */
/*   Updated: 2023/03/21 17:06:42 by danierod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	p_operator(t_s **one, t_s **two, char *str)
{
	t_s	*t1;

	t1 = *two;
	*two = *one;
	*one = (*one)->next;
	(*two)->next = t1;
	if (!str)
		return (0);
	write(1, str, 2);
	return (write(1, "\n", 1));
}

int	pa(t_s **a, t_s **b, int f)
{
	if (f == 0)
		return (p_operator(b, a, NULL));
	else
		return (p_operator(b, a, "pa"));
}

int	pb(t_s **a, t_s **b, int f)
{
	if (f == 0)
		return (p_operator(a, b, NULL));
	else
		return (p_operator(a, b, "pb"));
}
