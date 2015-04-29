/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 09:50:35 by mwilk             #+#    #+#             */
/*   Updated: 2015/04/29 09:50:43 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static int		ps_rs(t_ps **h)
{
	t_ps	*tmp;
	t_ps	*first;

	tmp = *h;
	if (tmp && tmp->next)
	{
		first = *h;
		*h = (*h)->next;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = first;
		first->next = NULL;
		return (1);
	}
	return (0);
}

int				ps_rr(t_ps **a, t_ps **b)
{
	write(1, "rr ", 3);
	return (ps_rs(a) + ps_rs(b));
}

int				ps_ra(t_ps **a)
{
	write(1, "ra ", 3);
	return (ps_rs(a));
}

int				ps_rb(t_ps **b)
{
	write(1, "rb ", 3);
	ps_rs(b);
	return (2);
}
