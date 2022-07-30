/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:32:41 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/07/29 19:38:01 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/header.h"

int	is_a_wall(t_data *data, float x, float y)
{
	if (data->map[(int)y / TILE][(int)x / TILE] == '1' ||
		data->map[(int)y / TILE][(int)(x + data->p.size) / TILE] == '1' ||
		data->map[(int)(y + data->p.size) / TILE][(int)x / TILE] == '1' ||
		data->map[(int)(y + data->p.size) / TILE][(int)(x + data->p.size) / TILE] == '1')
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
		p.y = data->p.p.y -  sin(angle) * move_step;
	}
	if (!is_a_wall(data, p.x, p.y))
	{
		data->p.p.x = p.x;
		data->p.p.y = p.y;
		render(data);
	}
	data->p.turn_direction = 0;
}

void	rotate_line(t_data *data)
{
	data->p.rotate_angle += data->p.turn_direction * data->p.rotate_speed;
	mlx_destroy_image(data->mlx, data->img.img);
	init_img(data);
	render(data);
	data->p.turn_direction = 0;
}

int	close_window(t_data *data)
{
	(void) data;
	exit(0);
	return(1);
}

int	key_hook(int key_code, t_data *data)
{
	if (key_code == KEY_ESC)
		close_window(data);
	else if (key_code == KEY_W)
		move(data, -1, 0);
	else if (key_code  == KEY_S)
		move(data, 1, 0);
	else if (key_code == KEY_D)
		move(data, 0, 1);
	else if (key_code == KEY_A)
	move(data, 0, -1);
	else if (key_code == KEY_LEFT)
	{
		data->p.turn_direction = -1;
		rotate_line(data);
	}
	else if (key_code == KEY_RIGHT)
	{
		data->p.turn_direction = 1;
		rotate_line(data);
	}
	return (0);
}

void	hooks(t_data *data)
{
	mlx_key_hook(data->mlx_win, key_hook, data);
	mlx_hook(data->mlx_win, EVENT_CLOSE, 0, &close_window, &data);
}