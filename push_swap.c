/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 15:48:12 by mwilk             #+#    #+#             */
/*   Updated: 2015/03/25 20:58:04 by mwilk            ###   ########.fr       */
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

void			sort(t_data *d, t_ps *a)
{
	t_ps	*b;

	b = NULL;
	while (!ps_ok(a, b))
	{
		if (ok_ab(a))
		{
			pstr("\nFin tri de a\n\n");
			while ((b && ok_ab(b)) || !ok_ab(b))
			{
				if (check_pa(b))
				{
					ps_pa(&a, &b);
					if (check_sa(d, a))
						check_sb(b) ? ps_ss(&a, &b) : ps_sa(&a);
					else if (check_ra(d, a))
						check_rb(b) ? ps_rr(&a, &b) : ps_ra(&a);
					else if (check_rra(d, a))
						check_rrb(b) ? ps_rrr(&a, &b) : ps_rra(&a);
				}
				else if (check_sb(b))
					ps_sb(&b);
				else if (check_rb(b))
					ps_rb(&b);
				else if (check_rrb(b))
					ps_rrb(&b);
				if (chr_opt(d->opts, OPT_V))
					ps_print_piles(a, b, d->color);
			}
			break;
		}
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
			if (b->next && check_sb(b))
				check_sa(d, a) ? ps_ss(&a, &b) : ps_sb(&b);
			else if (b->next && check_rb(b))
				check_ra(d, a) ? ps_rr(&a, &b) : ps_rb(&b);
			else if (b->next && check_rrb(b))
				check_rra(d, a) ? ps_rrr(&a, &b) : ps_rrb(&b);
		}
		if (chr_opt(d->opts, OPT_V))
			ps_print_piles(a, b, d->color);
	}
	if (ps_ok(a, b))
		ps_pcolor("\nSUCCESSFULL!!!!!!!!\n", d->color[1]);
	ps_del(a);
}
t_ps	*ps_init(t_data *d, int ac, char **av)
{
	t_ps	*a;
	int		i;

	i = -1;
	a = NULL;
	d->nb_color_opt = 0;
	d->nb_nbr = 0;
	d->special = 0;
	while (++i < NB_OPTS)
		d->opts[i] = '\0';
	if (ac < 1)
		ps_error();
	while (--ac > 0)
	{
		if (av[ac][0] == '-' && av[ac][1] <= 'z' && av[ac][1] >= 'a')
			ps_option(d, av[ac]);
		else
		{
			ps_front(&a, ps_new(tt_atoi(av[ac])));
			d->nb_nbr += 1;
		}
	}
	d->color[0] = 0;
	d->color[1] = PINK;
	d->color[2] = BLUE;
	return (a);
}
