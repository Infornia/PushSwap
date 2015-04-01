/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_ss.c		                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 15:48:12 by mwilk             #+#    #+#             */
/*   Updated: 2015/03/25 20:58:04 by mwilk            ###   ########.fr       */
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

void			ps_ss(t_ps **a, t_ps **b)
{
	int		i;

	i = ps_sa(a) + ps_sb(b);
	if (i == 3)
		write(1, "ss ", 3);
	if (i == 2)
		write(1, "sa ", 3);
	if (i == 1)
		write(1, "sb ", 3);
}

int				ps_sa(t_ps **a)
{
	if (ps_s(a))
	{
		write(1, "sa ", 3);
		return (2);
	}
	return (0);

}

int				ps_sb(t_ps **b)
{
	if (ps_s(b))
	{
		write(1, "sb ", 3);
		return (1);
	}
	return (0);
}
