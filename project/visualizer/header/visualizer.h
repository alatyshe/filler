/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 16:17:23 by alatyshe          #+#    #+#             */
/*   Updated: 2016/12/12 16:22:52 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZER_H
# define VISUALIZER_H
# define RED "\x1b[31m"
# define GREEN "\x1b[32m"
# define YELLOW "\x1b[33m"
# define BLUE "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN "\x1b[36m"
# define BLACK "\x1b[37m"
# define RESET "\x1b[0m"
# include "../../libft/header/libft.h"
# include "../../ft_printf/header/ft_printf.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct	s_filler
{
	char		**map;
	int			map_heigth;
	int			map_width;
	char		**figure;
	int			figure_heigth;
	int			figure_width;
	char		player_1;
	char		player_2;
	char		*name_1;
	char		*name_2;
	int			p1_counter;
	int			p2_counter;
	int			clean;
}				t_filler;

void			nulling_arrays(t_filler *lst);
void			print_map_figure(char **str, int len, t_filler *info);
void			ft_print_func(t_filler *info);
t_filler		*ft_lst_new_filler(void);
void			find_player(char *line, t_filler *lst);
void			get_map(t_filler *lst);
char			**get_figure(t_filler *lst, char *line);
int				str_compare(char *s1, char *s2);
int				find_char_from_end(char *str, char c);

#endif
