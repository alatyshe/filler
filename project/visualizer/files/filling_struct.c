/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filling_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:00:41 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/29 16:00:44 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/visualizer.h"

t_filler		*ft_lst_new_filler(void)
{
	t_filler	*lst;

	lst = (t_filler *)malloc(sizeof(t_filler));
	lst->map = NULL;
	lst->map_heigth = 0;
	lst->map_width = 0;
	lst->figure = NULL;
	lst->figure_heigth = 0;
	lst->figure_width = 0;
	lst->player_1 = 0;
	lst->player_2 = 0;
	lst->name_1 = NULL;
	lst->name_2 = NULL;
	lst->p1_counter = 0;
	lst->p2_counter = 0;
	lst->clean = 0;
	return (lst);
}

void			find_player(char *line, t_filler *lst)
{
	int			n;

	lst->player_1 = (str_compare(line, "p1")) ? 'O' : 'X';
	n = find_char_from_end(line, '/') + 1;
	if (!lst->name_2)
	{
		lst->name_2 = ft_strdup(line + n);
		n = ft_strlen(lst->name_2);
		lst->name_2[n - 1] = '\0';
	}
	else if (!lst->name_1)
	{
		lst->name_1 = ft_strdup(line + n);
		n = ft_strlen(lst->name_1);
		lst->name_1[n - 1] = '\0';
	}
	lst->player_2 = (lst->player_1 == 'O') ? 'X' : 'O';
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
		lst->map_width = ft_strlen(lst->map[0]);
	lst->map[i] = 0;
}

char			**get_figure(t_filler *lst, char *line)
{
	int			i;
	char		**res;

	i = 0;
	lst->figure_heigth = ft_atoi(line + 5);
	res = (char **)malloc(sizeof(char *) * lst->figure_heigth);
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
