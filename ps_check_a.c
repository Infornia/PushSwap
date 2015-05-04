/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 09:41:05 by mwilk             #+#    #+#             */
/*   Updated: 2015/05/04 18:44:24 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int		check_sa(t_data *d, t_ps *pa)
{
	t_ps	*a;
	t_ps	*last;

	last = pa;
	a = pa;
	while (last && last->next)
		last = last->next;
	if ((a->nb > a->next->nb && (a->nb < last->nb || d->special > 1))
			|| d->min == a->next->nb)
	{
		if (d->special)
			d->special--;
		d->print = 1;
		return (1);
	}
	return (0);
}

int		check_rra(t_data *d, t_ps *pa)
{
	t_ps	*a;
	t_ps	*last;

	a = pa;
	last = pa;
	while (last && last->next)
		last = last->next;
	if (a->nb > last->nb && (a->nb < a->next->nb))
	{
		if (d->special)
			d->special--;
		d->print = 1;
		return (1);
	}
	return (0);
}

int		check_ra(t_data *d, t_ps *pa)
{
	t_ps	*a;
	t_ps	*last;

	a = pa;
	last = pa;
	while (last && last->next)
		last = last->next;
	if (a->nb > last->nb && (a->nb > a->next->nb || d->special == 1))
	{
		if (d->special)
			d->special--;
		d->print = 1;
		return (1);
	}
	return (0);
}

int		special_check_a(t_data *d, t_ps **pa)
{
	int		stop;
	int		count;
	int		yes;
	int		mid_or_feed;
	t_ps	*tmp;

	yes = 0;
	stop = 0;
	count = 0;
	mid_or_feed = d->nb_nbr / 2;
	tmp = *pa;
	while (tmp && tmp->next && !d->special)
	{
		tmp->nb < tmp->next->nb && !stop ? count++ : stop++;
		if (stop == 1 && !yes)
			yes = tmp->nb;
		if (yes && yes > tmp->next->nb && (tmp->next->next ||
				(stop == 1 && !tmp->next->next)))
		{
			stop++;
			yes = 0;
		}
		tmp = tmp->next;
	}
	if (mid_or_feed < count && stop > 1 && !d->special)
	{
		d->special = 0;
		count = tmp->nb;
		while (stop)
		{
			if (d->special == 0)
			{
				pnbr((*pa)->nb);
				ps_rra(pa);
				ps_print_piles(d, *pa, NULL, 1);
				count = (*pa)->nb < count ? (*pa)->nb : count;
				stop--;
				d->special = 1;
			}
			ps_rra(pa);
			ps_print_piles(d, *pa, NULL, 1);
			count = (*pa)->nb < count ? (*pa)->nb : count;
			if (check_sa(d, *pa))
				ps_print_piles(d, *pa, NULL, ps_sa(pa));
			stop--;
			d->special++;
		}
		if (ps_special_rra(d, pa, count) && ps_print_piles(d, *pa, NULL, 1))
			d->special++;
		if (check_sa(d, *pa))
		{
			ps_sa(&(*pa));
			ps_print_piles(d, *pa, NULL, 1);
		}
		return (1);
	}
	return (0);
}

int		check_pb(t_data *d, t_ps *pa)
{
	t_ps	*a;
	t_ps	*last;

	a = pa;
	last = pa;
	while (last && last->next)
		last = last->next;
	if ((a->nb < a->next->nb && a->nb < last->nb) || d->min == pa->nb)
	{
		d->print = 1;
		return (1);
	}
	return (0);
}
