/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:44:02 by brmohamm          #+#    #+#             */
/*   Updated: 2022/08/21 21:06:41 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, int start, int len)
{
	char	*c;
	int		n;
	int		a;

	n = 0;
	a = len + 1;
	if (!s)
		return (NULL);
	if (a >= ft_strlen(s))
		a = ft_strlen(s) + 1;
	c = ft_calloc(sizeof(char), a);
	a = 0;
	if (!c)
		return (NULL);
	while (s[a] != '\0')
	{
		if (a >= start && n < len)
		{
			c[n] = s[a];
			n++;
		}
		a++;
	}
	c[a] = '\0';
	return (c);
}
