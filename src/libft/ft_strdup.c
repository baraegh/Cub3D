/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <brmohamm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:20:12 by brmohamm          #+#    #+#             */
/*   Updated: 2021/11/18 15:02:16 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup( const char *src )
{
	char	*c;
	int		n;

	n = 0;
	while (src[n] != '\0')
		n++;
	c = malloc(n + 1);
	if (c == 0)
		return (NULL);
	n = 0;
	while (src[n] != '\0')
	{
		c[n] = src[n];
		n++;
	}
	c[n] = '\0';
	return (c);
}
