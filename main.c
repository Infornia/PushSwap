/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 15:48:12 by mwilk             #+#    #+#             */
/*   Updated: 2015/04/29 09:40:24 by mwilk            ###   ########.fr       */
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
	//write(1, "\b\n", 2);
	return (0);
}
