/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:05:37 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/08/23 17:38:08 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/header.h"

float	get_distance(t_point p0, t_point p1)
{
	return (sqrt(pow((p1.x - p0.x), 2) + pow((p1.y - p0.y), 2)));
}

void	set_texture(t_data *data, t_cast_ray *cast_ray, int flag)
{
	if (flag == 1)
	{
		if (cast_ray->angle >= 0 && cast_ray->angle <= M_PI)
			data->texture = data->so_tex;
		else
			data->texture = data->no_tex;
	}
	else if (flag == 2)
	{
		if (cast_ray->angle >= M_PI / 2 && cast_ray->angle <= 3 * M_PI / 2)
			data->texture = data->we_tex;
		else
			data->texture = data->ea_tex;
	}
}

void	cast_ray(t_data *data, float angle, int ray_id)
{
	t_par		par;
	t_cast_ray	cast_ray;

	init_cast_ray(&cast_ray, angle);
	init_horz_par(&par, data, cast_ray);
	cal_horz_distance(&par, cast_ray, data);
	init_vert_par(&par, data, cast_ray);
	cal_vert_distance(&par, cast_ray, data);
	compare_distances(data, &par, &cast_ray);
	render_line(data, &cast_ray, ray_id);
}

void	cast_rays(t_data *data)
{
	int		ray_id;
	float	ray_angle;

	ray_angle = data->p.rotate_angle - (data->p.fov_angle / 2);
	ray_id = 0;
	while (ray_id < data->num_rays)
	{
		cast_ray(data, normalize_angle(ray_angle), ray_id);
		ray_angle += data->p.fov_angle / data->num_rays;
		ray_id++;
	}
}
