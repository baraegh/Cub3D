/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 14:52:55 by brmohamm          #+#    #+#             */
/*   Updated: 2021/11/05 14:52:59 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc( size_t count, size_t size)
{
	char	*str;

	str = malloc(count * size);
	if (str == 0)
		return (NULL);
	ft_memset (str, 0, (count * size));
	return ((void *)(str));
}
