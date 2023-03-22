/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danierod <danierod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:26:20 by danierod          #+#    #+#             */
/*   Updated: 2023/03/22 14:51:20 by danierod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_check(t_s *a, t_s *b)
{
	list_del(a, b);
	write(2, "error\n", 6);
	exit(0);
	return (1);
}

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
	t_s			*end;
	t_s			*temp;
	static t_c	c;

	c.i = 1;
	while (c.i < ac)
	{
		temp = malloc(sizeof(t_s));
		if (temp == NULL)
			error_check(*a, NULL);
		temp->next = NULL;
		if (*a == NULL)
				*a = temp;
		else
			end->next = temp;
		end = temp;
		if (!c.s || *c.s == '\0')
			c.s = av[c.i];
		end->val = ft_atoi(&c, *a);
		while (c.s && *c.s && (*c.s == ' ' || *c.s == '\t'))
			c.s++;
		c.i += *c.s == '\0';
	}
}

int	ft_atoi(t_c *c, t_s *a)
{
	c->nb = 0;
	c->c = 1;
	while (*c->s && (*c->s == ' ' || *c->s == '\t'))
		c->s++;
	c->c = (*c->s != '-' ) - (*c->s == '-');
	if ((*c->s == '-' || *c->s == '+'))
		c->s++;
	if (!(*c->s >= '0' && *c->s <= '9'))
		error_check(a, NULL);
	while (*c->s && *c->s >= '0' && *c->s <= '9')
		c->nb = c->nb * 10 + (*c->s++ - 48);
	c->nb *= c->c;
	if ((c->nb <= -2147483648 || c->nb >= 2147483647) || \
	(*c->s && *c->s != ' ' && *c->s != '\t'))
		error_check(a, NULL);
	return (c->nb);
}

int	main(int ac, char **av)
{
	static t_s	*a;
	static t_s	*b;
	static t_c	c;

	if (ac < 2)
		error_check(NULL, NULL);
	list_gen(&a, ac, av);
	dub_check(a);
	idx(a);
	if (list_len(&a) == 1)
		return (list_del(a, b));
	if (not_sorted(a, b) && dub_check(a))
	{
		if (list_len(&a) > 1 && list_len(&a) < 4)
			small_algorithm(&a, &b, 1);
		else if (list_len(&a) > 3 && list_len(&a) < 6)
			medium_algorithm_init(&a, &b, c);
		else
			radix_msd(&a, &b, 1);
	}
	return (list_del(a, b));
}
