/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 13:47:57 by mwilk             #+#    #+#             */
/*   Updated: 2015/04/20 21:11:45 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	ps_pcolor(char *s, int color)
{
	pstr("\033[");
	pnbr(color);
	pstr("m");
	pstr(s);
	pstr("\033[0m");
}

void	ps_pmoves(int moves, int color)
{
	pstr("\033[");
	pnbr(color);
	pstr("m");
	pstr("You did: ");
	pnbr(moves);
	pstr(" Moves");
	pstr("\033[0m");
}

void	ps_print_piles(t_data *d, t_ps *a, t_ps *b, int color)
{
	t_ps	*tmp;

	d->moves++;
	//pstr("\nMove : ");
	//pnbr(d->moves);
	//pstr("\n");
	if (color && chr_opt(d->opts, OPT_V))
	{
		tmp = a;
		if (tmp)
			pstr("\b\nPile A: ");
		while (tmp)
		{
			pnbr(tmp->nb);
			if (tmp->next)
				pstr(" ");
			else
				pstr("\n");
			tmp = tmp->next;
		}
		tmp = b;
		if (tmp)
			pstr("Pile B: ");
		while (tmp)
		{
			pnbr(tmp->nb);
			if (tmp->next)
				pstr(" ");
			else
				pstr("\n");
			tmp = tmp->next;
		}
	}
}
