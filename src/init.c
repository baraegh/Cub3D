/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 19:21:06 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/08/02 17:24:56 by eel-ghan         ###   ########.fr       */
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
	data->mlx_win = mlx_new_window(data->mlx, WIN_WIDTH,WIN_HEIGHT, "Cub3D");
	data->img.width = x * TILE;
	data->img.height = y * TILE;
	data->num_rays = data->img.width / WALL_STRIP_WIDTH;
}

void	init_img(t_data *data)
{
	data->img.img = mlx_new_image(data->mlx, data->img.width, data->img.height);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bpp,
							&data->img.line_length, &data->img.endian);
}

void	init_player(t_data *data)
{
	data->p.turn_direction = 0;
	data->p.rotate_angle = 0;
	data->p.move_speed = 3;
	data->p.rotate_speed = 5 * (M_PI / 180);
	data->p.flag_angle_set = 0;
}
