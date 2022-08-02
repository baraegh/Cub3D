/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_pix_put.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 14:18:03 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/07/24 15:21:15 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/header.h"

void	img_pix_put(t_data *data, int x, int y, int color)
{
	char	*pixel;
	int		i;

	if (x >= 0 && x < data->img.width
		&& y >= 0 && y < data->img.height)
	{
		i = data->img.bpp - 8;
		pixel = data->img.addr + (y * data->img.line_length + x * (data->img.bpp / 8));
		while (i >= 0)
		{
			if (data->img.endian != 0)
				*pixel++ = (color >> i) & 0xFF;
			else
				*pixel++ = (color >> (data->img.bpp - 8 - i)) & 0xFF;
			i -= 8;
		}
	}
}
