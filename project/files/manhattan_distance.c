/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manhattan_distance.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:00:41 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/29 16:00:44 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/filler.h"

void			find_max_distance(t_filler *lst)
{
	int			x;
	int			y;
	int			temp;

	temp = 0;
	y = 0;
	while (y < lst->map_heigth - 1)
	{
		x = 0;
		while (x < lst->map_width - 1)
		{
			if (temp < lst->distance_map[y][x])
				temp = lst->distance_map[y][x];
			x++;
		}
		y++;
	}
	lst->distance_map_max = temp;
}

void			manhattan_distance(t_filler *lst)
{
	char		**old_map;
	int			x;
	int			y;

	old_map = (lst->old_map == NULL) ? lst->map : lst->old_map;
	y = 0;
	while (y < lst->map_heigth)
	{
		x = -1;
		while (x++ < lst->map_width - 1)
		{
			if ((lst->map[y][x] == lst->enemy && old_map[y][x] == lst->enemy)
				|| lst->map[y][x] == lst->enemy + 32)
				lst->distance_map[y][x] = (lst->map_width > 20) ? 10 : 1;
			else if (lst->map[y][x] == lst->enemy
				&& old_map[y][x] != lst->enemy)
				lst->distance_map[y][x] = 1;
			else
				lst->distance_map[y][x] = 0;
		}
		y++;
	}
}

void			fill_distance_map(t_filler *lst, int find)
{
	int			x;
	int			y;

	y = 0;
	while (y < lst->map_heigth)
	{
		x = 0;
		while (x < lst->map_width)
		{
			if (lst->distance_map[y][x] == find)
			{
				if (y + 1 < lst->map_heigth && lst->distance_map[y + 1][x] == 0)
					lst->distance_map[y + 1][x] = lst->distance_map[y][x] + 1;
				if (y - 1 >= 0 && lst->distance_map[y - 1][x] == 0)
					lst->distance_map[y - 1][x] = lst->distance_map[y][x] + 1;
				if (x + 1 < lst->map_width && lst->distance_map[y][x + 1] == 0)
					lst->distance_map[y][x + 1] = lst->distance_map[y][x] + 1;
				if (x - 1 >= 0 && lst->distance_map[y][x - 1] == 0)
					lst->distance_map[y][x - 1] = lst->distance_map[y][x] + 1;
			}
			x++;
		}
		y++;
	}
}

void			modify_distance(t_filler *lst)
{
	int			find;

	find = 1;
	while (check_for_zeroes(lst))
	{
		fill_distance_map(lst, find);
		find++;
	}
}
