/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 14:37:27 by brmohamm          #+#    #+#             */
/*   Updated: 2021/11/05 14:37:32 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	char	*dest1;
	char	*src1;

	dest1 = (char *)dest;
	src1 = (char *)src;
	if (dest1 < src1)
	{
		ft_memcpy(dest1, src1, size);
	}
	else if (dest1 > src1)
	{
		while (size > 0)
		{
			dest1[size - 1] = src1[size - 1];
			size --;
		}
	}
	return (dest1);
}
