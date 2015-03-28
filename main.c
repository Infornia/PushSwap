/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 15:48:12 by mwilk             #+#    #+#             */
/*   Updated: 2015/03/25 20:58:04 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

t_ps	*sort(t_ps *a)
{
	t_ps	*b;
	int		i;
	int		max;

	b = NULL;
	max = 0;
	while (a)
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
	{
		write(1, "Hey That's a fail man !\n", 24);
		exit(0);
	}
	while (ac > 1)
		ps_front(&a, ps_new(tt_atoi(av[--ac])));
	a = sort(a);
	write(1, "\b\n", 2);
	ps_del(a);
	return (0);
}
