/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_door.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 15:45:41 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/08/23 15:58:58 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/header.h"

int	is_an_open_door(t_data *data, float x, float y)
{
	t_int_point	p;

	p.x = (int)(x + data->p.size) / TILE;
	p.y = (int)(y + data->p.size) / TILE;
	if (data->map[(int)(y / TILE)][(int)x / TILE] == '6' ||
		data->map[(int)(y / TILE)][(int)(x + data->p.size) / TILE] == '6' ||
		data->map[(int)(y + data->p.size) / TILE][(int)x / TILE] == '6' ||
		data->map[p.y][p.x] == '6')
		return (1);
	return (0);
}

int	is_a_door(t_data *data, float x, float y)
{
	t_int_point	p;

	p.x = (int)(x + data->p.size) / TILE;
	p.y = (int)(y + data->p.size) / TILE;
	if (data->map[(int)(y / TILE)][(int)x / TILE] == '5' ||
		data->map[(int)(y / TILE)][(int)(x + data->p.size) / TILE] == '5' ||
		data->map[(int)(y + data->p.size) / TILE][(int)x / TILE] == '5' ||
		data->map[p.y][p.x] == '5')
		return (1);
	return (0);
}

void	open_door(t_data *data)
{
	float	i;
	t_point	p;

	i = 0;
	while (i < 3)
	{
		p.x = data->ray.p0.x + cos(data->p.rotate_angle) * i * TILE;
		p.y = data->ray.p0.y + sin(data->p.rotate_angle) * i * TILE;
		if (data->map[(int)p.y / TILE][(int)p.x / TILE] == '1')
			return ;
		if (data->map[(int)p.y / TILE][(int)p.x / TILE] == '5')
		{
			data->map[(int)p.y / TILE][(int)p.x / TILE] = '6';
			data->door_hit = p;
			data->door_is_open = 1;
			data->door_opened_time = time(NULL);
			break ;
		}
		i += 0.5;
	}
}

void	close_door(t_data *data)
{
	t_point	p;

	p.x = data->door_hit.x;
	p.y = data->door_hit.y;
	data->map[(int)p.y / TILE][(int)p.x / TILE] = '5';
	data->door_is_open = 0;
}

int	ready_to_close_door(t_data *data)
{
	time_t		cur_time;
	t_int_point	p;

	p.x = (int)data->ray.p0.x / TILE;
	p.y = (int)data->ray.p0.y / TILE;
	cur_time = time(NULL);
	if (data->door_is_open
		&& cur_time - data->door_opened_time >= 3
		&& data->map[p.y][p.x] != '6')
		return (1);
	return (0);
}
