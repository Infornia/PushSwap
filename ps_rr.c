/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rr.c			                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 15:48:12 by mwilk             #+#    #+#             */
/*   Updated: 2015/03/25 20:58:04 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static int		ps_rrs(t_ps **h)
{
	t_ps	*tmp;
	t_ps	*prev;

	tmp = *h;
	if (tmp && tmp->next)
	{
		while (tmp->next)
		{
			prev = tmp;
			tmp = tmp->next;
		}
		prev->next = NULL;
		tmp->next = *h;
		*h = tmp;
		return (1);
	}
	return (0);
}

int				ps_special_rra(t_data *d, t_ps **h, int min)
{
	t_ps	*tmp;
	t_ps	*prev;

	(void)d;
	tmp = *h;
	if (tmp && tmp->next)
	{
		while (tmp->next)
		{
			prev = tmp;
			tmp = tmp->next;
		}
		if (min < tmp->nb && prev->nb < min)
		{
			prev->next = NULL;
			tmp->next = *h;
			*h = tmp;
			write(1, "rra ", 4);
			return (1);
		}
	}
	return (0);
}

int				ps_rrr(t_ps **a, t_ps **b)
{
	write(1, "rrr ", 4);
	return (ps_rrs(a) + ps_rrs(b));
}

int				ps_rra(t_ps **a)
{
	write(1, "rra ", 4);
	return (ps_rrs(a));
}

int				ps_rrb(t_ps **b)
{
	write(1, "rrb ", 4);
	ps_rrs(b);
	return (2);
}
