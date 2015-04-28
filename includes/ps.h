/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 15:48:12 by mwilk             #+#    #+#             */
/*   Updated: 2015/04/28 17:31:47 by mwilk            ###   ########.fr       */
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
#define GREEN		34
#define OPTS		"123cnv"
#define NB_OPTS		7
#define OPT_V		'v'
#define OPT_N		'n'
#define OPT_PINK	'1'
#define OPT_BLUE	'2'
#define OPT_GREEN	'3'

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
	int				color[4];
	int				v;
	int				min;
	int				moves;
	int				nb_color_opt;
	int				nb_nbr;
	int				special;
}						t_data;

/*
 ** TT_Functions
*/

int			tt_atoi(const char *str);
int			tt_isspace(int c);
void		pstr(char *s);
void		pnbr(int nb);
t_ps		*get_last(t_ps *h);

/*
 ** Errors
*/

void		ps_error(void);
void		ps_error_usage(void);
void		ps_error_number(t_data d, t_ps *a);
int			ps_error_letter(char *s);
void		ps_option_error(char c);

/*
 ** Prints
*/

void		ps_pcolor(char *s, int color);
void		ps_pmoves(int moves, int color);
void		ps_print_piles(t_data *d, t_ps *a, t_ps *b, int color);

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
void		sort_a(t_data *d, t_ps *a, t_ps *b);
int			ok_ab(t_ps *p);

void		ps_option(t_data *d, char *s);
int			chr_opt(char *opt, char c);

int			ps_pa(t_ps **a, t_ps **b);
int			ps_pb(t_ps **a, t_ps **b);

int			ps_ss(t_ps **a, t_ps **b);
int			ps_sa(t_ps **a);
int			ps_sb(t_ps **b);

int			ps_rr(t_ps **a, t_ps **b);
int			ps_ra(t_ps **a);
int			ps_rb(t_ps **b);

int			ps_rrr(t_ps **a, t_ps **b);
int			ps_rra(t_ps **a);
int			ps_special_rra(t_data *d, t_ps **a, int min);
int			ps_rrb(t_ps **b);

void		magic_a(t_data *d, t_ps **pa, t_ps **pb);
void		magic_b(t_data *d, t_ps **pa, t_ps **pb);

/*
 ** Ps_Check
*/
int			check_post_pa(t_data *d, t_ps **a, t_ps **b, int go);
int			check_post_pb(t_data *d, t_ps **a, t_ps **b, int go);

int			check_sa(t_data *d, t_ps *pa);
int			check_ra(t_data *d, t_ps *pa);
int			check_rra(t_data *d, t_ps *pa);
//int			special_check_a(t_data *d, t_ps **pa);
int			magic_check_a(t_data *d, t_ps *pa, t_ps *pb);
int			check_pb(t_data *d, t_ps *pa);

int			check_sb(t_ps *pb);
int			check_rb(t_ps *pb);
int			check_rrb(t_ps *pb);
int			magic_check_b(t_data *d, t_ps *pa, t_ps *pb);
int			check_pa(t_ps *pb);
#endif /* !PS_H */
