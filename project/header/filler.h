/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 16:17:23 by alatyshe          #+#    #+#             */
/*   Updated: 2016/12/12 16:22:52 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# define RED "\x1b[31m"
# define GREEN "\x1b[32m"
# define YELLOW "\x1b[33m"
# define BLUE "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN "\x1b[36m"
# define BLACK "\x1b[37m"
# define RESET "\x1b[0m"
# include "../libft/header/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct			s_coordinates
{
	int					y;
	int					x;
	int					y1;
	int					x1;
	int					y0;
	int					x0;
	int					count;
}						t_coord;

typedef struct			s_figure
{
	int					y_map;
	int					x_map;
	int					y_star;
	int					x_star;
	int					y_res;
	int					x_res;
	int					summ;
	struct s_figure		*next;
}						t_figure;

typedef struct			s_filler
{
	char				**map;
	char				**old_map;
	int					**distance_map;
	int					distance_map_max;
	int					map_heigth;
	int					map_width;
	char				**figure;
	int					figure_heigth;
	int					figure_width;
	int					count_stars;
	char				my;
	char				enemy;
	int					res_x;
	int					res_y;
	t_figure			*succes_pasting;
}						t_filler;

/*
**	new_struct
*/
t_filler				*new_filler(void);
t_figure				*new_figure(void);
/*
**	get_info
*/
void					find_player(char *line, t_filler *lst);
void					get_map(t_filler *lst);
char					**get_figure(t_filler *lst, char *line);
int						str_compare(char *s1, char *s2);
/*
**	print
*/
void					print_func(t_filler *info);
void					print_res(t_filler *lst);
void					count_stars(t_filler *lst);
/*
**	tactic
*/
void					find_star(t_filler *lst,
	t_figure *figure, int num_of_star);
void					analyse_tactic(t_filler *lst);
void					find_shortest_way(t_filler *lst);
void					find_res(t_filler *lst);
/*
**	pasting
*/
int						try_paste(t_filler *lst,
	t_figure *figure, int y0, int x0);
int						pasting(t_filler *lst,
	t_figure *figure, int y0, int x0);
/*
**	nulling
*/
void					nulling_figure(t_figure *lst);
void					nulling_array(void **str, int len);
void					nulling_arrays(t_filler *lst);
/*
**	manhattan_distance
*/
void					find_max_distance(t_filler *lst);
void					distance_map_zero(t_filler *lst);
int						**new_distance_map(t_filler *lst);
void					manhattan_distance(t_filler *lst);
int						find_min_num(t_filler *lst, int	y, int x);
void					modify_distance_2(t_filler *lst, int y);
void					modify_distance(t_filler *lst);
int						check_for_zeroes(t_filler *lst);
/*
**	read
*/
int						ft_for_read(const int fd, char **line, int del);
#endif
