/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_print_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:00:41 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/29 16:00:44 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/visualizer.h"

void			printf_array_map(char *str, t_filler *info)
{
	int			i;

	i = 0;
	while (str[i])
	{
		if (str[i] == info->player_1 || str[i] == info->player_1 + 32)
			ft_printf("%s%c%s", GREEN, str[i], RESET);
		else if (str[i] == info->player_2 || str[i] == info->player_2 + 32)
			ft_printf("%s%c%s", RED, str[i], RESET);
		else
			ft_printf("%c", str[i]);
		i++;
	}
}

void			print_map(char **str, int len, t_filler *info)
{
	int			i;

	i = 0;
	while (i < len)
	{
		printf_array_map(str[i], info);
		ft_printf("%s  #####  %s", YELLOW, RESET);
		if (i < info->figure_heigth - 1)
			ft_printf("%-*s%s\t%s",
				info->map_width, info->figure[i], YELLOW, RESET);
		else
			ft_printf("%*c%s\t%s",
				info->map_width, ' ', YELLOW, RESET);
		ft_printf("\n");
		i++;
	}
}

void			print_players(t_filler *info)
{
	ft_printf("%s%c - %s : %d\n%s", GREEN,
		info->player_1, info->name_1, info->p1_counter, RESET);
	ft_printf("%s%c - %s : %d\n\n%s", RED,
		info->player_2, info->name_2, info->p2_counter, RESET);
}

void			ft_print_func(t_filler *info)
{
	ft_printf("\033[6;0H");
	print_players(info);
	print_map(info->map, info->map_heigth, info);
}
