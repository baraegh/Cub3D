/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_distances.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 16:51:07 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/08/23 17:37:43 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/header.h"

void	compare_wall_distance(t_par *par, t_cast_ray *cast_ray, t_data *data)
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
}

void	set_distance(t_par *par)
{
	if (par->horz_door_distance < par->vert_door_distance)
	{
		par->door_distance = par->horz_door_distance;
		par->is_door_vert_hit = 0;
	}
	else
	{
		par->door_distance = par->vert_door_distance;
		par->is_door_vert_hit = 1;
	}
	if (par->horz_wall_distance < par->vert_wall_distance)
	{
		par->flag = 1;
		par->is_wall_vert_hit = 0;
		par->wall_distance = par->horz_wall_distance;
	}
	else
	{
		par->flag = 2;
		par->is_wall_vert_hit = 1;
		par->wall_distance = par->vert_wall_distance;
	}
}

void	compare_distances_util(t_par *par, t_data *data, t_cast_ray *cast_ray)
{
	if (par->door_distance < par->wall_distance)
	{
		cast_ray->distance = par->door_distance;
		if (par->is_door_vert_hit)
			cast_ray->the_hit_point = par->vert_door_hit;
		else
			cast_ray->the_hit_point = par->horz_door_hit;
		cast_ray->is_vert_hit = par->is_door_vert_hit;
		data->texture = data->door_tex;
	}
	else
	{
		cast_ray->distance = par->wall_distance;
		if (par->is_wall_vert_hit)
			cast_ray->the_hit_point = par->vert_wall_hit;
		else
			cast_ray->the_hit_point = par->horz_wall_hit;
		cast_ray->is_vert_hit = par->is_wall_vert_hit;
		set_texture(data, cast_ray, par->flag);
	}
}

void	compare_distances(t_data *data, t_par *par, t_cast_ray *cast_ray)
{
	par->is_door_vert_hit = 0;
	par->is_wall_vert_hit = 0;
	if (par->there_is_a_door)
	{
		set_distance(par);
		compare_distances_util(par, data, cast_ray);
	}
	else
		compare_wall_distance(par, cast_ray, data);
}
