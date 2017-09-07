/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pasting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:00:41 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/29 16:00:44 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/filler.h"

static void		fill_coordinates(t_coord *c, t_figure *figure, int y0, int x0)
{
	c->y = -figure->y_star;
	c->x = -figure->x_star;
	c->y1 = 0;
	c->x1 = 0;
	c->x0 = x0;
	c->y0 = y0;
	c->count = 0;
}

static int		try_paste_1(t_filler *lst, t_figure *figure, t_coord *c)
{
	c->x = 0 - figure->x_star;
	c->x1 = 0;
	while (c->x < lst->figure_width - figure->x_star && c->x + c->x0 >= 0)
	{
		if ((lst->figure_width - figure->x_star) + c->x0 > lst->map_width)
			return (0);
		if ((lst->figure_heigth - figure->y_star) + c->y0 > lst->map_heigth)
			return (0);
		if (lst->figure[c->y1][c->x1] == '*'
			&& (lst->map[c->y0 + c->y][c->x0 + c->x] == lst->enemy
			|| lst->map[c->y0 + c->y][c->x0 + c->x] == lst->enemy + 32))
			return (0);
		if (lst->figure[c->y1][c->x1] == '*'
			&& (lst->map[c->y0 + c->y][c->x0 + c->x] == lst->my
			|| lst->map[c->y0 + c->y][c->x0 + c->x] == lst->my + 32))
		{
			c->count++;
			if (c->count >= 2)
				return (0);
		}
		c->x1++;
		c->x++;
	}
	return (1);
}

int				try_paste(t_filler *lst, t_figure *figure, int y0, int x0)
{
	t_coord		c;

	fill_coordinates(&c, figure, y0, x0);
	while (c.y < lst->figure_heigth - figure->y_star && c.y + c.y0 >= 0)
	{
		if (!try_paste_1(lst, figure, &c))
			return (0);
		c.y1++;
		c.y++;
	}
	if (c.x == lst->figure_width - figure->x_star
		&& c.y == lst->figure_heigth - figure->y_star)
		return (1);
	return (0);
}

static int		pasting_1(t_filler *lst, t_figure *figure, t_coord *c)
{
	while (c->x < lst->figure_width - figure->x_star && c->x + c->x0 >= 0)
	{
		if ((lst->figure_width - figure->x_star) + c->x0 > lst->map_width)
			return (0);
		if ((lst->figure_heigth - figure->y_star) + c->y0 > lst->map_heigth)
			return (0);
		if (lst->figure[c->y1][c->x1] == '*'
			&& (lst->map[c->y0 + c->y][c->x0 + c->x] == lst->enemy
			|| lst->map[c->y0 + c->y][c->x0 + c->x] == lst->enemy + 32))
			return (0);
		if (lst->figure[c->y1][c->x1] == '*'
			&& (lst->map[c->y0 + c->y][c->x0 + c->x] == lst->my
			|| lst->map[c->y0 + c->y][c->x0 + c->x] == lst->my + 32))
		{
			c->count++;
			if (c->count >= 2)
				return (0);
		}
		if (lst->figure[c->y1][c->x1] == '*')
			figure->summ += lst->distance_map[c->y0 + c->y][c->x0 + c->x];
		c->x1++;
		c->x++;
	}
	return (1);
}

int				pasting(t_filler *lst, t_figure *figure, int y0, int x0)
{
	t_coord		c;

	fill_coordinates(&c, figure, y0, x0);
	while (c.y < lst->figure_heigth - figure->y_star && c.y + c.y0 >= 0)
	{
		c.x = 0 - figure->x_star;
		c.x1 = 0;
		if (!pasting_1(lst, figure, &c))
			return (0);
		c.y1++;
		c.y++;
	}
	if (c.x == lst->figure_width - figure->x_star
		&& c.y == lst->figure_heigth - figure->y_star)
	{
		figure->y_res = c.y0 - figure->y_star;
		figure->x_res = c.x0 - figure->x_star;
		return (1);
	}
	figure->summ = 0;
	return (0);
}
