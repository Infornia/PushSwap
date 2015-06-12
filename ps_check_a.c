/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 09:41:05 by mwilk             #+#    #+#             */
/*   Updated: 2015/06/12 15:09:59 by mwilk            ###   ########.fr       */
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
