/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 15:48:12 by mwilk             #+#    #+#             */
/*   Updated: 2015/04/29 09:59:09 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static int		ps_ok(t_ps *a, t_ps *b)
{
	t_ps	*tmp;

	tmp = a;

	if (b)
		return (0);
	while (tmp && tmp->next)
	{
		if (tmp->nb > tmp->next->nb)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int				ok_ab(t_ps *p)
{
	t_ps	*tmp;

	tmp = p;
	while (tmp && tmp->next)
	{
		if (tmp->nb > tmp->next->nb)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static int		sort_b(t_data *d, t_ps **a, t_ps **b)
{
	int	work;

	work = 1;
	//pstr("Fin tri de a\n");
	while ((*b && ok_ab(*b)) || !ok_ab(*b))
	{
		if (check_sb(*b))
			ps_sb(b);
		else if (check_rb(*b))
			ps_rb(b);
		else if (check_rrb(*b))
			ps_rrb(b);
		else if (magic_check_b(d, *a, *b))
			magic_b(d, a, b);
		else if (check_pa(*b))
		{
			ps_pa(a, b);
			check_post_pa(d, a, b, 1);
		}
		else
			work--;
		work++;
		ps_print_piles(d, *a, *b, 1);
	}
	if (ps_ok(*a, *b) || work)
	{
		//ps_pcolor("\n\nSUCCESSFULL!!!!!!!!\n", d->color[1]);
		return (1);
	}
	return (0);
}

void			sort_a(t_data *d, t_ps *a, t_ps *b)
{
	while (!ps_ok(a, b))
	{
		if (ok_ab(a) && sort_b(d, &a, &b) && ok_ab(a))
			break ;
		else if (check_sa(d, a))
			ps_sa(&a);
		else if (check_ra(d, a))
			ps_ra(&a);
		else if (check_pb(d, a))
		{
			ps_pb(&a, &b);
			ps_print_piles(d, a, b, 1);
			check_post_pb(d, &a, &b, 1);
		}
		else if (check_rra(d, a))
			ps_rra(&a);
		else if (magic_check_a(d, a, b))
			magic_b(d, &a, &b);
		ps_print_piles(d, a, b, 1);
		//pstr("The head\n");
		//pnbr(a->nb);
		//pstr("\n");
	}
	//	ps_pcolor("\nYOU'RE THE BEST MY LORD\n", d->color[2]);
	if (chr_opt(d->opts, OPT_N))
		ps_pmoves(d->moves, d->color[3]);
	ps_del(a);
}
