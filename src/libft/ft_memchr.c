/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:06:35 by brmohamm          #+#    #+#             */
/*   Updated: 2021/11/05 15:06:38 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr( const void *s, int serchar, size_t size )
{
	size_t			n;

	n = 0;
	while (n < size)
	{
		if (((unsigned char *)s)[n] == (unsigned char)serchar)
		{
			return ((void *)(s + n));
		}
		n++;
	}
	return (0);
}
