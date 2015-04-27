/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check_list.c		                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 15:48:12 by mwilk             #+#    #+#             */
/*   Updated: 2015/04/27 21:11:54 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int		check_post_pb(t_data *d, t_ps **a, t_ps **b)
{
	ps_print_piles(d, *a, *b, 1);
	if (check_sa(d, *a))
		check_sb(*b) ? ps_ss(a, b) : ps_sa(a);
	else if (check_ra(d, *a))
		check_rb(*b) ? ps_rr(a, b) : ps_ra(a);
	else if (check_rra(d, *a))
		check_rrb(*b) ? ps_rrr(a, b) : ps_rra(a);
	else if (check_sb(*b))
		ps_sb(b);
	else if (check_rb(*b))
		ps_rb(b);
	else if (check_rrb(*b))
		ps_rrb(b);
	else
		return (0);
	return (1);
}

int		check_post_pa(t_data *d, t_ps **a, t_ps **b)
{
	ps_print_piles(d, *a, *b, 1);
	if (*b && (*b)->next && check_sb(*b))
		check_sa(d, *a) ? ps_ss(a, b) : ps_sb(b);
	else if (*b && (*b)->next && check_rb(*b))
		check_ra(d, *a) ? ps_rr(a, b) : ps_rb(b);
	else if (*b && (*b)->next && check_rrb(*b))
		check_rra(d, *a) ? ps_rrr(a, b) : ps_rrb(b);
	else if (check_sa(d, *a))
		ps_sa(a);
	else if (check_ra(d, *a))
		ps_ra(a);
	else if (check_rra(d, *a))
		ps_rra(a);
	else
		return (0);
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
