/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_oper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danierod <danierod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:26:20 by danierod          #+#    #+#             */
/*   Updated: 2023/03/21 16:55:19 by danierod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	s_operator(t_s **s, char *str)
{
	t_s	*t;

	t = (*s)->next;
	(*s)->next = (*s)->next->next;
	t->next = *s;
	*s = t;
	if (!str)
		return (0);
	write(1, str, 2);
	return (write(1, "\n", 1));
}

int	sa(t_s **a, int f)
{
	if (f == 0)
		return (s_operator(a, NULL));
	else
		return (s_operator(a, "sa"));
}

int	sb(t_s **b, int f)
{
	if (f == 0)
		return (s_operator(b, NULL));
	else
		return (s_operator(b, "sb"));
}

int	ss(t_s **a, t_s **b, int f)
{
	if (f == 0)
	{
		s_operator(a, NULL);
		return (s_operator(b, NULL));
	}
	else
	{
		s_operator(a, NULL);
		return (s_operator(b, "ss"));
	}
}
