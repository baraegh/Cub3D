/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:32:41 by eel-ghan          #+#    #+#             */
/*   Updated: 2023/01/15 00:40:35 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/header.h"

int	close_window(t_data *data)
{
	(void) data;
	exit(0);
	return (0);
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
	if (data->render == 1)
	{
		mlx_clear_window(data->mlx, data->mlx_win);
		render(data);
		data->render = 0;
	}
	return (0);
}

void	hooks(t_data *data)
{
	mlx_hook(data->mlx_win, EVENT_KEY_PRESS, 0, key_press, data);
	mlx_hook(data->mlx_win, EVENT_KEY_RELEASE, 0, key_release, data);
	mlx_hook(data->mlx_win, EVENT_CLOSE, 0, &close_window, &data);
	mlx_loop_hook(data->mlx, &main_loop, data);
}
