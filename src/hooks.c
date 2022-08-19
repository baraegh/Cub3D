/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:32:41 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/08/19 21:07:40 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/header.h"

int	is_an_open_door(t_data *data, float x, float y)
{
	if (data->map[(int)(y / TILE)][(int)x / TILE] == '6' ||
		data->map[(int)(y / TILE)][(int)(x + data->p.size) / TILE] == '6' ||
		data->map[(int)(y + data->p.size) / TILE][(int)x / TILE] == '6' ||
		data->map[(int)(y + data->p.size) / TILE][(int)(x + data->p.size) / TILE] == '6')
		return (1);
	return (0);
}

int	is_a_door(t_data *data, float x, float y)
{
	if (data->map[(int)(y / TILE)][(int)x / TILE] == '5' ||
		data->map[(int)(y / TILE)][(int)(x + data->p.size) / TILE] == '5' ||
		data->map[(int)(y + data->p.size) / TILE][(int)x / TILE] == '5' ||
		data->map[(int)(y + data->p.size) / TILE][(int)(x + data->p.size) / TILE] == '5')
		return (1);
	return (0);
}

int	is_a_wall(t_data *data, float x, float y)
{
	if (data->map[(int)(y / TILE)][(int)x / TILE] == '1' ||
		data->map[(int)(y / TILE)][(int)(x + data->p.size) / TILE] == '1' ||
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
	if (!is_a_wall(data, p.x, p.y) && !is_a_door(data, p.x, p.y))
	{
		data->p.p.x = p.x;
		data->p.p.y = p.y;
		// mlx_destroy_image(data->mlx, data->map_img.img);
		// init_map_img(data);
		render(data);
	}
}

void	rotate_line(t_data *data)
{
	data->p.rotate_angle += data->p.turn_direction * data->p.rotate_speed;
	// mlx_destroy_image(data->mlx, data->map_img.img);
	// init_map_img(data);
	render(data);
}

void	*routine(void *arg)
{
	t_data	*data;
	t_point	p;

	data = (t_data *) arg;
	p.x = data->door_hit.x;
	p.y = data->door_hit.y;
	sleep(2);
	while (data->map[(int)data->p.p.y / TILE][(int)data->p.p.x / TILE] == '6')
		sleep(1);
	data->map[(int)p.y / TILE][(int)p.x / TILE] = '5';
	render(data);
	return (NULL);
}

void	open_door(t_data *data)
{
	float	i;
	t_point	p;

	i  = 0;
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

int	close_window(t_data *data)
{
	(void) data;
	exit(0);
	return(1);
}

int	key_release(int key_code, t_data *data)
{
	if (key_code == KEY_ESC)
		return (close_window(data));
	else if (key_code == KEY_W || key_code == KEY_UP)
		data->p.step.x = 0;
	else if (key_code == KEY_S || key_code == KEY_DOWN)
		data->p.step.y = 0;
	else if (key_code == KEY_D)
		data->p.move_l_r.x = 0;
	else if (key_code == KEY_A)
		data->p.move_l_r.y = 0;
	else if (key_code == KEY_LEFT)
		data->p.turn_direction = 0;
	else if (key_code == KEY_RIGHT)
		data->p.turn_direction = 0;
	else if (key_code == KEY_O)
		data->p.open_door = 0;
	return (0);
}

int	ready_to_close_door(t_data *data)
{
	time_t cur_time;

	cur_time = time(NULL);
	if (data->door_is_open
		&& cur_time - data->door_opened_time >= 3
		&& data->map[(int)data->ray.p0.y / TILE][(int)data->ray.p0.x / TILE] != '6')
		return (1);
	return (0);
}

int	key_press(int key_code, t_data *data)
{
	if (key_code == KEY_ESC)
		return (close_window(data));
	else if (key_code == KEY_W || key_code == KEY_UP)
		data->p.step.x = 1;
	else if (key_code == KEY_S || key_code == KEY_DOWN)
		data->p.step.y = 1;
	else if (key_code == KEY_D)
		data->p.move_l_r.x = 1;
	else if (key_code == KEY_A)
		data->p.move_l_r.y = 1;
	else if (key_code == KEY_LEFT)
		data->p.turn_direction = -1;
	else if (key_code == KEY_RIGHT)
		data->p.turn_direction = 1;
	else if (key_code == KEY_O)
		data->p.open_door = 1;
	return (0);
}


int	main_loop(t_data *data)
{
	if (data->p.step.x)
		move(data, -1, 0);
	else if (data->p.step.y)
		move(data, 1, 0);
	else if (data->p.move_l_r.x)
		move(data, 0, 1);
	else if (data->p.move_l_r.y)
		move(data, 0, -1);
	else if (data->p.turn_direction != 0)
		rotate_line(data);
	else if (data->p.open_door)
		open_door(data);
	else if (ready_to_close_door(data))
		close_door(data);
	else
		render(data);
	return (0);
}

void	hooks(t_data *data)
{
	mlx_hook(data->mlx_win, EVENT_KEY_PRESS, 0, key_press, data);
	mlx_hook(data->mlx_win, EVENT_KEY_RELEASE, 0, key_release, data);
	mlx_hook(data->mlx_win, EVENT_CLOSE, 0, &close_window, &data);
	mlx_loop_hook(data->mlx, main_loop, data);
}