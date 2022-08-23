/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 14:47:12 by brmohamm          #+#    #+#             */
/*   Updated: 2022/08/23 17:22:21 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	loop(const char *str, int i, int n)
{
	long	result;
	long	help;

	result = 0;
	help = 0;
	while (str[n] >= '0' && str[n] <= '9')
	{
		help = 10 * help + (str[n] - '0');
		if ((help / 10 != result) && (i == -1))
			return (0);
		if ((help / 10 != result) && (i == 1))
			return (-1);
		result = 10 * result + (str[n] - '0');
		n++;
	}
	return (result * i);
}

int	ft_atoi(const char *str)
{
	long	result;
	int		i;
	int		n;

	result = 0;
	i = 1;
	n = 0;
	while (str[n] == '\f' || str[n] == '\n' || str[n] == 32
		|| str[n] == '\r' || str[n] == '\v' || str[n] == '\t')
		n++;
	if (str[n] == '-')
	{
		i *= -1;
		n++;
	}
	else if (str[n] == '+')
		n++;
	result = loop(str, i, n);
	return (result);
}
