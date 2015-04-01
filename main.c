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

void	ps_error(void)
{
		write(1, "Error\n", 6);
		exit(0);
}

void	pstr(char *s)
{
	while (*s)
		write(1, &(*s++), 1);
}

static int		ps_ok(t_ps *a, t_ps *b)
{
	t_ps	*tmp;

	tmp = a;

	if (b)
		return (0);
	while (tmp && tmp->next)
	{
		if (tmp->nb > tmp->next->nb)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static int		ok_ab(t_ps *a)
{
	t_ps	*tmp;

	tmp = a;
	while (tmp && tmp->next)
	{
		if (tmp->nb > tmp->next->nb)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
t_ps	*sort(t_ps *a)
{
	t_ps	*b;

	b = NULL;
	while (!ps_ok(a, b))
	{
		if (ok_ab(a))
		{
			pstr("Fin tri de a\n");
			while ((b && ok_ab(b)) || !ok_ab(b))
			{
				if (check_pa(b))
				{
					ps_pa(&a, &b);
					if (check_sa(a))
						ps_sa(&a);
				}
				else if (check_sb(b))
					ps_sb(&b);
				else if (check_rb(b))
					ps_rb(&b);
				else if (check_rrb(b))
					ps_rrb(&b);
			}
			break;
		}
		else if (check_sa(a))
			ps_sa(&a);
		else if (check_ra(a))
			ps_ra(&a);
		else if (check_rra(a))
			ps_rra(&a);
		else if (check_pb(a))
		{
			ps_pb(&a, &b);
			if (b->next && check_sb(b))
				ps_sb(&b);
		}
	}
	if (ps_ok(a, b))
		pstr("SUCCESSFULL!!!!!!!!\n");
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
	write(1, "\b\n", 2);
	ps_del(a);
	return (0);
}

t_ps	*sort2(t_ps *a)
{
	t_ps	*b;
	int		i;
	int		max;

	b = NULL;
	max = 0;
	while (a && !ps_ok(a, b))
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
