/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 09:51:58 by mwilk             #+#    #+#             */
/*   Updated: 2015/06/11 18:18:13 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	pchar(char c)
{
	write(1, &c, 1);
}

void	pstr(char *s)
{
	while (*s)
		write(1, &(*s++), 1);
}

void	pnbr(int n)
{
	if (n < 0)
	{
		pchar('-');
		n *= -1;
	}
	if (n >= 10)
	{
		pnbr(n / 10);
		pnbr(n % 10);
	}
	else
		pchar(n + '0');
}

int		tt_isspace(int c)
{
	c = (unsigned char)c;
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
			|| c == ' ')
		return (1);
	return (0);
}

int		tt_atoi(const char *str)
{
	int		sign;
	int		result;

	result = 0;
	sign = 1;
	while (tt_isspace(*str))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - 48;
		str++;
	}
	return (result * sign);
}
