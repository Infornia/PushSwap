/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 15:48:12 by mwilk             #+#    #+#             */
/*   Updated: 2015/03/25 20:58:04 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_H
# define PS_H

#include <unistd.h>
#include <stdlib.h>

typedef struct			s_ps
{
	int				nb;
	struct s_ps		*next;
}						t_ps;

/*
 ** TT_Functions
*/

int			tt_atoi(const char *str);
int			tt_isspace(int c);

/*
 ** Chain_list
*/

t_ps		*ps_new(int nb);
void		ps_del(t_ps *head);
void		ps_front(t_ps **head, t_ps *new);
void		ps_back(t_ps **head, t_ps *new);

/*
 ** Ps_Functions
*/

void		ps_pa(t_ps **a, t_ps **b);
void		ps_pb(t_ps **a, t_ps **b);

void		ps_ss(t_ps **a, t_ps **b);
int			ps_sa(t_ps **a);
int			ps_sb(t_ps **b);

int			ps_rr(t_ps **a, t_ps **b);
int			ps_ra(t_ps **a);
int			ps_rb(t_ps **b);

int			ps_rrr(t_ps **a, t_ps **b);
int			ps_rra(t_ps **a);
int			ps_rrb(t_ps **b);

#endif /* !PS_H */
