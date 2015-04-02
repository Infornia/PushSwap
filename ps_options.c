/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_option.c			                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 15:48:12 by mwilk             #+#    #+#             */
/*   Updated: 2015/03/25 20:58:04 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"


int			chr_opt(char *opt, char c)
{
	if (!opt)
		return (0);
	while (*opt)
	{
		if (*opt == c)
			return (1);
		opt++;
	}
	return (0);
}

void		ps_option(t_data *d, char *s)
{
	int		opt;

	opt = 0;
	while (*(++s))
	{
		if (chr_opt(OPTS, *s))
		{
			if (!chr_opt(d->opts, *s))
			{
				d->opts[opt] = *s;
				opt += 1;
				if (*s <= '9' && *s >= '0')
					d->nb_color_opt++;
			}
		}
		else
			ps_error();
	}
	d->opts[opt] = '\0';
}
