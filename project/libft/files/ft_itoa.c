/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 20:26:59 by alatyshe          #+#    #+#             */
/*   Updated: 2016/12/08 16:13:20 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

size_t				num_count(long long int n)
{
	size_t			i;
	size_t			b;

	i = 0;
	if (n < 0)
	{
		b = (size_t)(-n);
		i++;
	}
	else
		b = (size_t)n;
	while (b >= 10)
	{
		i++;
		b = b / 10;
	}
	i++;
	return (i);
}

char				*ft_itoa(intmax_t n)
{
	unsigned int	i;
	char			*b;
	size_t			s;
	int				c;

	c = 1;
	i = num_count(n);
	if (!(b = (char *)malloc(sizeof(char) * num_count(n) + 1)))
		return (NULL);
	b[i] = '\0';
	if (n < 0)
	{
		s = (size_t)(-n);
		c = -1;
	}
	else
		s = (size_t)n;
	while (i--)
	{
		b[i] = s % 10 + 48;
		s = s / 10;
	}
	if (c == -1)
		b[0] = '-';
	return (b);
}
