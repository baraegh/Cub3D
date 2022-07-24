/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:07:28 by brmohamm          #+#    #+#             */
/*   Updated: 2021/11/05 15:07:30 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp( const void *s1, const void *s2, size_t size )
{
	size_t	n;

	n = 0;
	while (n < size)
	{
		if (((unsigned char *)s1)[n] != ((unsigned char *)s2)[n])
		{
			return (((unsigned char *)s1)[n] - ((unsigned char *)s2)[n]);
		}
		n++;
	}
	return (0);
}
