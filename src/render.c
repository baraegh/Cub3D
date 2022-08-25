/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:47:04 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/08/25 16:27:30 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/header.h"

void	render_player(t_data *data)
{
	put_rect(&data->map_img,
		(t_rect){data->p.p.x * MAP_SCALE, data->p.p.y * MAP_SCALE,
		BLACK_COLOR, data->p.size * MAP_SCALE, data->p.size * MAP_SCALE});
	init_direction_ray(data);
	draw_direction_ray(data);
}

void	render_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == '1')
				put_rect(&data->map_img, (t_rect){x * TILE * MAP_SCALE,
					y * TILE * MAP_SCALE, WALL_COLOR,
					TILE * MAP_SCALE, TILE * MAP_SCALE});
			else if (data->map[y][x] == '0')
				put_rect(&data->map_img,
					(t_rect){x * TILE * MAP_SCALE, y * TILE * MAP_SCALE,
					PLAT_COLOR, TILE * MAP_SCALE, TILE * MAP_SCALE});
			x++;
		}
		y++;
	}
}

int	render(t_data *data)
{
	cast_rays(data);
	render_map(data);
	render_player(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win,
		data->map_img.img, 0, 0);
	return (0);
}

void	display(t_data *data)
{
	init_win(data);
	init_map_img(data);
	init_texture(data);
	init_player(data);
	hooks(data);
	mlx_loop(data->mlx);
}
