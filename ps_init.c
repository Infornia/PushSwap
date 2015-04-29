/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/21 20:37:29 by mwilk             #+#    #+#             */
/*   Updated: 2015/04/29 09:44:24 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static void	ini_opt(t_data *d)
{
	int		i;

	i = -1;
	while (++i < NB_OPTS)
		d->opts[i] = '\0';
	d->color[0] = 0;
	d->color[1] = PINK;
	d->color[2] = BLUE;
	d->color[3] = GREEN;
	d->nb_color_opt = 0;
	d->nb_nbr = 0;
	d->special = 0;
	d->moves = 0;
}

t_ps		*ps_init(t_data *d, int ac, char **av)
{
	t_ps	*a;
	int		nb;

	a = NULL;
	if (ac < 1)
		ps_error();
	ini_opt(d);
	d->min = 2147483647;
	while (--ac > 0)
	{
		if (av[ac][0] == '-' && av[ac][1] <= 'z' && av[ac][1] >= 'a')
			ps_option(d, av[ac]);
		else if (ps_error_letter(av[ac]))
			ps_error();
		else
		{
			nb = tt_atoi(av[ac]);
			ps_front(&a, ps_new(nb));
			d->nb_nbr += 1;
			d->min = nb < d->min ? nb : d->min;
		}
	}
	if (chr_opt(d->opts, OPT_V))
		d->v = 1;
	return (a);
}
