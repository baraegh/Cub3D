/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:47:04 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/07/24 12:34:49 by eel-ghan         ###   ########.fr       */
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
	data->mlx_win = mlx_new_window(data->mlx, x * 30, y * 30, "Cub3D");
	data->img.img = mlx_new_image(data->mlx, x * 30, y * 30);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bpp,
							&data->img.line_length, &data->img.endian);
	data->img.width = x * 30;
	data->img.height = y * 30;
}

void	set_player_direction(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'W' || data->map[y][x] == 'S'
				|| data->map[y][x] == 'N' || data->map[y][x] == 'E')
				data->p_direction = data->map[y][x];
			x++;
		}
		y++;
	}
}

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
				put_imgs(data,(t_rect){x * 30, y * 30, WALL_COLOR, 30, 30});
			else if (data->map[y][x] == '0')
				put_imgs(data, (t_rect){x * 30, y * 30, PLAT_COLOR, 30, 30});
			else if (data->map[y][x] == 'W' || data->map[y][x] == 'S'
				|| data->map[y][x] == 'N' || data->map[y][x] == 'E')
				put_imgs(data, (t_rect){x * 30, y * 30, PLAYER_COLOR, 30, 30});
			x++; 
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win,
		data->img.img, 0, 0);
}

void	display(t_data *data)
{
	init_win(data);
	set_player_direction(data);
	render(data);
	hooks(data);
	mlx_loop(data->mlx);
}