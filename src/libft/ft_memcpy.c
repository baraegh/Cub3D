/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:08:32 by brmohamm          #+#    #+#             */
/*   Updated: 2021/11/05 15:08:35 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy( void *destination, const void *source, size_t size )
{
	size_t	n;

	n = 0;
	if (destination == source || size == 0)
		return (destination);
	while (n < size)
	{
		((unsigned char *)destination)[n] = ((unsigned char *)source)[n];
		n++;
	}
	return (destination);
}
