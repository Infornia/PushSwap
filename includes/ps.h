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

/*
 ** Defines
*/

#define BLUE		36
#define PINK		35
#define OPTS		"12cv"
#define NB_OPTS		5
#define OPT_V		'v'
#define OPT_PINK	'1'
#define OPT_BLUE	'2'

/*
 ** Structures
*/

typedef struct			s_ps
{
	int				nb;
	struct s_ps		*next;
}						t_ps;

typedef struct			s_data
{
	char			opts[NB_OPTS + 1];
	int				color[3];
	int				nb_color_opt;
	int				nb_nbr;
}						t_data;

/*
 ** TT_Functions
*/

int			tt_atoi(const char *str);
int			tt_isspace(int c);
void		pstr(char *s);
void		pnbr(int nb);

/*
 ** Prints
*/

void		ps_pcolor(char *s, int color);
void		ps_print_piles(t_ps *a, t_ps *b, int *color);

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
t_ps		*ps_init(t_data *d, int ac, char **av);
void		sort(t_data *d, t_ps *a);
void		ps_error(void);

void		ps_option(t_data *d, char *s);
int			chr_opt(char *opt, char c);

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

/*
 ** Ps_Check
*/

int			check_sa(t_ps *pa);
int			check_ra(t_ps *pa);
int			check_rra(t_ps *pa);
int			check_pb(t_ps *pa);

int			check_sb(t_ps *pb);
int			check_rb(t_ps *pb);
int			check_rrb(t_ps *pb);
int			check_pa(t_ps *pb);
#endif /* !PS_H */
