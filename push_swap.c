/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danierod <danierod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:26:20 by danierod          #+#    #+#             */
/*   Updated: 2023/03/21 17:24:06 by danierod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	list_del(t_s *a, t_s *b)
{
	t_s	*t1;
	t_s	*t2;

	while (a || b)
	{
		if (a)
		{
			t1 = (a)->next;
			free (a);
			a = t1;
		}
		if (b)
		{
			t2 = (b)->next;
			free (b);
			b = t2;
		}
	}
	return (0);
}

void	list_gen(t_s **a, int ac, char **av)
{
	t_s	*t;
	t_s	*h;
	t_c	c;

	c.i = 1;
	while (c.i < ac)
	{
		*a = (t_s *)malloc(sizeof(t_s));
		(*a)->val = (int)ft_atoi(av[c.i], c);
		if (c.i == 1)
		{
			h = *a;
			t = *a;
		}
		else
		{
			t->next = *a;
			t = *a;
		}
		c.i++;
	}
	t->next = NULL;
	*a = h;
}

int	ft_atoi(char *str, t_c c)
{
	c.s = str;
	c.nb = 0;
	c.c = 1;
	while (*c.s)
	{
		if (*c.s || *c.s == '-' || *c.s == '+' || *c.s
			== '/' || (*c.s >= '0' && *c.s <= '9'))
			c.s++;
		else
			error_check();
	}
	c.s = str;
	while (*c.s == '-' || *c.s == '+' || *c.s == '/')
	{
		if (*c.s == '-')
			c.c *= -1;
		c.s++;
	}
	while (*c.s && *c.s >= '0' && *c.s <= '9')
		c.nb = c.nb * 10 + (*c.s++ - 48);
	c.nb *= c.c;
	if (c.nb <= -2147483648 || c.nb >= 2147483647)
		error_check();
	return (c.nb);
}

int	big_sort(t_s **a, t_s **b, int ac, char **av)
{
	t_c	c;

	c.i = radix_msd(a, b, 0);
	list_del(*a, *b);
	list_gen(a, ac, av);
	idx(*a);
	c.n = radix_lsd(a, b, 0);
	list_del(*a, *b);
	list_gen(a, ac, av);
	idx(*a);
	if (c.i > c.n)
		return (radix_lsd(a, b, 1));
	else
		return (radix_msd(a, b, 1));
}

int	main(int ac, char **av)
{
	t_s	*a;
	t_s	*b;
	t_c	c;

	b = NULL;
	list_gen(&a, ac, av);
	idx(a);
	if (list_len(&a) == 1)
		return (list_del(a, b));
	if (not_sorted(a, b) && dub_check(a))
	{
		if (list_len(&a) > 1 && list_len(&a) < 4)
			small_algorithm(&a, &b, 1);
		else if (list_len(&a) > 3 && list_len(&a) < 6)
			medium_algorithm_init(&a, &b, c);
		else if (list_len(&a) > 5)
			big_sort(&a, &b, ac, av);
	}
	if (!not_sorted(a, b))
		printf("sorted\n");
	return (list_del(a, b));
}
