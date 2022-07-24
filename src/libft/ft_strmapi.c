/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:35:36 by brmohamm          #+#    #+#             */
/*   Updated: 2021/11/05 15:35:38 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		ls;
	char	*c;

	ls = 0;
	if (!s)
		return (NULL);
	while (s[ls] != '\0')
		ls++;
	c = malloc(ls + 1);
	if (!c)
		return (NULL);
	ls = 0;
	while (s[ls] != '\0')
	{
		c[ls] = (f)(ls, s[ls]);
		ls++;
	}
	c[ls] = '\0';
	return (c);
}
