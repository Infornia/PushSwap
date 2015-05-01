/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 09:42:25 by mwilk             #+#    #+#             */
/*   Updated: 2015/05/01 20:13:59 by mwilk            ###   ########.fr       */
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
	if (b && b->next && b->nb < b->next->nb &&
			(b->nb > last->nb || last->nb == b->next->nb))
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
	if (b && b->next && b->nb > b->next->nb && b->nb < last->nb)
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
	if (b && b->next && b->nb < b->next->nb && b->nb < last->nb)
		return (1);
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
	if (!b->next || (b->nb > b->next->nb && b->nb > last->nb))
		return (1);
	return (0);
}
