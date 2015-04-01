/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check.c		                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 15:48:12 by mwilk             #+#    #+#             */
/*   Updated: 2015/03/25 20:58:04 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int		check_sa(t_ps *pa)
{
	t_ps	*a;
	t_ps	*last;

	last = pa;
	a = pa;
	while (last && last->next)
		last = last->next;
	if (a->nb > a->next->nb && a->nb < last->nb)
		return (1);
	return (0);
}

int		check_rra(t_ps *pa)
{
	t_ps	*a;
	t_ps	*last;

	a = pa;
	last = a;
	while (last && last->next)
		last = last->next;
	if (a->nb < a->next->nb && a->nb > last->nb)
		return (1);
	return (0);
}

int		check_ra(t_ps *pa)
{
	t_ps	*a;
	t_ps	*last;

	a = pa;
	last = a;
	while (last && last->next)
		last = last->next;
	if (a->nb > a->next->nb && a->nb > last->nb)
		return (1);
	return (0);
}

int		check_pb(t_ps *pa)
{
	t_ps	*a;
	t_ps	*last;

	a = pa;
	last = a;
	while (last && last->next)
		last = last->next;
	if (a->nb < a->next->nb && a->nb < last->nb)
		return (1);
	return (0);
}
