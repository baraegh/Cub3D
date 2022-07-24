/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 14:43:18 by brmohamm          #+#    #+#             */
/*   Updated: 2021/11/05 14:43:33 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int value, size_t count)
{
	size_t			n;
	unsigned char	chr;
	char			*result;

	chr = value;
	result = str;
	n = 0;
	while (n < count)
	{
		result[n] = chr;
		n++;
	}
	return (result);
}
