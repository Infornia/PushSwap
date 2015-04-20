/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 15:48:12 by mwilk             #+#    #+#             */
/*   Updated: 2015/04/20 20:10:43 by mwilk            ###   ########.fr       */
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

static int		ok_ab(t_ps *pile)
{
	t_ps	*tmp;

	tmp = pile;
	while (tmp && tmp->next)
	{
		if (tmp->nb > tmp->next->nb)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static int		sort_b(t_data *d, t_ps *a, t_ps *b)
{
	pstr("\nFin tri de a\n\n");
	while ((b && ok_ab(b)) || !ok_ab(b))
	{
		if (magic_check_b(d, &a, &b))
			;
		else if (check_sb(b))
			ps_sb(&b);
		else if (check_rb(b))
			ps_rb(&b);
		else if (check_rrb(b))
			ps_rrb(&b);
		else if (check_pa(b))
		{
			ps_pa(&a, &b);
			check_post_pa(d, a, b);
		}
		ps_print_piles(d, a, b, 1);
	}
	if (ps_ok(a, b))
	{
	//	ps_pcolor("\n\nSUCCESSFULL!!!!!!!!\n", d->color[1]);
		return (1);
	}
	return (0);
}

void			sort_a(t_data *d, t_ps *a, t_ps *b)
{
	while (!ps_ok(a, b))
	{
		if (ok_ab(a) && sort_b(d, a, b))
			break;
		else if (check_sa(d, a))
			ps_sa(&a);
		else if (check_ra(d, a))
			ps_ra(&a);
		else if (check_rra(d, a))
			ps_rra(&a);
		else if (magic_check_a(d, &a))
			;
		else if (check_pb(a))
		{
			ps_pb(&a, &b);
			ps_print_piles(d, a, b, 1);
			check_post_pb(d, a, b);
		}
		ps_print_piles(d, a, b, 1);
	}
	if (ps_ok(a, NULL))
		ps_pcolor("\nYOU'RE THE BEST MY LORD\n", d->color[2]);
	if (chr_opt(d->opts, OPT_N))
		ps_pmoves(d->moves, d->color[3]);
	ps_del(a);
}

t_ps	*ps_init(t_data *d, int ac, char **av)
{
	t_ps	*a;
	int		i;

	a = NULL;
	d->nb_color_opt = 0;
	d->nb_nbr = 0;
	d->special = 0;
	d->moves = 0;
	i = -1;
	while (++i < NB_OPTS)
		d->opts[i] = '\0';
	if (ac < 1)
		ps_error();
	while (--ac > 0)
	{
		if (av[ac][0] == '-' && av[ac][1] <= 'z' && av[ac][1] >= 'a')
			ps_option(d, av[ac]);
		else if (ps_error_letter(av[ac]))
			ps_error();
		else
		{
			ps_front(&a, ps_new(tt_atoi(av[ac])));
			d->nb_nbr += 1;
		}
	}
	if (chr_opt(d->opts, OPT_V))
		d->v = 1;
	d->color[0] = 0;
	d->color[1] = PINK;
	d->color[2] = BLUE;
	d->color[3] = GREEN;
	return (a);
}
