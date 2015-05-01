/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 15:48:12 by mwilk             #+#    #+#             */
/*   Updated: 2015/05/01 20:23:30 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int		main(int ac, char **av)
{
	t_data	d;
	t_ps	*a;
	t_ps	*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		ps_error_usage();
	a = ps_init(&d, ac, av);
	ps_error_number(d, a);
	sort_a(&d, a, b);
	if (chr_opt(d.opts, OPT_N))
		ps_pmoves(d.moves, d.color[3]);
	return (0);
}
