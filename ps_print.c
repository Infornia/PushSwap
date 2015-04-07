/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 13:47:57 by mwilk             #+#    #+#             */
/*   Updated: 2014/11/08 14:12:04 by mwilk            ###   ########.fr       */
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

void	ps_print_piles(t_ps *a, t_ps *b, int *color)
{
	t_ps	*tmp;

	(void)color;
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
			pstr("\n\n");
		tmp = tmp->next;
	}
}
