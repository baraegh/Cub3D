/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:39:26 by brmohamm          #+#    #+#             */
/*   Updated: 2021/11/05 15:39:29 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int				n;

	n = 0;
	while (str[n] != '\0')
		n++;
	while (n >= 0)
	{
		if (((char *)str)[n] == (char)c)
			return ((char *)str + n);
		n--;
	}
	return (0);
}
