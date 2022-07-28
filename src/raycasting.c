/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:05:37 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/07/28 17:35:04 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/header.h"

void	cast_rays(t_data *data)
{
	int		i;
	float	ray_angle;
	t_point	p;

	p.x = data->p.p.x + TILE / 4;
	p.y = data->p.p.y + TILE / 4;
	ray_angle = data->p.rotate_angle - (FOV_ANGLE / 2);
	i = 0;
	while (i < data->num_rays)
	{
		dda(data,
			(t_ray){
				p,
				(t_point){
					p.x + cos(ray_angle) * TILE,
					p.y + sin(ray_angle) * TILE
				},
				CASTING_RAYS_COLOR
			});
		ray_angle += FOV_ANGLE / data->num_rays;
		i++;
	}
}