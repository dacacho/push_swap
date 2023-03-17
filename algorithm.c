/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danierod <danierod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:26:20 by danierod          #+#    #+#             */
/*   Updated: 2023/03/17 19:41:56 by danierod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int bin_len(t_s *stack)
{
    t_s *t;
    t_c c;
    
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

int	small_algorithm(t_s **stack_a, t_s **stack_b, int f)
{
    t_c c;

    c.len = list_len(stack_a);
    if (c.len == 2 && not_sorted(*stack_a, *stack_b))
        return (sa(stack_a, f));
    else if (c.len == 3 && not_sorted(*stack_a, *stack_b))
    {
        if ((*stack_a)->idx > (*stack_a)->next->idx && (*stack_a)->idx > (*stack_a)->next->next->idx)
            ra(stack_a, f);
        else if ((*stack_a)->idx < (*stack_a)->next->idx && (*stack_a)->next->idx > (*stack_a)->next->next->idx)
            rra(stack_a, f);
        if ((*stack_a)->idx > (*stack_a)->next->idx)
            return (sa(stack_a, f));
    }
    return (0);
}

int	medium_algorithm(t_s **stack_a, t_s **stack_b, int f)
{
    t_c c;

    c.len = list_len(stack_a);
    c.i = 0;
    while (c.i < 13 && not_sorted(*stack_a, *stack_b))
    {
        if ((*stack_a)->idx > (*stack_a)->next->idx)
            sa(stack_a, f);
        else
            ra(stack_a, f);
        c.i++;
    }
    
    return (0);
}

int radix_msd(t_s **stack_a, t_s **stack_b, int f)
{
    t_c c;

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

int radix_lsd(t_s **stack_a, t_s **stack_b, int f)
{
    t_c c;

    c.len = list_len(stack_a);
    c.i = bin_len(*stack_a);
    c.c = 0;
    while (c.i >= 0 && not_sorted(*stack_a, *stack_b))
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
        c.i--;
    }
    return (c.c);
}

    /*
    ///////////////////////////////////////
    if (not_sorted(*stack_a, *stack_b) == 1)
        printf("not sorted\n");
    else
        printf("sorted\n");
    print_list(stack_a, stack_b, NULL);
    ///////////////////////////////////////
    */