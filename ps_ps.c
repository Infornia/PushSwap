/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 15:48:12 by mwilk             #+#    #+#             */
/*   Updated: 2015/04/29 09:50:27 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static void		ps_ps(t_ps **dest, t_ps **src)
{
	t_ps	*tmp;

	tmp = *src;
	*src = (*src)->next;
	tmp->next = NULL;
	ps_front(dest, tmp);
}

int				ps_pa(t_ps **a, t_ps **b)
{
	if (*b)
	{
		ps_ps(a, b);
		write(1, "pa ", 3);
		return (1);
	}
	return (0);
}

int				ps_pb(t_ps **a, t_ps **b)
{
	if (*a)
	{
		ps_ps(b, a);
		write(1, "pb ", 3);
		return (2);
	}
	return (0);
}
