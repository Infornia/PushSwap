/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check_rev_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 09:43:04 by mwilk             #+#    #+#             */
/*   Updated: 2015/04/29 09:43:09 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int		check_rev_sa(t_data *d, t_ps *pa)
{
	t_ps	*a;

	a = pa;
	if (a->nb < a->next->nb && a->next->nb > a->next->next->nb)
	{
		if (d->special)
			d->special--;
		return (1);
	}
	return (0);
}

int		check_rev_rra(t_data *d, t_ps *pa)
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

int		check_rev_ra(t_data *d, t_ps *pa)
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

int		check_rev_pb(t_ps *pa)
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
