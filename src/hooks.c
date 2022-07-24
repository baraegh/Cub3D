/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:32:41 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/07/24 12:15:00 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/header.h"

void	move(t_data *data, int y, int x, t_point p)
{
	if (data->map[p.y + y][p.x + x] != '1')
	{
		data->map[p.y][p.x] = '0';
		data->map[p.y + y][p.x + x] = 'N';
		render(data);
	}
}

int	check(t_data *data, int x, int y)
{
	if (data->map[y][x] != '1'
		&& (data->map[y][x] == 'N'|| data->map[y][x] == 'W'
		|| data->map[y][x] == 'E' || data->map[y][x] == 'S'))
		return (1);
	return (0);
}

int	close_window(t_data *data)
{
	(void) data;
	exit(0);
	return(1);
}

int	key_hook(int key_code, t_data *data)
{
	int	x;
	int	y;
	int	break_flag;

	if (key_code == KEY_ESC)
		close_window(data);
	y = 0;
	break_flag = 1;
	while (data->map[y] && break_flag)
	{
		x = 0;
		while (data->map[y][x])
		{
			if (check(data, x, y) && break_flag)
			{
				break_flag = 0;
				if (key_code == KEY_UP)
					move(data, -1, 0, (t_point){x, y});
				else if (key_code == KEY_DOWN)
					move(data, 1, 0, (t_point){x, y});
				else if (key_code == KEY_LEFT)
					move(data, 0, -1, (t_point){x, y});
				else if (key_code == KEY_RIGHT)
					move(data, 0, 1, (t_point){x, y});
			}
			x++;
		}
		y++;
	}
	return (0);
}

void	hooks(t_data *data)
{
	mlx_key_hook(data->mlx_win, key_hook, data);
	mlx_hook(data->mlx_win, EVENT_CLOSE, 0, &close_window, &data);
}