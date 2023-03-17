/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_oper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danierod <danierod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:26:20 by danierod          #+#    #+#             */
/*   Updated: 2023/03/17 19:13:09 by danierod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    msg(char *str)
{
    if (!str)
		return (0);
    write(1, str, 2);
    return(write(1, "\n", 1));
}

int r_operator(t_s **s, char *str)
{
    t_s *t1;
    t_s *t2;
    t_s *t3;

    t1 = *s;
    t2 = *s;
    t3 = (*s)->next;
    while (t1)
    {
        if (t1-> next == NULL)
            return (0);
        if (t1->next && t1->next->next == NULL)
        {
            t1->next->next = t2;
            t2->next = NULL;
            *s = t3;
            break ;
        }
        t1 = t1->next;
    } 
	return(msg(str));
}

int	ra(t_s **a, int f)
{
    if (f == 0)
        return (r_operator(a, NULL));
    else
        return (r_operator(a, "ra"));
}

int	rb(t_s **b, int f)
{
	if (f == 0)
        return (r_operator(b, NULL));
    else
        return (r_operator(b, "ra"));
}

int	rr(t_s **a, t_s **b, int f)
{
    if (f == 0)
    {
        r_operator(a, NULL);
        return (r_operator(b, NULL));
    }
    else
    {
        r_operator(a, NULL);
        return (r_operator(b, "rr"));
    }
}