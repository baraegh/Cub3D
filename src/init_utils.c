/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 16:16:33 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/08/24 20:49:55 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/header.h"

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
	data->ray.p1.x = data->ray.p0.x + cos(data->p.rotate_angle)
		* (data->p.size + 10);
	data->ray.p1.y = data->ray.p0.y + sin(data->p.rotate_angle)
		* (data->p.size + 10);
}

void	init_player_corr(t_data *data)
{
	int	x;
	int	y;

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
}

void	init_img_h_w(t_data *data)
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
}

void	set_text_addr(t_data *data)
{
	data->no_tex.addr = mlx_get_data_addr(data->no_tex.img, &data->no_tex.bpp,
			&data->no_tex.line_length, &data->no_tex.endian);
	data->so_tex.addr = mlx_get_data_addr(data->so_tex.img, &data->so_tex.bpp,
			&data->so_tex.line_length, &data->so_tex.endian);
	data->we_tex.addr = mlx_get_data_addr(data->we_tex.img, &data->we_tex.bpp,
			&data->we_tex.line_length, &data->we_tex.endian);
	data->ea_tex.addr = mlx_get_data_addr(data->ea_tex.img, &data->ea_tex.bpp,
			&data->ea_tex.line_length, &data->ea_tex.endian);
}
