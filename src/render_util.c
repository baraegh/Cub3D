/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 17:03:43 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/08/23 17:16:05 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/header.h"

void	put_rect(t_img *img, t_rect rect)
{
	float	i;
	float	j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
		{
			img_pix_put(img, j, i, rect.color);
			j++;
		}
		i++;
	}
}

void	draw_direction_ray(t_data *data)
{
	dda(data, (t_ray){
		(t_point){data->ray.p0.x * MAP_SCALE, data->ray.p0.y * MAP_SCALE},
		(t_point){data->ray.p1.x * MAP_SCALE, data->ray.p1.y * MAP_SCALE},
		BLACK_COLOR
	});
}
