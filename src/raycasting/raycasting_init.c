/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 16:25:21 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/08/23 17:38:23 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/header.h"

void	init_horz_par(t_par *par, t_data *data, t_cast_ray cast_ray)
{
	par->there_is_a_door = 0;
	par->found_a_wall = 0;
	par->found_a_door = 0;
	if (cast_ray.is_facing_down)
		par->y_intercept = (floor(data->ray.p0.y / TILE) * TILE) + TILE;
	else
		par->y_intercept = floor(data->ray.p0.y / TILE) * TILE;
	par->x_intercept = data->ray.p0.x
		+ ((par->y_intercept - data->ray.p0.y) / tan(cast_ray.angle));
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
	par->y_intercept = data->ray.p0.y
		+ ((par->x_intercept - data->ray.p0.x) * tan(cast_ray.angle));
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

float	normalize_angle(float angle)
{
	angle = remainder(angle, (2 * M_PI));
	if (angle < 0)
		angle += (2 * M_PI);
	return (angle);
}
