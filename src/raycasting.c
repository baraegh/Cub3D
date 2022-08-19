/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:05:37 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/08/16 14:12:32 by eel-ghan         ###   ########.fr       */
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


float	get_distance(t_point p0, t_point p1)
{
	return (sqrt((p1.x - p0.x) * (p1.x - p0.x) + (p1.y - p0.y) * (p1.y - p0.y)));
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

void	init_horz_par(t_par *par, t_data *data, t_cast_ray cast_ray)
{
	par->there_is_a_door = 0;
	par->found_a_wall = 0;
	par->found_a_door = 0;
	if (cast_ray.is_facing_down)
		par->y_intercept = (floor(data->ray.p0.y / TILE) * TILE) + TILE;
	else
		par->y_intercept = floor(data->ray.p0.y / TILE) * TILE;
	par->x_intercept = data->ray.p0.x + ((par->y_intercept - data->ray.p0.y) / tan(cast_ray.angle));
	if (cast_ray.is_facing_up)
		par->y_step = -TILE;
	else
		par->y_step = TILE;
	par->x_step = TILE / tan(cast_ray.angle);
	if (cast_ray.is_facing_left && par->x_step > 0)
		par->x_step *= -1;
	if (cast_ray.is_facing_right && par->x_step < 0)
		par->x_step *= -1;
	par->next_touch_x = par->x_intercept;
	par->next_touch_y = par->y_intercept;
}

void	init_vert_par(t_par *par, t_data *data, t_cast_ray cast_ray)
{
	par->found_a_wall = 0;
	par->found_a_door = 0;
	if (cast_ray.is_facing_right)
		par->x_intercept = (floor(data->ray.p0.x / TILE) * TILE) + TILE;
	else
		par->x_intercept = floor(data->ray.p0.x / TILE) * TILE;
	par->y_intercept = data->ray.p0.y + ((par->x_intercept - data->ray.p0.x) * tan(cast_ray.angle));
	if (cast_ray.is_facing_left)
		par->x_step = -TILE;
	else
		par->x_step = TILE;
	par->y_step = TILE * tan(cast_ray.angle);
	if (cast_ray.is_facing_up && par->y_step > 0)
		par->y_step *= -1;
	if (cast_ray.is_facing_down && par->y_step < 0)
		par->y_step *= -1;
	par->next_touch_x = par->x_intercept;
	par->next_touch_y = par->y_intercept;
}


void	cal_horz_distance(t_par *par, t_cast_ray cast_ray, t_data *data)
{
	float	y_offst;
	int		wall_flag;
	int		door_flag;

	wall_flag = 0;
	door_flag = 0;
	while (par->next_touch_x >= 0 && par->next_touch_x < data->map_img.width &&
		par->next_touch_y >= 0 && par->next_touch_y < data->map_img.height)
	{
		if (cast_ray.is_facing_up)
			y_offst = par->next_touch_y - 1;
		else
			y_offst = par->next_touch_y;
		if (data->map[(int)y_offst / TILE][(int)par->next_touch_x / TILE] == '1')
		{
			if (!wall_flag)
			{
				par->found_a_wall = 1;
				par->horz_wall_hit.x = par->next_touch_x;
				par->horz_wall_hit.y = par->next_touch_y;
				wall_flag = 1;
			}
			// break ;
		}
		else if (data->map[(int)y_offst / TILE][(int)par->next_touch_x / TILE] == '5')
		{
			if (!door_flag)
			{
				par->found_a_door = 1;
				par->there_is_a_door = 1;
				par->horz_door_hit.x = par->next_touch_x;
				par->horz_door_hit.y = par->next_touch_y;
				door_flag = 1;
			}
			// break ;
		}
		par->next_touch_x += par->x_step;
		par->next_touch_y += par->y_step;
	}
	if (par->found_a_wall)
		par->horz_wall_distance = get_distance(data->ray.p0,
			par->horz_wall_hit);
	else
		par->horz_wall_distance = MAXFLOAT;
	if (par->found_a_door)
		par->horz_door_distance = get_distance(data->ray.p0,
			par->horz_door_hit);
	else
		par->horz_door_distance = MAXFLOAT;
	// return ((t_point){par->wall_hit_x, par->wall_hit_y});
}

void	cal_vert_distance(t_par *par, t_cast_ray cast_ray, t_data *data)
{
	float	x_offset;
	int		wall_flag;
	int		door_falg;

	wall_flag = 0;
	door_falg = 0;
	while (par->next_touch_x >= 0 && par->next_touch_x < data->map_img.width &&
		par->next_touch_y >= 0 && par->next_touch_y < data->map_img.height)
	{
		if (cast_ray.is_facing_left)
			x_offset = par->next_touch_x - 1;
		else
			x_offset = par->next_touch_x;
		if (data->map[(int)par->next_touch_y / TILE][(int)x_offset / TILE] == '1')
		{
			if (!wall_flag)
			{
				par->found_a_wall = 1;
				par->vert_wall_hit.x = par->next_touch_x;
				par->vert_wall_hit.y = par->next_touch_y;
				wall_flag = 1;
			}
			// break ;
		}
		else if (data->map[(int)(par->next_touch_y / TILE)][(int)x_offset / TILE] == '5')
		{
			if (!door_falg)
			{
				par->found_a_door = 1;
				par->there_is_a_door = 1;
				par->vert_door_hit.x = par->next_touch_x;
				par->vert_door_hit.y = par->next_touch_y;
				door_falg = 1;
			}
			// break ;
		}
		par->next_touch_x += par->x_step;
		par->next_touch_y += par->y_step;
	}
	if (par->found_a_wall)
		par->vert_wall_distance = get_distance(data->ray.p0,
			par->vert_wall_hit);
	else
		par->vert_wall_distance = MAXFLOAT;
	if (par->found_a_door)
		par->vert_door_distance = get_distance(data->ray.p0,
			par->vert_door_hit);
	else
		par->vert_door_distance = MAXFLOAT;
	// return ((t_point){par->wall_hit_x, par->wall_hit_y});
}

void	compare_distances(t_data *data, t_par *par, t_cast_ray *cast_ray)
{
	float	door_distance;
	float	wall_distance;
	int		flag;
	int		is_door_vert_hit;
	int		is_wall_vert_hit;

	is_door_vert_hit = 0;
	is_wall_vert_hit = 0;
	if (par->there_is_a_door)
	{
		if (par->horz_door_distance < par->vert_door_distance)
		{
			door_distance = par->horz_door_distance;
			is_door_vert_hit = 0;
		}
		else
		{
			door_distance = par->vert_door_distance;
			is_door_vert_hit = 1;
		}
		if (par->horz_wall_distance < par->vert_wall_distance)
		{
			flag = 1;
			is_wall_vert_hit = 0;
			wall_distance = par->horz_wall_distance;
		}
		else
		{
			flag = 2;
			is_wall_vert_hit = 1;
			wall_distance = par->vert_wall_distance;
		}
		if (door_distance < wall_distance)
		{
			cast_ray->distance = door_distance;
			if(is_door_vert_hit)
				cast_ray->the_hit_point = par->vert_door_hit;
			else
				cast_ray->the_hit_point = par->horz_door_hit;
			cast_ray->is_vert_hit = is_door_vert_hit;
			data->texture = data->door_tex;
			// dda(data, (t_ray){data->ray.p0, cast_ray->the_hit_point, COLOR});
		}
		else
		{
			cast_ray->distance = wall_distance;
			if(is_wall_vert_hit)
				cast_ray->the_hit_point = par->vert_wall_hit;
			else
				cast_ray->the_hit_point = par->horz_wall_hit;
			cast_ray->is_vert_hit = is_wall_vert_hit;
			set_texture(data, cast_ray, flag);
			// dda(data, (t_ray){data->ray.p0, cast_ray->the_hit_point, CASTING_RAYS_COLOR});
		}
	}
	else
	{
		if (par->horz_wall_distance < par->vert_wall_distance)
		{
			cast_ray->the_hit_point = par->horz_wall_hit;
			cast_ray->distance = par->horz_wall_distance;
			cast_ray->is_vert_hit = 0;
			set_texture(data, cast_ray, 1);
		}
		else
		{
			cast_ray->the_hit_point = par->vert_wall_hit;
			cast_ray->distance = par->vert_wall_distance;
			cast_ray->is_vert_hit = 1;
			set_texture(data, cast_ray, 2);
		}
		// dda(data, (t_ray){data->ray.p0, cast_ray->the_hit_point, CASTING_RAYS_COLOR});
	}
}

void	cast_ray(t_data *data, float angle, int ray_id)
{
	t_par		par;
	t_cast_ray	cast_ray;
	(void) ray_id;
	init_cast_ray(&cast_ray, angle);
	init_horz_par(&par, data, cast_ray);
	cal_horz_distance(&par, cast_ray, data);
	init_vert_par(&par, data, cast_ray);
	cal_vert_distance(&par, cast_ray, data);
	compare_distances(data, &par, &cast_ray);
	// if (par.there_is_a_door)
	// 	dda(data, (t_ray){data->ray.p0, cast_ray.the_hit_point, COLOR});
	// else
	// 	dda(data, (t_ray){data->ray.p0, cast_ray.the_hit_point, CASTING_RAYS_COLOR});
	render_line(data, &cast_ray, ray_id);
}

void	cast_rays(t_data *data)
{
	int		ray_id;
	float	ray_angle;

	ray_angle = data->p.rotate_angle - (FOV_ANGLE / 2);
	ray_id = 0;
	while (ray_id < data->num_rays)
	{
		cast_ray(data, normalize_angle(ray_angle), ray_id);
		ray_angle += FOV_ANGLE / data->num_rays;
		ray_id++;
	}
}