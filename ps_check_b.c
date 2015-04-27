/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check_b.c		                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 15:48:12 by mwilk             #+#    #+#             */
/*   Updated: 2015/04/27 21:32:50 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int		check_sb(t_ps *pb)
{
	t_ps	*b;
	t_ps	*last;

	b = pb;
	last = pb;
	while (last && last->next)
		last = last->next;
	if (b && b->next && b->nb < b->next->nb &&
			(b->nb > last->nb || last->nb == b->next->nb))
		return (1);
	return (0);
}

int		check_rrb(t_ps *pb)
{
	t_ps	*b;
	t_ps	*last;

	b = pb;
	last = pb;
	while (last && last->next)
		last = last->next;
	if (b && b->next && b->nb > b->next->nb && b->nb < last->nb)
		return (1);
	return (0);
}

int		check_rb(t_ps *pb)
{
	t_ps	*b;
	t_ps	*last;

	b = pb;
	last = pb;
	while (last && last->next)
		last = last->next;
	if (b && b->next && b->nb < b->next->nb && b->nb < last->nb)
		return (1);
	return (0);
}

int		magic_check_b(t_data *d, t_ps **pa, t_ps **pb)
{
	t_ps	*tmp;
	int		magic_a;
	int		plus;
	int		magic_b;

	magic_a = 0;
	plus = 0;
	magic_b = 0;
	tmp = *pa;
	if (*pa && *pb && (*pa)->nb < (*pb)->nb)
	{
		while (tmp && tmp->next && (*pb)->nb > tmp->nb)
		{
			magic_a++;
			tmp = tmp->next;
		}
		plus = magic_a;
		tmp = *pb;
		while (tmp && (*pa)->nb < tmp->nb)
		{
			magic_b++;
			tmp = tmp->next;
		}
		while (magic_a--)
		{
			ps_ra(pa);
			ps_print_piles(d, *pa, *pb, 1);
		}
		while (magic_b || plus)
		{
			tmp = get_last(*pa);
			if (*pb && (*pb)->nb > tmp->nb)
			{
				ps_pa(pa, pb);
				ps_print_piles(d, *pa, *pb, 1);
				magic_b--;
			}
			else
			{
				ps_rra(pa);
				ps_print_piles(d, *pa, *pb, 1);
				plus--;
			}
		}
		return (1);
	}
	return (0);
}

int		check_pa(t_ps *pb)
{
	t_ps	*b;
	t_ps	*last;

	b = pb;
	last = pb;
	if (b && !(b->next))
		return (1);
	while (last && last->next)
		last = last->next;
	if (!b->next || (b->nb > b->next->nb && b->nb > last->nb))
		return (1);
	return (0);
}
