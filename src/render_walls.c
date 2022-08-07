/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 17:34:04 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/08/07 14:14:10 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/header.h"

void	render_wall(t_data *data, t_cast_ray *cast_ray, int ray_id)
{
	int		distance_proj_plane;
	int		wall_height;
	float	correct_wall_distance;

	dda(data,
	(t_ray){
		(t_point){data->ray.p0.x * MAP_SCALE, data->ray.p0.y * MAP_SCALE},
		(t_point){
			cast_ray->wall_hit_x * MAP_SCALE,
			cast_ray->wall_hit_y * MAP_SCALE
		},
		CASTING_RAYS_COLOR
	});

	correct_wall_distance = cast_ray->distance * cos(cast_ray->angle - data->p.rotate_angle);
	distance_proj_plane = (data->map_img.width / 2) / tan(FOV_ANGLE / 2);
	wall_height = (TILE / correct_wall_distance) * distance_proj_plane;
	dda(data, (t_ray){
		(t_point){ray_id * WALL_STRIP_WIDTH, (data->map_img.height / 2) - (wall_height / 2)},
		(t_point){ray_id * WALL_STRIP_WIDTH,  (data->map_img.height / 2) + (wall_height / 2)},
		WHITE_COLOR
	});
}