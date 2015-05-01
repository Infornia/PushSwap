/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 15:48:12 by mwilk             #+#    #+#             */
/*   Updated: 2015/05/01 20:26:30 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

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

int				ok_ab(t_ps *p)
{
	t_ps	*tmp;

	tmp = p;
	while (tmp && tmp->next)
	{
		if (tmp->nb > tmp->next->nb)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static void		initiate(t_data *d, t_ps **a, t_ps **b)
{
	int		mid;
	int		i;
	int		j;

	mid = d->nb_nbr / 2;
	i = 0;
	j = 1;
	while (j < 2)
	{
		while (i < mid * j && ps_pb(a, b))
		{
			ps_print_piles(d, *a, *b, 1);
			check_post_pb(d, a, b, 0);
			i++;
		}
		while (i)
		{
			ps_pa(a, b);
			ps_print_piles(d, *a, *b, 1);
			check_post_pa(d, a, b, 1);
			i--;
		}
		j++;
	}
	d->init = 1;
}

static int		sort_b(t_data *d, t_ps **a, t_ps **b)
{
	while ((*b && ok_ab(*b)) || !ok_ab(*b))
	{
		if (check_sb(*b))
			ps_sb(b);
		else if (check_rb(*b))
			ps_rb(b);
		else if (check_rrb(*b))
			ps_rrb(b);
		else if (magic_check_b(d, *a, *b))
			magic_b(d, a, b);
		else if (check_pa(*b) && ps_pa(a, b))
			check_post_pa(d, a, b, 1);
		ps_print_piles(d, *a, *b, 1);
	}
	if (ps_ok(*a, *b))
		return (1);
	return (0);
}

void			sort_a(t_data *d, t_ps *a, t_ps *b)
{
	if (!d->init && d->nb_nbr >= 300)
		initiate(d, &a, &b);
	while (!ps_ok(a, b))
	{
		if (ok_ab(a) && sort_b(d, &a, &b) && ok_ab(a))
			break ;
		else if (check_sa(d, a))
			ps_sa(&a);
		else if (check_ra(d, a))
			ps_ra(&a);
		else if (check_pb(d, a) && ps_pb(&a, &b) && ps_print_piles(d, a, b, 1))
			check_post_pb(d, &a, &b, 1);
		else if (check_rra(d, a))
			ps_rra(&a);
		else if (magic_check_a(d, a, b))
			magic_b(d, &a, &b);
		else if (special_check_a(d, &a))
			;
		ps_print_piles(d, a, b, 1);
	}
	ps_del(a);
	if (d->nb_nbr > 1)
		write(1, "\b\n", 2);
}
