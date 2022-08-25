/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_distance.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 16:26:57 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/08/24 20:40:51 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/header.h"

void	cal_horz_distance_util(t_data *data, t_par *par, int y_offset)
{
	if (data->map[(int)y_offset / TILE][(int)par->next_touch_x / TILE] == '1')
	{
		if (!par->wall_flag)
		{
			par->found_a_wall = 1;
			par->horz_wall_hit.x = par->next_touch_x;
			par->horz_wall_hit.y = par->next_touch_y;
			par->wall_flag = 1;
		}
	}
}

void	cal_horz_distance(t_par *par, t_cast_ray cast_ray, t_data *data)
{
	float	y_offset;

	par->wall_flag = 0;
	while (par->next_touch_x >= 0 && par->next_touch_x < data->map_img.width
		&& par->next_touch_y >= 0 && par->next_touch_y < data->map_img.height)
	{
		if (cast_ray.is_facing_up)
			y_offset = par->next_touch_y - 1;
		else
			y_offset = par->next_touch_y;
		cal_horz_distance_util(data, par, y_offset);
		par->next_touch_x += par->x_step;
		par->next_touch_y += par->y_step;
	}
	set_horz_distance(par, data);
}

void	cal_vert_distance_util(t_data *data, t_par *par, int x_offset)
{
	if (data->map[(int)par->next_touch_y / TILE][(int)x_offset / TILE] == '1')
	{
		if (!par->wall_flag)
		{
			par->found_a_wall = 1;
			par->vert_wall_hit.x = par->next_touch_x;
			par->vert_wall_hit.y = par->next_touch_y;
			par->wall_flag = 1;
		}
	}
}

void	cal_vert_distance(t_par *par, t_cast_ray cast_ray, t_data *data)
{
	float	x_offset;

	par->wall_flag = 0;
	while (par->next_touch_x >= 0 && par->next_touch_x < data->map_img.width
		&& par->next_touch_y >= 0 && par->next_touch_y < data->map_img.height)
	{
		if (cast_ray.is_facing_left)
			x_offset = par->next_touch_x - 1;
		else
			x_offset = par->next_touch_x;
		cal_vert_distance_util(data, par, x_offset);
		par->next_touch_x += par->x_step;
		par->next_touch_y += par->y_step;
	}
	set_vert_distance(par, data);
}
