/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 15:48:12 by mwilk             #+#    #+#             */
/*   Updated: 2015/04/29 10:15:46 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	ps_error(void)
{
		write(1, "Error\n", 6);
		exit(0);
}

static int		ps_ok(t_ps *a, t_ps *b)
{
	t_ps	*tmp;

	tmp = a;

	if (b)
		return (1);
	while (tmp && tmp->next)
	{
		if (tmp->nb > tmp->next->nb)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

t_ps	*sort(t_ps *a)
{
	t_ps	*b;
	int		i;
	int		max;

	b = NULL;
	max = 0;
	while (a && ps_ok(a, b))
	{
		i = 0;
		while (b && a->nb < b->nb && i < max)
		{
			ps_rb(&b);
			i++;
		}
		ps_pb(&a, &b);
		while (i-- > 0)
			ps_rrb(&b);
		max++;
	}
	while (b)
		ps_pa(&a, &b);
	return (a);
}

int		main(int ac, char **av)
{
	t_ps	*a;

	a = NULL;
	if (ac < 1)
		ps_error();
	while (ac > 1)
		ps_front(&a, ps_new(tt_atoi(av[--ac])));
	a = sort(a);
	//write(1, "\b\n", 2);
	ps_del(a);
	return (0);
}
