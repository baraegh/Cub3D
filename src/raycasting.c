/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:05:37 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/08/02 17:13:13 by eel-ghan         ###   ########.fr       */
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

float	get_distance(t_point p0, t_point p1)
{
	return (sqrt((p1.x - p0.x) * (p1.x - p1.x) + (p1.y - p0.y) * (p1.y - p0.y)));
}

void	calculate_distace(t_data *data, t_par *par, t_cast_ray *cast_ray)
{
	if (par->found_horz_wall_hit)
		par->horz_distance = get_distance(data->ray.p0,
			(t_point){par->horz_wall_hit_x, par->horz_wall_hit_y});
	else
		par->horz_distance = MAXFLOAT;
	if (par->found_vert_wall_hit)
		par->vert_distance = get_distance(data->ray.p0,
			(t_point){par->vert_wall_hit_x, par->vert_wall_hit_y});
	else
		par->vert_distance = MAXFLOAT;
	if (par->horz_distance < par->vert_distance)
	{
		cast_ray->wall_hit_x = par->horz_wall_hit_x;
		cast_ray->wall_hit_y = par->horz_wall_hit_y;
	}
	else
	{
		cast_ray->wall_hit_x = par->vert_wall_hit_x;
		cast_ray->wall_hit_y = par->vert_wall_hit_y;
	}
	dda(data,
		(t_ray){
			(t_point){data->ray.p0.x * MAP_SCALE, data->ray.p0.y * MAP_SCALE},
			(t_point){
				cast_ray->wall_hit_x * MAP_SCALE,
				cast_ray->wall_hit_y * MAP_SCALE
			},
			CASTING_RAYS_COLOR
		});
}

void	init_hor_par(t_par *par, t_data *data, t_cast_ray cast_ray, float angle)
{
	par->found_horz_wall_hit = 0;
	par->y_intercept = floor(data->ray.p0.y / TILE) * TILE;
	par->y_intercept += cast_ray.is_facing_down ? TILE : 0;
	par->x_intercept = data->ray.p0.x + ((par->y_intercept - data->ray.p0.y) / tan(angle));
	par->y_step = TILE;
	par->y_step *= cast_ray.is_facing_up ? -1 : 1;
	par->x_step = TILE / tan(angle);
	par->x_step *= (cast_ray.is_facing_left && par->x_step > 0) ? -1 : 1;
	par->x_step *= (cast_ray.is_facing_right && par->x_step < 0) ? -1 : 1;
	par->next_horz_touch_x = par->x_intercept;
	par->next_horz_touch_y = par->y_intercept;
}

void	init_vert_par(t_par *par, t_data *data, t_cast_ray cast_ray, float angle)
{
	par->found_vert_wall_hit = 0;
	par->x_intercept = floor(data->ray.p0.x / TILE) * TILE;
	par->x_intercept += cast_ray.is_facing_right ? TILE : 0;
	par->y_intercept = data->ray.p0.y + ((par->x_intercept - data->ray.p0.x) * tan(angle));
	par->x_step = TILE;
	par->x_step *= cast_ray.is_facing_left ? -1 : 1;
	par->y_step = TILE * tan(angle);
	par->y_step *= (cast_ray.is_facing_up && par->y_step > 0) ? -1 : 1;
	par->y_step *= (cast_ray.is_facing_down && par->y_step < 0) ? -1 : 1;
	par->next_vert_touch_x = par->x_intercept;
	par->next_vert_touch_y = par->y_intercept;
}

void	set_horz_distance(t_par *par, t_cast_ray cast_ray, t_data * data)
{
	float	y_offset;

	while (par->next_horz_touch_x >= 0 && par->next_horz_touch_x < data->img.width &&
		par->next_horz_touch_y >= 0 && par->next_horz_touch_y < data->img.height)
	{
		y_offset = par->next_horz_touch_y + (cast_ray.is_facing_up ? -1 : 0);
		if (data->map[(int)y_offset / TILE][(int) par->next_horz_touch_x / TILE] == '1')
		{
			par->found_horz_wall_hit = 1;
			par->horz_wall_hit_x = par->next_horz_touch_x;
			par->horz_wall_hit_y = par->next_horz_touch_y;
			break ;
		}
		par->next_horz_touch_x += par->x_step;
		par->next_horz_touch_y += par->y_step;
	}
}

void	set_vert_distance(t_par *par, t_cast_ray cast_ray, t_data * data)
{
	float	x_offset;

	while (par->next_vert_touch_x >= 0 && par->next_vert_touch_x < data->img.width &&
		par->next_vert_touch_y >= 0 && par->next_vert_touch_y < data->img.height)
	{
		x_offset = par->next_vert_touch_x + (cast_ray.is_facing_left ? -1 : 0);
		if (data->map[(int)par->next_vert_touch_y / TILE][(int)x_offset / TILE] == '1')
		{
			par->found_vert_wall_hit = 1;
			par->vert_wall_hit_x = par->next_vert_touch_x;
			par->vert_wall_hit_y = par->next_vert_touch_y;
			break ;
		}
		par->next_vert_touch_x += par->x_step;
		par->next_vert_touch_y += par->y_step;
	}
}

void	cast_ray(t_data *data, float angle, int i)
{
	t_par		par;
	t_cast_ray	cast_ray;

	(void) i;
	init_cast_ray(&cast_ray, angle);
	init_hor_par(&par, data, cast_ray, angle);
	set_horz_distance(&par, cast_ray, data);
	init_vert_par(&par, data, cast_ray, angle);
	set_vert_distance(&par, cast_ray, data);
	calculate_distace(data, &par, &cast_ray);
}

void	cast_rays(t_data *data)
{
	int		i;
	float	ray_angle;

	ray_angle = data->p.rotate_angle - (FOV_ANGLE / 2);
	i = 0;
	while (i < data->num_rays)
	{
		cast_ray(data, normalize_angle(ray_angle), i);
		ray_angle += FOV_ANGLE / data->num_rays;
		i++;
	}
}