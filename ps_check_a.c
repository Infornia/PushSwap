/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check.c		                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 15:48:12 by mwilk             #+#    #+#             */
/*   Updated: 2015/04/03 19:19:32 by mwilk            ###   ########.fr       */
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
	if (a->nb > a->next->nb && (a->nb < last->nb || d->special > 1))
	{
		if (d->special)
			d->special--;
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
	if (a->nb > last->nb && (a->nb < a->next->nb || d->special))
	{
		if (d->special)
			d->special--;
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
	if (a->nb > last->nb && (a->nb > a->next->nb || d->special))
	{
		if (d->special)
			d->special--;
		return (1);
	}
	return (0);
}

int		magic_check_a(t_data *d, t_ps **pa)
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
		if (yes && yes > tmp->next->nb)
		{
			stop++;
			yes = 0;
		}
		tmp = tmp->next;
	}
	if (mid_or_feed <= count && stop > 1 && !d->special)
	{
		d->special = stop;
		while (stop)
		{
			ps_rra(pa);
			stop--;
		}
		return (1);
	}
	return (0);
}

int		check_pb(t_ps *pa)
{
	t_ps	*a;
	t_ps	*last;

	a = pa;
	last = pa;
	while (last && last->next)
		last = last->next;
	if (a->nb < a->next->nb && a->nb < last->nb)
		return (1);
	return (0);
}
