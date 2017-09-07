/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tactic.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:00:41 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/29 16:00:44 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/filler.h"

void			analyse_tactic(t_filler *lst)
{
	count_stars(lst);
	manhattan_distance(lst);
	lst->succes_pasting = new_figure();
	while (check_for_zeroes(lst))
		modify_distance(lst);
	find_max_distance(lst);
	find_shortest_way(lst);
	find_res(lst);
}

void			find_res(t_filler *lst)
{
	t_figure	*figure;
	t_figure	*res;

	figure = lst->succes_pasting;
	res = figure;
	while (figure->next)
	{
		if (res->summ > figure->summ)
			res = figure;
		figure = figure->next;
	}
	lst->res_x = res->x_res;
	lst->res_y = res->y_res;
}

static void		find_shortest_way_x(t_filler *lst,
	t_figure **figure, int y, int count)
{
	int			x;
	int			count_stars;

	x = 0;
	while (x < lst->map_width - 1)
	{
		if ((lst->map[y][x] == lst->my
			|| lst->map[y][x] == lst->my + 32)
			&& lst->distance_map[y][x] == count)
		{
			count_stars = 1;
			while (count_stars <= lst->count_stars)
			{
				find_star(lst, (*figure), count_stars);
				if (try_paste(lst, (*figure), y, x))
				{
					pasting(lst, (*figure), y, x);
					(*figure)->next = new_figure();
					(*figure) = (*figure)->next;
				}
				count_stars++;
			}
		}
		x++;
	}
}

void			find_shortest_way(t_filler *lst)
{
	int			y;
	int			count;
	t_figure	*figure;

	figure = lst->succes_pasting;
	count = 2;
	while (count < lst->distance_map_max)
	{
		y = 0;
		while (y < lst->map_heigth - 1)
		{
			find_shortest_way_x(lst, &figure, y, count);
			y++;
		}
		count++;
	}
}

void			find_star(t_filler *lst, t_figure *figure, int num_of_star)
{
	int			y;
	int			x;
	int			count;

	count = 0;
	y = 0;
	while (y < lst->figure_heigth)
	{
		x = 0;
		while (x < lst->figure_width)
		{
			if (lst->figure[y][x] == '*')
				count++;
			if (count == num_of_star)
			{
				figure->x_star = x;
				figure->y_star = y;
				return ;
			}
			x++;
		}
		y++;
	}
}
