/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_oper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danierod <danierod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:26:20 by danierod          #+#    #+#             */
/*   Updated: 2023/03/17 19:23:33 by danierod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int rr_operator(t_s **s, char *str)
{
    t_s *t1;

    t1 = *s;
    while (t1)
    {
        if (t1->next && t1->next->next == NULL)
        {
            t1->next->next = *s;
            *s = t1->next;
            t1->next = NULL;
            break ;
        }
        t1 = t1->next;
    }
    if (!str)
		return (0);
    write(1, str, 3);
    return (write(1, "\n", 1));
}

int	rra(t_s **a, int f)
{
    if (f == 0)
        return (rr_operator(a, NULL));
    else
        return (rr_operator(a, "rra"));
}

int	rrb(t_s **b, int f)
{
	if (f == 0)
        return (rr_operator(b, NULL));
    else
        return (rr_operator(b, "rrb"));
}

int	rrr(t_s **a, t_s **b, int f)
{
    if (f == 0)
    {
        rr_operator(a, NULL);
        return (rr_operator(b, NULL));
    }
    else
    {
        rr_operator(a, NULL);
        return (rr_operator(b, "rrr"));
    }
}