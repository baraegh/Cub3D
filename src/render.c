/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:47:04 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/08/02 17:17:49 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/header.h"

void	put_imgs(t_data *data, t_rect rect)
{
	int	i;
	int	j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
		{
			img_pix_put(data, j , i, rect.color);
			j++;
		}
		i++;
	}
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

void	draw_direction_ray(t_data *data)
{
	data->ray.p0.x = data->p.p.x + TILE / 4;
	data->ray.p0.y = data->p.p.y + TILE / 4;
	if (!data->p.flag_angle_set)
		set_ray_rotate_angle(data);
	data->ray.p1.x = data->ray.p0.x + cos(data->p.rotate_angle) * TILE / 2;
	data->ray.p1.y =  data->ray.p0.y + sin(data->p.rotate_angle) * TILE / 2;
	cast_rays(data);
	dda(data, (t_ray){
		(t_point){data->ray.p0.x * MAP_SCALE, data->ray.p0.y * MAP_SCALE},
		(t_point){data->ray.p1.x * MAP_SCALE, data->ray.p1.y * MAP_SCALE},
		RAY_COLOR
	});
}

void	render_player(t_data *data)
{
	data->p.size = TILE / 2;
	put_imgs(data,
		(t_rect){data->p.p.x * MAP_SCALE, data->p.p.y * MAP_SCALE,
			PLAYER_COLOR, data->p.size * MAP_SCALE, data->p.size * MAP_SCALE});
	draw_direction_ray(data);
}

void	render(t_data *data)
{
	int	x;
	int y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == '1')
				put_imgs(data,(t_rect){x * TILE * MAP_SCALE,
					y * TILE * MAP_SCALE, WALL_COLOR,
					TILE * MAP_SCALE, TILE * MAP_SCALE});
			else if (data->map[y][x] == '0')
				put_imgs(data,
					(t_rect){x * TILE * MAP_SCALE, y * TILE * MAP_SCALE,
						PLAT_COLOR, TILE * MAP_SCALE, TILE * MAP_SCALE});
			else if (data->map[y][x] == 'W' || data->map[y][x] == 'S'
				|| data->map[y][x] == 'N' || data->map[y][x] == 'E')
			{
				data->p.p.x = x * TILE + TILE / 4;
				data->p.p.y = y * TILE + TILE / 4;
				put_imgs(data, (t_rect){x * TILE * MAP_SCALE, y * TILE * MAP_SCALE,
					PLAT_COLOR, TILE * MAP_SCALE, TILE * MAP_SCALE});
				data->p.first_direction = data->map[y][x];
				data->map[y][x] = '0';
			}
			x++; 
		}
		y++;
	}
	render_player(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win,
		data->img.img, 0, 0);
}

void	display(t_data *data)
{
	init_win(data);
	init_img(data);
	init_player(data);
	render(data);
	hooks(data);
	mlx_loop(data->mlx);
}