/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check_b.c		                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 15:48:12 by mwilk             #+#    #+#             */
/*   Updated: 2015/03/25 20:58:04 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int		check_sb(t_ps *pb)
{
	t_ps	*a;
	t_ps	*last;

	last = pb;
	a = pb;
	while (last && last->next)
		last = last->next;
	if (a->nb < a->next->nb && a->nb > last->nb)
		return (1);
	return (0);
}

int		check_rrb(t_ps *pb)
{
	t_ps	*a;
	t_ps	*last;

	a = pb;
	last = a;
	while (last && last->next)
		last = last->next;
	if (a->nb > a->next->nb && a->nb < last->nb)
		return (1);
	return (0);
}

int		check_rb(t_ps *pb)
{
	t_ps	*a;
	t_ps	*last;

	a = pb;
	last = a;
	while (last && last->next)
		last = last->next;
	if (a->nb < a->next->nb && a->nb > last->nb)
		return (1);
	return (0);
}

int		check_pa(t_ps *pb)
{
	t_ps	*a;
	t_ps	*last;

	a = pb;
	last = a;
	if (a && !(a->next))
		return (1);
	while (last && last->next)
		last = last->next;
	if (a->nb > a->next->nb && a->nb > last->nb)
		return (1);
	return (0);
}
