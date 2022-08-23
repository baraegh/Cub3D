/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 15:47:49 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/08/23 15:59:12 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/header.h"

int	is_a_wall(t_data *data, float x, float y)
{
	t_int_point	p;

	p.x = (int)(x + data->p.size) / TILE;
	p.y = (int)(y + data->p.size) / TILE;
	if (data->map[(int)(y / TILE)][(int)x / TILE] == '1' ||
		data->map[(int)(y / TILE)][(int)(x + data->p.size) / TILE] == '1' ||
		data->map[(int)(y + data->p.size) / TILE][(int)x / TILE] == '1' ||
		data->map[p.y][p.x] == '1')
		return (1);
	return (0);
}

void	move(t_data *data, int y, int x)
{
	float	move_step;
	float	angle;
	t_point	p;

	data->p.rotate_angle += data->p.turn_direction * data->p.rotate_speed;
	if (y)
	{
		move_step = y * data->p.move_speed;
		p.x = data->p.p.x - cos(data->p.rotate_angle) * move_step;
		p.y = data->p.p.y - sin(data->p.rotate_angle) * move_step;
	}
	else if (x)
	{
		move_step = x * data->p.move_speed;
		angle = data->p.rotate_angle + (3 * M_PI / 2);
		p.x = data->p.p.x - cos(angle) * move_step;
		p.y = data->p.p.y - sin(angle) * move_step;
	}
	if (!is_a_wall(data, p.x, p.y) && !is_a_door(data, p.x, p.y))
	{
		data->p.p.x = p.x;
		data->p.p.y = p.y;
		render(data);
	}
}

void	rotate_line(t_data *data)
{
	data->p.rotate_angle += data->p.turn_direction * data->p.rotate_speed;
	render(data);
}
