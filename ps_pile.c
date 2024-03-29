/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_pile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 09:45:49 by mwilk             #+#    #+#             */
/*   Updated: 2015/04/29 09:45:55 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

t_ps	*ps_new(int nb)
{
	t_ps	*new;

	if (!(new = (t_ps *)malloc(sizeof(t_ps))))
		return (NULL);
	new->nb = nb;
	new->next = NULL;
	return (new);
}

void	ps_del(t_ps *h)
{
	t_ps	*tmp;

	while (h)
	{
		tmp = h;
		h = h->next;
		free(tmp);
		tmp = NULL;
	}
}

void	ps_front(t_ps **head, t_ps *new)
{
	if (!new)
		return ;
	if (*head == NULL)
		*head = new;
	else
	{
		new->next = *head;
		*head = new;
	}
}

void	ps_back(t_ps **head, t_ps *new)
{
	t_ps	*tmp;

	if (!new)
		return ;
	if (*head == NULL)
		*head = new;
	else
	{
		tmp = *head;
		while (tmp)
			tmp = tmp->next;
		tmp = new;
	}
}
