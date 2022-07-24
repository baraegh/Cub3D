/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <brmohamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:45:29 by brmohamm          #+#    #+#             */
/*   Updated: 2022/06/12 22:53:57 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_tolower(char *str)
{
	char	*c;
	int		i;

	i = 0;
	c = malloc(ft_strlen(str) + 1);
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			c[i] = str[i] + 32;
		else
			c[i] = str[i];
		i++;
	}
	c[i] = '\0';
	return (c);
}
