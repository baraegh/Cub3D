/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_distances.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 16:51:07 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/08/24 20:41:54 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/header.h"

void	compare_distances(t_data *data, t_par *par, t_cast_ray *cast_ray)
{
	par->is_wall_vert_hit = 0;
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
