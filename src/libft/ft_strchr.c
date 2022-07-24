/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <brmohamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:18:16 by brmohamm          #+#    #+#             */
/*   Updated: 2022/06/12 22:53:28 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr( const char *str, int c )
{
	unsigned char	chr;
	char			*st;
	int				n;

	chr = c;
	st = (char *)str;
	n = 0;
	while (st[n] != '\0')
	{
		if (st[n] == chr)
		{
			return ((char *)1);
		}
		n++;
	}
	return (0);
}
