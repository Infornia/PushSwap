/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/21 20:37:29 by mwilk             #+#    #+#             */
/*   Updated: 2015/06/12 15:46:51 by mwilk            ###   ########.fr       */
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
	d->nb_nbr = 0;
	d->init = 0;
	d->special = 0;
	d->moves = 0;
	d->v = 0;
	d->n = 0;
	d->c = 0;
	d->yes = 0;
	d->stop = 0;
	d->count = 0;
}

static void	set_opt(t_data *d)
{
	if (chr_opt(d->opts, OPT_V))
		d->v = 1;
	if (chr_opt(d->opts, OPT_C))
		d->c = 1;
	if (chr_opt(d->opts, OPT_N))
		d->n = 1;
}

t_ps		*ps_init(t_data *d, int ac, char **av)
{
	t_ps	*a;
	int		nb;

	a = NULL;
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
			if (nb <= MIN_INT || nb > MAX_INT)
				ps_error();
			ps_front(&a, ps_new(nb));
			d->nb_nbr += 1;
			d->min = nb < d->min ? nb : d->min;
		}
	}
	set_opt(d);
	return (a);
}
