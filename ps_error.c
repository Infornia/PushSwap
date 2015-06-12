/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 15:48:12 by mwilk             #+#    #+#             */
/*   Updated: 2015/06/12 14:40:58 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	ps_error(void)
{
	write(1, "Error\n", 6);
	exit(0);
}

void	ps_error_usage(void)
{
	pstr("\nUsage: ./push_swap [-");
	pstr(OPTS);
	pstr("]... [number 1] [number 2] ...\n");
	exit(0);
}

void	ps_option_error(char c)
{
	pstr("PushSwap: invalid option -- -");
	pchar(c);
	ps_error_usage();
}

int		ps_error_letter(char *s)
{
	while (*s)
	{
		if ((*s < '0' && *s != '-') || *s > '9')
			return (1);
		++s;
	}
	return (0);
}

void	ps_error_number(t_data d, t_ps *a)
{
	t_ps	*tmp;
	int		nb_tab[d.nb_nbr + 1];
	int		i;

	tmp = a;
	i = -1;
	while (++i <= d.nb_nbr + 1)
		nb_tab[i] = '\0';
	while (tmp)
	{
		i = 0;
		while (nb_tab[i])
		{
			if (nb_tab[i] == tmp->nb)
				ps_error();
			i++;
		}
		nb_tab[i] = tmp->nb;
		tmp = tmp->next;
	}
}
