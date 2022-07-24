/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:41:04 by brmohamm          #+#    #+#             */
/*   Updated: 2021/11/05 15:41:06 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	bigins1(int countset, char const *s1, char const *set)
{
	int	lset;
	int	fs1;

	lset = 0;
	fs1 = 0;
	while (lset != countset)
	{
		if (s1[fs1] == set[lset])
		{
			fs1++;
			lset = -1;
		}
		lset++;
	}
	return (fs1);
}

static int	endns1(int *counts1, int countset, char const *s1, char const *set)
{
	int	lset;

	lset = 0;
	while (lset <= countset)
	{
		if (s1[*counts1] == set[lset])
		{
			(*counts1)--;
			lset = -1;
		}
		lset++;
	}
	return (*counts1);
}

static char	*cpy_to_c(int fs1, int counts1, char *c, char const *s1)
{
	int	countset;

	countset = 0;
	while (fs1 <= counts1)
	{
		c[countset] = s1[fs1];
		countset++;
		fs1++;
	}
	c[countset] = '\0';
	return (c);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		fs1;
	int		countset;
	int		counts1;
	char	*c;

	countset = 0;
	counts1 = 0;
	if (!s1)
		return (NULL);
	while (set[countset] != '\0')
		countset++;
	while (s1[counts1] != '\0')
		counts1++;
	fs1 = bigins1(countset, s1, set);
	if (fs1 != counts1)
		endns1(&counts1, countset, s1, set);
	c = malloc((counts1 - fs1) + 2);
	if (!c)
		return (NULL);
	cpy_to_c(fs1, counts1, c, s1);
	return (c);
}
