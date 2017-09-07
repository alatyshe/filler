/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nulling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:00:41 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/29 16:00:44 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/filler.h"

void			nulling_arrays(t_filler *lst)
{
	lst->distance_map_max = 0;
	lst->figure_heigth = 0;
	lst->figure_width = 0;
	lst->old_map = lst->map;
	lst->map = NULL;
	if (lst->figure)
		nulling_array((void **)lst->figure, lst->figure_heigth - 1);
	nulling_figure(lst->succes_pasting);
}

void			nulling_array(void **str, int len)
{
	int			i;

	i = 0;
	while (i < len)
	{
		free(str[i]);
		i++;
	}
}

void			nulling_figure(t_figure *lst)
{
	t_figure	*copy;

	while (lst->next)
	{
		copy = lst->next;
		free(lst);
		lst = copy;
	}
}
