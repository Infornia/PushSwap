/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_ss.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 09:51:01 by mwilk             #+#    #+#             */
/*   Updated: 2015/04/29 09:51:20 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static int		ps_s(t_ps **h)
{
	int		tmp;

	if ((*h))
	{
		if (((*h)->next))
		{
			tmp = (*h)->nb;
			(*h)->nb = (*h)->next->nb;
			(*h)->next->nb = tmp;
			return (1);
		}
	}
	return (0);
}

int				ps_ss(t_ps **a, t_ps **b)
{
	ps_s(a);
	ps_s(b);
	write(1, "ss ", 3);
	return (3);
}

int				ps_sa(t_ps **a)
{
	if (ps_s(a))
	{
		write(1, "sa ", 3);
		return (1);
	}
	return (0);
}

int				ps_sb(t_ps **b)
{
	if (ps_s(b))
	{
		write(1, "sb ", 3);
		return (2);
	}
	return (0);
}
