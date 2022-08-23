/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 19:21:06 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/08/23 16:17:38 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/header.h"

void	init_win(t_data *data)
{
	init_img_h_w(data);
	data->mlx_win = mlx_new_window(data->mlx, data->map_img.width,
			data->map_img.height, "Cub3D");
	data->num_rays = data->map_img.width / WALL_STRIP_WIDTH;
}

void	init_map_img(t_data *data)
{
	data->map_img.img = mlx_new_image(data->mlx,
			data->map_img.width, data->map_img.height);
	if (!data->map_img.img)
		error("Failed toload image!", NULL);
	data->map_img.addr = mlx_get_data_addr(data->map_img.img,
			&data->map_img.bpp, &data->map_img.line_length,
			&data->map_img.endian);
}

void	init_texture(t_data *data)
{
	data->no_tex.img = mlx_xpm_file_to_image(data->mlx, data->no_tex_path,
			&data->no_tex.width, &data->no_tex.height);
	if (!data->no_tex.img)
		error("Failed to load NO's texture", NULL);
	data->so_tex.img = mlx_xpm_file_to_image(data->mlx, data->so_tex_path,
			&data->so_tex.width, &data->so_tex.height);
	if (!data->so_tex.img)
		error("Failed to load SO's texture", NULL);
	data->we_tex.img = mlx_xpm_file_to_image(data->mlx, data->we_tex_path,
			&data->we_tex.width, &data->we_tex.height);
	if (!data->we_tex.img)
		error("Failed to load WE's texture", NULL);
	data->ea_tex.img = mlx_xpm_file_to_image(data->mlx, data->ea_tex_path,
			&data->ea_tex.width, &data->ea_tex.height);
	if (!data->ea_tex.img)
		error("Failed to load EA's texture", NULL);
	data->door_tex.img = mlx_xpm_file_to_image(data->mlx, "./texturs/door.xpm",
			&data->door_tex.width, &data->door_tex.height);
	if (!data->door_tex.img)
		error("Failed to load door's texture", NULL);
	set_text_addr(data);
}

void	init_player(t_data *data)
{
	data->p.step.x = 0;
	data->p.step.y = 0;
	data->p.move_l_r.x = 0;
	data->p.move_l_r.y = 0;
	data->p.turn_direction = 0;
	data->p.fov_angle = 60 * (M_PI / 180);
	data->p.rotate_angle = 0;
	data->p.move_speed = 5;
	data->p.rotate_speed = 5 * (M_PI / 180);
	data->p.flag_angle_set = 0;
	data->p.size = TILE / 4;
	init_player_corr(data);
	init_direction_ray(data);
}

void	init_cast_ray(t_cast_ray *cast_ray, float angle)
{
	cast_ray->the_hit_point.x = 0;
	cast_ray->the_hit_point.y = 0;
	cast_ray->distance = 0;
	cast_ray->is_facing_down = 0;
	if (angle > 0 && angle < M_PI)
		cast_ray->is_facing_down = 1;
	cast_ray->is_facing_up = !cast_ray->is_facing_down;
	cast_ray->is_facing_right = 0;
	if (angle < M_PI / 2 || angle > 3 * M_PI / 2)
		cast_ray->is_facing_right = 1;
	cast_ray->is_facing_left = !cast_ray->is_facing_right;
	cast_ray->angle = angle;
}
