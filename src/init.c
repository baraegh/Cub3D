/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 19:21:06 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/08/15 20:46:27 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/header.h"

void	init_win(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->map[y])
	{
		while (data->map[0][x])
			x++;
		y++;
	}
	data->mlx = mlx_init();
	data->map_img.width = x * TILE;
	data->map_img.height = y * TILE;
	data->mlx_win = mlx_new_window(data->mlx, data->map_img.width, data->map_img.height, "Cub3D");
	data->num_rays = data->map_img.width / WALL_STRIP_WIDTH;
}

void	init_map_img(t_data *data)
{
	data->map_img.img = mlx_new_image(data->mlx, data->map_img.width,  data->map_img.height);
	data->map_img.addr = mlx_get_data_addr(data->map_img.img, &data->map_img.bpp,
							&data->map_img.line_length, &data->map_img.endian);
}

void	init_texture(t_data *data)
{
	data->no_tex.img = mlx_xpm_file_to_image(data->mlx, "./texturs/NO.xpm",
		&data->no_tex.width, &data->no_tex.height);
	data->no_tex.addr = mlx_get_data_addr(data->no_tex.img, &data->no_tex.bpp,
		&data->no_tex.line_length, &data->no_tex.endian);
	
	data->so_tex.img = mlx_xpm_file_to_image(data->mlx, "./texturs/SO.xpm",
		&data->so_tex.width, &data->so_tex.height);
	data->so_tex.addr = mlx_get_data_addr(data->so_tex.img, &data->so_tex.bpp,
		&data->so_tex.line_length, &data->so_tex.endian);

	data->we_tex.img = mlx_xpm_file_to_image(data->mlx, "./texturs/WE.xpm",
		&data->we_tex.width, &data->we_tex.height);
	data->we_tex.addr = mlx_get_data_addr(data->we_tex.img, &data->we_tex.bpp,
		&data->we_tex.line_length, &data->we_tex.endian);
	
	data->ea_tex.img = mlx_xpm_file_to_image(data->mlx, "./texturs/EA.xpm",
		&data->ea_tex.width, &data->ea_tex.height);
	data->ea_tex.addr = mlx_get_data_addr(data->ea_tex.img, &data->ea_tex.bpp,
		&data->ea_tex.line_length, &data->ea_tex.endian);
	
	data->door_tex.img = mlx_xpm_file_to_image(data->mlx, "./texturs/door.xpm",
		&data->door_tex.width, &data->door_tex.height);
	data->door_tex.addr = mlx_get_data_addr(data->door_tex.img, &data->door_tex.bpp,
		&data->door_tex.line_length, &data->door_tex.endian);
	// data->texture = NULL;
}

void	set_ray_rotate_angle(t_data *data)
{
	if (data->p.first_direction == 'N')
		data->p.rotate_angle = 3 * M_PI / 2;
	else if (data->p.first_direction == 'S')
		data->p.rotate_angle = M_PI / 2;
	else if (data->p.first_direction == 'W')
		data->p.rotate_angle = M_PI;
	else if (data->p.first_direction == 'E')
		data->p.rotate_angle = 0;
	data->p.flag_angle_set = 1;
}

void	init_direction_ray(t_data *data)
{
	data->ray.p0.x = data->p.p.x + data->p.size / 2;
	data->ray.p0.y = data->p.p.y + data->p.size / 2;
	if (!data->p.flag_angle_set)
		set_ray_rotate_angle(data);
	data->ray.p1.x = data->ray.p0.x + cos(data->p.rotate_angle) * (data->p.size + 10);
	data->ray.p1.y =  data->ray.p0.y + sin(data->p.rotate_angle) * (data->p.size + 10);
}

void	init_player(t_data *data)
{
	int	x;
	int	y;

	data->p.step.x = 0;
	data->p.step.y = 0;
	data->p.move_l_r.x = 0;
	data->p.move_l_r.y = 0;
	data->p.turn_direction = 0;
	data->p.rotate_angle = 0;
	data->p.move_speed = 5;
	data->p.rotate_speed = 5 * (M_PI / 180);
	data->p.flag_angle_set = 0;
	data->p.size = TILE / 4;
	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'W' || data->map[y][x] == 'S'
				|| data->map[y][x] == 'N' || data->map[y][x] == 'E')
			{
				data->p.p.x = x * TILE + TILE / 4;
				data->p.p.y = y * TILE + TILE / 4;
				data->p.first_direction = data->map[y][x];
				data->map[y][x] = '0';
			}
			x++;
		}
		y++;
	}
	init_direction_ray(data);
}

void	init_cast_ray(t_cast_ray *cast_ray, float angle)
{
	cast_ray->the_hit_point.x = 0;
	cast_ray->the_hit_point.y = 0;
	cast_ray->distance = 0;
	cast_ray->is_facing_down = angle > 0 && angle < M_PI;
	cast_ray->is_facing_up = !cast_ray->is_facing_down;
	cast_ray->is_facing_right = angle < M_PI / 2 || angle > 3 * M_PI / 2;
	cast_ray->is_facing_left = !cast_ray->is_facing_right;
	cast_ray->angle = angle;
}
