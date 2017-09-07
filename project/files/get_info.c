/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:00:41 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/29 16:00:44 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/filler.h"

void			find_player(char *line, t_filler *lst)
{
	int			n;

	n = 0;
	lst->my = (str_compare(line, "1")
		&& !str_compare((line + 15), ".filler")) ? 'O' : 'X';
	lst->enemy = (lst->my == 'O') ? 'X' : 'O';
	free(line);
}

void			get_map(t_filler *lst)
{
	int			i;
	char		*line;

	i = 0;
	lst->map = (char **)malloc(sizeof(char *) * lst->map_heigth + 1);
	get_next_line(0, &line);
	free(line);
	while (i < lst->map_heigth)
	{
		get_next_line(0, &line);
		lst->map[i] = ft_strdup((line + 4));
		free(line);
		i++;
	}
	if (lst->map_width == 0)
	{
		lst->map_width = ft_strlen(lst->map[0]);
		lst->distance_map = new_distance_map(lst);
		distance_map_zero(lst);
	}
	lst->map[i] = 0;
}

char			**get_figure(t_filler *lst, char *line)
{
	int			i;
	char		**res;

	i = 0;
	lst->figure_heigth = ft_atoi(line + 5);
	res = (char **)malloc(sizeof(char *) * lst->figure_heigth + 1);
	while (i < lst->figure_heigth)
	{
		get_next_line(0, &line);
		res[i] = ft_strdup(line);
		i++;
		free(line);
	}
	if (res[0])
		lst->figure_width = ft_strlen(res[0]);
	return (res);
}

int				str_compare(char *s1, char *s2)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (s1[i + j] && (s1[i + j] != '\0' && s2[j] != '\0'))
	{
		j = 0;
		while (s1[j + i] == s2[j])
		{
			if (s2[j + 1] == '\0')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void			count_stars(t_filler *lst)
{
	int			y;
	int			x;
	int			count;

	y = 0;
	count = 0;
	while (y < lst->figure_heigth)
	{
		x = 0;
		while (x < lst->figure_width)
		{
			if (lst->figure[y][x] == '*')
				count++;
			x++;
		}
		y++;
	}
	lst->count_stars = count;
}
