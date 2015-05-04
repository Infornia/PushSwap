/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 09:42:43 by mwilk             #+#    #+#             */
/*   Updated: 2015/05/04 18:47:00 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int		check_post_pb(t_data *d, t_ps **a, t_ps **b, int go)
{
	d->print = 0;
	if (check_sa(d, *a) && go)
		check_sb(d, *b) ? ps_ss(a, b) : ps_sa(a);
	else if (check_ra(d, *a) && go == 1)
		check_rb(d, *b) ? ps_rr(a, b) : ps_ra(a);
	else if (check_rra(d, *a) && go == 1)
		check_rrb(d, *b) ? ps_rrr(a, b) : ps_rra(a);
	else if (check_sb(d, *b))
		ps_sb(b);
	else if (check_rb(d, *b))
		ps_rb(b);
	else if (check_rrb(d, *b))
		ps_rrb(b);
	else
		return (0);
	if (d->print)
		ps_print_piles(d, *a, *b, 1);
	return (1);
}

int		check_post_pa(t_data *d, t_ps **a, t_ps **b, int go)
{
	d->print = 0;
	if (*b && (*b)->next && check_sb(d, *b))
		check_sa(d, *a) ? ps_ss(a, b) : ps_sb(b);
	else if (*b && (*b)->next && check_rb(d, *b) && go)
		check_ra(d, *a) ? ps_rr(a, b) : ps_rb(b);
	else if (*b && (*b)->next && check_rrb(d, *b) && go)
		check_rra(d, *a) ? ps_rrr(a, b) : ps_rrb(b);
	else if (check_sa(d, *a) && go)
		ps_sa(a);
	else if (check_ra(d, *a) && go)
		ps_ra(a);
	else if (check_rra(d, *a) && go)
		ps_rra(a);
	else
		return (0);
	if (d->print)
		ps_print_piles(d, *a, *b, 1);
	return (1);
}

t_ps	*get_last(t_ps *p)
{
	t_ps	*tmp;

	tmp = p;
	while (tmp && tmp->next)
		tmp = tmp->next;
	return (tmp);
}
