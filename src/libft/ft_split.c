/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <brmohamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:17:32 by brmohamm          #+#    #+#             */
/*   Updated: 2022/06/12 22:53:15 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countpart_lop(char const *s, char c)
{
	int	ls;
	int	countpart;

	countpart = 0;
	ls = 0;
	while (s[ls] != '\0')
	{
		if (s[ls] != c)
		{
			while (s[ls] != c && s[ls] != '\0')
				s++;
			countpart++;
			ls--;
		}
		ls++;
	}
	return (countpart);
}

static char	**ft_free_alloc_malloc(char **c1, int countpart, int countstrs)
{
	int	i;

	i = 0;
	c1[countpart] = (char *)malloc(sizeof(char) * countstrs + 1);
	if (!c1[countpart])
	{
		while (i < countpart)
		{
			free(c1[i]);
			i++;
		}
		return (NULL);
	}
	return (c1);
}

static	char	**countstr_lop(char const *s, char c, char **c1, int countpart)
{
	int	ls;
	int	countstrs;

	ls = 0;
	countstrs = 0;
	while (s[ls] != '\0')
	{
		if (s[ls] != c)
		{
			while (s[ls] != c && s[ls] != '\0')
			{
				countstrs++;
				ls++;
			}
			ls--;
		}
		if ((countstrs > 0) || (s[ls + 1] == '\0' && s[ls] != c))
		{
			c1 = ft_free_alloc_malloc(c1, countpart, countstrs);
			countpart++;
			countstrs = 0;
		}
		ls++;
	}
	return (c1);
}

static	char	**contaner_lop(char const *s, char c, char **c1, int countpart)
{
	int	ls;
	int	countstrs;

	ls = 0;
	countstrs = 0;
	while (s[ls])
	{
		if (s[ls] != c)
		{
			while (s[ls] != c && s[ls] != '\0')
			{
				c1[countpart][countstrs++] = s[ls];
				ls++;
			}
			ls--;
		}
		if ((countstrs > 0) || (s[ls + 1] == '\0' && s[ls] != c))
		{
			c1[countpart][countstrs] = '\0';
			countpart++;
			countstrs = 0;
		}
		ls++;
	}
	return (c1);
}

char	**ft_split(char const *s, char c)
{
	int		countpart;
	char	**c1;
	int		i;

	if (!s)
		return (NULL);
	countpart = countpart_lop(s, c);
	c1 = (char **)malloc(sizeof(char *) * (countpart + 1));
	if (!c1)
		return (NULL);
	c1[countpart] = NULL;
	countpart = 0;
	i = 0;
	while (c1[i])
		i++;
	countstr_lop(s, c, c1, countpart);
	if (!c1)
		return (NULL);
	countpart = 0;
	contaner_lop(s, c, c1, countpart);
	if (ft_strncmp(s, "", 1) == 0)
		c1[0] = "";
	return (c1);
}
