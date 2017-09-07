/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nulling.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:00:41 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/29 16:00:44 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/visualizer.h"

void			nulling_array(void **str, int len)
{
	int			i;

	i = 0;
	while (i < len)
		free(str[i++]);
	free(str);
}

void			nulling_arrays(t_filler *lst)
{
	nulling_array((void **)lst->map, lst->map_heigth - 1);
	lst->map = NULL;
	nulling_array((void **)lst->figure, lst->figure_heigth - 1);
	lst->figure = NULL;
}
