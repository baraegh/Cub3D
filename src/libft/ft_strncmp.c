/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:36:53 by brmohamm          #+#    #+#             */
/*   Updated: 2021/11/05 15:36:56 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp( const char *s1, const char *s2, size_t n)
{
	size_t	m;

	m = 0;
	if (s1 == s2 || n == 0)
		return (0);
	while ((s1[m] != '\0' && s2[m] != '\0') && m < n)
	{
		if (s1[m] != s2[m])
		{
			return (((unsigned char *)s1)[m] - ((unsigned char *)s2)[m]);
		}
		m++;
	}
	if (m < n && ((s1[m] == '\0' && s2[m] != '0')
			|| (s2[m] == '\0' && s1[m] != '\0')))
		return (((unsigned char *)s1)[m] - ((unsigned char *)s2)[m]);
	return (0);
}
