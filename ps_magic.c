/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_magic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/20 19:54:11 by mwilk             #+#    #+#             */
/*   Updated: 2015/05/04 18:28:38 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static void		izero(int magic[3])
{
	magic[0] = 0;
	magic[1] = 0;
	magic[2] = 0;
}

int				magic_check_a(t_data *d, t_ps *pa, t_ps *pb)
{
	(void)d;
	if (pa && pb && pb->next && pa->nb < pb->nb)
		return (1);
	return (0);
}

int				magic_check_b(t_data *d, t_ps *pa, t_ps *pb)
{
	(void)d;
	if (pa && pb && (pa)->nb < (pb)->nb)
		return (1);
	return (0);
}

void			magic_a(t_data *d, t_ps **pa, t_ps **pb)
{
	int		rb_pb_rrb[3];
	t_ps	*tmp;

	izero(rb_pb_rrb);
	tmp = *pb;
	while (tmp && (*pa)->nb < tmp->nb && ++(rb_pb_rrb[0]))
		tmp = tmp->next;
	rb_pb_rrb[2] = rb_pb_rrb[0];
	tmp = *pa;
	while (tmp && (*pb)->nb > tmp->nb && ++(rb_pb_rrb[1]))
		tmp = tmp->next;
	while ((rb_pb_rrb[0])--)
		ps_print_piles(d, *pa, *pb, ps_rb(pb));
	while (rb_pb_rrb[1] || rb_pb_rrb[2])
	{
		tmp = get_last(*pb);
		if (*pa && ((*pa)->nb < tmp->nb || (*pa)->nb > tmp->nb) &&
				ps_print_piles(d, *pa, *pb, ps_pb(pa, pb)) &&
				check_post_pb(d, pa, pb, 0))
			(rb_pb_rrb[1])--;
		else if (rb_pb_rrb[2] && ps_rrb(pb) && ps_print_piles(d, *pa, *pb, 1))
			(rb_pb_rrb[2])--;
		else
			break ;
	}
}

void			magic_b(t_data *d, t_ps **pa, t_ps **pb)
{
	int		ra_pa_rra[3];
	t_ps	*tmp;

	izero(ra_pa_rra);
	tmp = *pa;
	while (tmp && (*pb)->nb > tmp->nb && ++(ra_pa_rra[0]))
		tmp = tmp->next;
	ra_pa_rra[2] = ra_pa_rra[0];
	tmp = *pb;
	while (tmp && (*pa)->nb < tmp->nb && ++(ra_pa_rra[1]))
		tmp = tmp->next;
	while ((ra_pa_rra[0])--)
		ps_print_piles(d, *pa, *pb, ps_ra(pa));
	while (ra_pa_rra[1] || ra_pa_rra[2])
	{
		tmp = get_last(*pa);
		if (*pb && ((*pb)->nb > tmp->nb || (*pa)->nb < tmp->nb) &&
				ps_print_piles(d, *pa, *pb, ps_pa(pa, pb)) &&
				check_post_pa(d, pa, pb, 0))
			(ra_pa_rra[1])--;
		else if (ra_pa_rra[2] && ps_print_piles(d, *pa, *pb, ps_rra(pa)))
			(ra_pa_rra[2])--;
		else
			break ;
	}
}
