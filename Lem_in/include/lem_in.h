/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpozniak <vpozniak@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 18:26:04 by vpozniak          #+#    #+#             */
/*   Updated: 2019/06/12 18:26:07 by vpozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_LEM_IN_H
# define LEM_IN_LEM_IN_H
# define P1  "\e[0;35mL%d-%s  \e[0m"
# define P2  "\e[0;35mL%d-%s \e[0m"
# include "../libft/libft.h"

typedef struct s_rooms	t_rooms;
typedef struct s_room	t_room;
typedef struct s_puti	t_puti;

struct			s_room
{
	int			ant;
	int			bizi;
	int			visit;
	int			cor[2];
	char		*name;
	t_room		*relatives;
	t_rooms		*links;
};

struct			s_rooms
{
	t_room		**rooms;
	ssize_t		len;
	ssize_t		max;
};

struct			s_puti
{
	t_rooms		**paths;
	ssize_t		len;
	ssize_t		max;
};

t_rooms			*g_graph;
t_rooms			*g_output;
t_rooms			*g_order;
t_rooms			*g_ants_col;
t_room			*g_start;
t_puti			*g_puti;
t_room			*g_end;
t_rooms			*g_output;
char			*g_x;
int				g_col;
int				g_mv;
int				g_i;
int				g_start_point;
int				g_end_point;
int				g_num[1];

void			pars();
void			print(void);
void			path(void);
void			output(void);
void			strakt(void);
void			print_end(void);
void			print_stat(void);
void			error(char *str);
void			valid_cor(char *arr);
void			move(int ac);
void			valid_l(char *line);
int				check_sym(char *line, char s);
t_room			*find_room(char *name);
t_room			*find_room(char *name);

#endif
