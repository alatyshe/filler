/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:00:41 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/29 16:00:44 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/filler.h"

void			distance_map_zero(t_filler *lst)
{
	int			y;
	int			x;

	y = 0;
	while (y < lst->map_heigth)
	{
		x = 0;
		while (x < lst->map_width)
		{
			lst->distance_map[y][x] = 0;
			x++;
		}
		y++;
	}
}

int				**new_distance_map(t_filler *lst)
{
	int			**res;
	int			y;

	res = (int**)malloc(sizeof(int *) * lst->map_heigth);
	y = 0;
	while (y < lst->map_heigth)
	{
		res[y] = (int*)malloc(sizeof(int) * lst->map_width);
		y++;
	}
	return (res);
}

int				check_for_zeroes(t_filler *lst)
{
	int			x;
	int			y;

	y = 0;
	while (y < lst->map_heigth)
	{
		x = 0;
		while (x < lst->map_width)
		{
			if (lst->distance_map[y][x] == 0)
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}
