/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 18:36:32 by alatyshe          #+#    #+#             */
/*   Updated: 2016/12/05 19:22:45 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

void	ft_putendl(char const *s)
{
	char	*b;

	b = (char *)s;
	if (b)
		while (*b)
			ft_putchar(*b++);
	ft_putchar('\n');
}
