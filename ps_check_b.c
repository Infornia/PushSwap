/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check_b.c		                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 15:48:12 by mwilk             #+#    #+#             */
/*   Updated: 2015/04/04 07:31:59 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int		check_sb(t_ps *pb)
{
	t_ps	*b;
	t_ps	*last;

	b = pb;
	last = pb;
	while (last && last->next)
		last = last->next;
	if (b && (!b->next || b->nb < b->next->nb) && b->nb >= last->nb)
		return (1);
	return (0);
}

int		check_rrb(t_ps *pb)
{
	t_ps	*b;
	t_ps	*last;

	b = pb;
	last = pb;
	while (last && last->next)
		last = last->next;
	if (b->nb > b->next->nb && b->nb < last->nb)
		return (1);
	return (0);
}

int		check_rb(t_ps *pb)
{
	t_ps	*b;
	t_ps	*last;

	b = pb;
	last = pb;
	while (last && last->next)
		last = last->next;
	if (b->nb < b->next->nb && b->nb < last->nb)
		return (1);
	return (0);
}

int		magic_check_b(t_data *d, t_ps **pa, t_ps **pb)
{
	t_ps	*tmp;
	int		magic_b;

	tmp = *pb;
	magic_b = 0;
	(void)d;
	if (*pa && *pb && (*pa)->nb < tmp->nb)
	{
		while (tmp && tmp->next && (*pa)->nb < tmp->nb)
		{
			magic_b++;
			tmp = tmp->next;
		}
		if (!tmp->next)
			magic_b++;
		ps_ra(pa);
		if (chr_opt(d->opts, OPT_V))
			ps_print_piles(*pa, NULL, d->color);
		while (magic_b--)
		{
			ps_pa(pa, pb);
			if (chr_opt(d->opts, OPT_V))
				ps_print_piles(*pa, NULL, d->color);
		}
		return (1);
	}
	return (0);
}

int		check_pa(t_ps *pb)
{
	t_ps	*b;
	t_ps	*last;

	b = pb;
	last = pb;
	if (b && !(b->next))
		return (1);
	while (last && last->next)
		last = last->next;
	if (b->nb > b->next->nb && b->nb > last->nb)
		return (1);
	return (0);
}
