/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_special_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/12 15:02:44 by mwilk             #+#    #+#             */
/*   Updated: 2015/06/12 15:54:42 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static void	ini_special(t_data *d)
{
	d->yes = 0;
	d->stop = 0;
	d->mid_or_feed = d->nb_nbr / 2;
	d->count = 0;
}

static void	special_help(t_data *d, t_ps **pa)
{
	while (d->stop)
	{
		if (d->special == 0)
		{
			ps_rra(pa);
			ps_print_piles(d, *pa, NULL, 1);
			d->count = (*pa)->nb < d->count ? (*pa)->nb : d->count;
			d->stop--;
			d->special = 1;
		}
		ps_rra(pa);
		ps_print_piles(d, *pa, NULL, 1);
		d->count = (*pa)->nb < d->count ? (*pa)->nb : d->count;
		if (check_sa(d, *pa))
			ps_print_piles(d, *pa, NULL, ps_sa(pa));
		d->stop--;
		d->special++;
	}
	if (ps_special_rra(d, pa, d->count) && ps_print_piles(d, *pa, NULL, 1))
		d->special++;
	if (check_sa(d, *pa))
	{
		ps_sa(&(*pa));
		ps_print_piles(d, *pa, NULL, 1);
	}
}

int			special_check_a(t_data *d, t_ps **pa)
{
	t_ps	*tmp;

	tmp = *pa;
	ini_special(d);
	while (tmp && tmp->next && !d->special)
	{
		tmp->nb < tmp->next->nb && !d->stop ? d->count++ : d->stop++;
		if (d->stop == 1 && !d->yes)
			d->yes = tmp->nb;
		if (d->yes && d->yes > tmp->next->nb && (tmp->next->next ||
				(d->stop == 1 && !tmp->next->next)))
		{
			d->stop++;
			d->yes = 0;
		}
		tmp = tmp->next;
	}
	if (d->mid_or_feed < d->count && d->stop > 1 && !d->special)
	{
		d->special = 0;
		d->count = tmp->nb;
		special_help(d, pa);
		return (1);
	}
	return (0);
}
