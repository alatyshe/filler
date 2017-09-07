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

#include "../header/filler.h"

int				main(void)
{
	char		*line;
	t_filler	*lst;

	lst = new_filler();
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
		{
			lst->figure = get_figure(lst, line);
			if (lst->map_width != 0 || lst->map_heigth != 0)
				analyse_tactic(lst);
			print_res(lst);
			nulling_arrays(lst);
		}
	}
	return (0);
}
