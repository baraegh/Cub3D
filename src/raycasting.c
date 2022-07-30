/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:05:37 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/07/30 14:53:55 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/header.h"

// in order to keep our angle between 0 & 2PI 
float	normalize_angle(float angle)
{
	angle = remainder(angle , (2 * M_PI));
	if (angle < 0)
		angle += (2 * M_PI);
	return (angle);
}

void	init_cast_ray(t_cast_ray *cast_ray, float angle)
{
	cast_ray->wall_hit_x = 0;
	cast_ray->wall_hit_y = 0;
	cast_ray->distance = 0;
	cast_ray->is_facing_down = angle > 0 && angle < M_PI;
	cast_ray->is_facing_up = !cast_ray->is_facing_down;
	cast_ray->is_facing_right = angle < M_PI / 2 || angle > 3 * M_PI / 2;
	cast_ray->is_facing_left = !cast_ray->is_facing_right;
}

void	cast_ray(t_data *data, float angle, int i)
{
	float		x_intercept;
	float		y_intercept;
	float		x_step;
	float		y_step;
	float		next_horz_touch_x;
	float		next_horz_touch_y;
	t_cast_ray	cast_ray;

	(void) i;
	init_cast_ray(&cast_ray, angle);
	y_intercept = floor(data->ray.p0.y / TILE) * TILE;
	y_intercept += cast_ray.is_facing_down ? TILE : 0;
	x_intercept = data->ray.p0.x + ((y_intercept - data->ray.p0.y) / tan(angle));

	y_step = TILE;
	y_step *= cast_ray.is_facing_up ? -1 : 1;

	x_step = TILE / tan(angle);
	x_step *= (cast_ray.is_facing_left && x_step > 0) ? -1 : 1;
	x_step *= (cast_ray.is_facing_right && x_step < 0) ? -1 : 1;

	next_horz_touch_x = x_intercept;
	next_horz_touch_y = y_intercept;
	if (cast_ray.is_facing_up)
		next_horz_touch_y--;
	while (next_horz_touch_x >= 0 && next_horz_touch_x < data->img.width &&
		next_horz_touch_y >= 0 && next_horz_touch_y < data->img.height)
	{
		if (data->map[(int)next_horz_touch_y / TILE][(int)next_horz_touch_x / TILE] == '1')
		{
			cast_ray.wall_hit_x = next_horz_touch_x;
			cast_ray.wall_hit_y = next_horz_touch_y;
			dda(data,
				(t_ray){
					data->ray.p0,
					(t_point){
						cast_ray.wall_hit_x,
						cast_ray.wall_hit_y
					},
					CASTING_RAYS_COLOR
				});
			break ;
		}
		next_horz_touch_x += x_step;
		next_horz_touch_y += y_step;
	}
}

void	cast_rays(t_data *data)
{
	int		i;
	float	ray_angle;
	// t_point	p;

	ray_angle = data->p.rotate_angle - (FOV_ANGLE / 2);
	i = 0;
	while (i < data->num_rays)
	{
		cast_ray(data, normalize_angle(ray_angle), i);
		ray_angle += FOV_ANGLE / data->num_rays;
		i++;
	}
}