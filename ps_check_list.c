/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check_list.c		                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 15:48:12 by mwilk             #+#    #+#             */
/*   Updated: 2015/04/04 08:03:44 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int		check_post_pb(t_data *d, t_ps *a, t_ps *b)
{
	if (check_sa(d, a))
		check_sb(b) ? ps_ss(&a, &b) : ps_sa(&a);
	else if (check_ra(d, a))
		check_rb(b) ? ps_rr(&a, &b) : ps_ra(&a);
	else if (check_rra(d, a))
		check_rrb(b) ? ps_rrr(&a, &b) : ps_rra(&a);
	else
		return (0);
	if (d->v)
		ps_print_piles(d, a, b, 1);
	return (2);
}

int		check_post_pa(t_data *d, t_ps *a, t_ps *b)
{
	if (b && b->next && check_sb(b))
		check_sa(d, a) ? ps_ss(&a, &b) : ps_sb(&b);
	else if (b && b->next && check_rb(b))
		check_ra(d, a) ? ps_rr(&a, &b) : ps_rb(&b);
	else if (b && b->next && check_rrb(b))
		check_rra(d, a) ? ps_rrr(&a, &b) : ps_rrb(&b);
	else
		return (0);
	if (d->v)
		ps_print_piles(d, a, b, 1);
	return (1);
}
