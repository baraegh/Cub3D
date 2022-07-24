/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:04:12 by brmohamm          #+#    #+#             */
/*   Updated: 2021/11/05 15:04:22 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	lopandcondition(int n, char *c, int i)
{
	long int	g;

	g = n;
	if (n == 0)
		c[0] = 48;
	if (n < 0)
	{
		c[0] = '-';
		g *= -1;
	}
	while (i >= 0 && g > 0)
	{
		c[i] = g % 10 + 48;
		g /= 10 ;
		i--;
	}
	return (*c);
}

char	*ft_itoa(int n)
{
	char	*c;
	int		i;
	int		t;

	t = n;
	i = 0;
	if (t < 0)
	{
		t *= -1;
		i++;
	}
	if (t == 0)
		i = 1;
	while (t != 0)
	{
		t /= 10;
		i++;
	}
	c = (char *)ft_calloc(sizeof(char), i + 1);
	if (!c)
		return (NULL);
	i--;
	lopandcondition(n, c, i);
	return (c);
}
