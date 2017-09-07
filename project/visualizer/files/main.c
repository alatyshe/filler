/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:00:41 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/29 16:00:44 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/visualizer.h"

int				find_char_from_end(char *str, char c)
{
	int			i;

	i = ft_strlen(str);
	while (i > 0)
	{
		if (str[i] == c)
			return (i);
		i--;
	}
	return (0);
}

void			print_vinner(t_filler *lst)
{
	int			i;

	i = 0;
	ft_printf("\n\n%sWINNER WINNER WINNER - %s", MAGENTA, RESET);
	if (lst->p1_counter > lst->p2_counter)
		ft_printf("%s            \n\n\n", lst->name_1);
	else
		ft_printf("%s            \n\n\n", lst->name_2);
}

char			*ft_newstring(int len)
{
	char		*res;
	int			i;

	i = 0;
	res = (char*)malloc(sizeof(char) * len + 1);
	while (i < len)
		res[i++] = ' ';
	res[i] = '\0';
	return (res);
}

void			ft_cleaning(t_filler *info)
{
	int				height;
	int				width;
	char			*str;
	int				i;

	i = 0;
	width = info->map_width * 4;
	height = info->map_heigth + 20;
	str = ft_newstring(width);
	ft_printf("\033[6;0H");
	while (i < height)
	{
		ft_printf("%s\n", str);
		i++;
	}
	free(str);
}

int				main(void)
{
	char		*line;
	t_filler	*lst;

	lst = ft_lst_new_filler();
	while (get_next_line(0, &line) > 0)
	{
		if (line[0] == '$' && str_compare(line, "$$$"))
			find_player(line, lst);
		if (str_compare(line, "Plateau"))
		{
			if (lst->map_heigth == 0)
				lst->map_heigth = ft_atoi(line + 7);
			get_map(lst);
		}
		if (str_compare(line, "Piece"))
			lst->figure = get_figure(lst, line);
		if (str_compare(line, "<got"))
		{
			line[6] == lst->player_1 ? lst->p1_counter++ : lst->p2_counter++;
			lst->clean++ == 0 ? ft_cleaning(lst) : 0;
			ft_print_func(lst);
		}
	}
	print_vinner(lst);
	return (0);
}
