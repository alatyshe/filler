/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:00:41 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/29 16:00:44 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/filler.h"

t_figure		*new_figure(void)
{
	t_figure	*lst;

	lst = (t_figure *)malloc(sizeof(t_figure));
	lst->y_map = 0;
	lst->x_map = 0;
	lst->y_star = 0;
	lst->x_star = 0;
	lst->y_res = 0;
	lst->x_res = 0;
	lst->summ = 0;
	lst->next = NULL;
	return (lst);
}

t_filler		*new_filler(void)
{
	t_filler	*lst;

	lst = (t_filler *)malloc(sizeof(t_filler));
	lst->map = NULL;
	lst->old_map = NULL;
	lst->distance_map = NULL;
	lst->distance_map_max = 0;
	lst->map_heigth = 0;
	lst->map_width = 0;
	lst->figure = NULL;
	lst->figure_heigth = 0;
	lst->figure_width = 0;
	lst->count_stars = 0;
	lst->my = 0;
	lst->enemy = 0;
	lst->res_x = 0;
	lst->res_y = 0;
	lst->succes_pasting = NULL;
	return (lst);
}
