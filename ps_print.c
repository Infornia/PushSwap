/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 13:47:57 by mwilk             #+#    #+#             */
/*   Updated: 2015/06/11 19:51:53 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void			ps_pcolor(char *s, int color)
{
	pstr("\033[");
	pnbr(color);
	pstr("m");
	pstr(s);
	pstr("\033[0m");
}

void			ps_pmoves(int moves)
{
	pstr("\033[35m");
	pstr("You did: ");
	pnbr(moves);
	pstr(" Moves");
	pstr("\033[0m");
}

static void		print_help(t_ps *tmp, int color)
{
	while (tmp)
	{
		pnbr(tmp->nb);
		if (tmp->next)
			pstr(" ");
		else
			pstr("\n");
		tmp = tmp->next;
	}
	if (color)
		pstr("\033[0m");
}

int				ps_print_piles(t_data *d, t_ps *a, t_ps *b, int color)
{
	t_ps	*tmp;

	d->moves++;
	if (color && d->v)
	{
		tmp = a;
		if (tmp)
		{
			if (d->c)
				pstr("\033[31m");
			pstr("\b\nPile A: ");
			print_help(tmp, d->c);
		}
		tmp = b;
		if (tmp)
		{
			if (d->c)
				pstr("\033[36m");
			pstr("Pile B: ");
			print_help(tmp, d->c);
		}
	}
	return (1);
}
