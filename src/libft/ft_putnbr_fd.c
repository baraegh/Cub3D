/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:14:58 by brmohamm          #+#    #+#             */
/*   Updated: 2021/11/05 15:15:01 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	n1;

	n1 = (unsigned int )n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n1 *= -1;
	}
	if (n1 >= 10)
	{
		ft_putnbr_fd(n1 / 10, fd);
		ft_putnbr_fd(n1 % 10, fd);
	}
	if (n1 <= 9)
	{
		n1 = n1 + '0';
		ft_putchar_fd(n1, fd);
	}
}
