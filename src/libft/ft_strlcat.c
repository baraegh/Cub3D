/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:28:25 by brmohamm          #+#    #+#             */
/*   Updated: 2021/11/05 15:28:28 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	lds;
	unsigned int	k;
	unsigned int	lsr;

	lsr = 0;
	lds = 0;
	k = 0;
	while (src[lsr] != '\0')
		lsr++;
	while (dest[lds] != '\0')
		lds++;
	if (size <= lds)
		return (lsr + size);
	while (src[k] != '\0' && k + lds < size - 1)
	{
		dest[lds + k] = src[k];
		k++;
	}
	dest[lds + k] = '\0';
	return (lds + lsr);
}
