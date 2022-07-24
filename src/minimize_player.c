/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimize_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 12:17:38 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/07/24 12:18:25 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../Includes/header.h"

void	init_player(t_data * data)
{
	int	x;
	int	y;

	data->player_matrix = malloc(sizeof(char *) * 5);
	y = 0;
	while (y < 4)
	{
		data->player_matrix[y] = malloc(sizeof(char) * 5);
		x = 0;
		while (x < 4)
		{
			if ((y == 1 && ( x == 1 || x == 2))
				|| (y == 2 && (x == 1 || x == 2)))
				data->player_matrix[y][x] = '0';
			else
				data->player_matrix[y][x] = '1';
			x++;
		}
		data->player_matrix[y][x] = '\0';
		y++;
	}
	data->player_matrix[y] = NULL;
}

//TODO: create a matrix to handle player's spawn & movement
void	put_img_for_player(t_data * data, t_rect rect)
{
	float	i;
	float	j;

	put_imgs(data, (t_rect){rect.x + rect.width / 2, rect.y + rect.height/ 2,
		rect.color, rect.width, rect.height});
	i =  0;
	while (i < rect.height)
	{
		j = 0;
		while (j < rect.width)
		{
			put_imgs(data, (t_rect){j + rect.x, i + rect.y, PLAT_COLOR,
				rect.width / 2, rect.height / 2});		
			j++;
		}
		i++;
	}
}

void	render_player(t_data *data, t_rect rect)
{
	int		x;
	int		y;
	float	x_pos;
	float	y_pos;

	put_imgs(data, (t_rect){rect.x,rect.y,
					0x8879B0, rect.width, rect.height});
	y = 0;
	y_pos = 0;
	while (data->player_matrix[y])
	{
		x = 0;
		x_pos = 0;
		while (data->player_matrix[y][x])
		{
			if (data->player_matrix[y][x] == '0')
				put_imgs(data, (t_rect){x_pos + rect.x, y_pos + rect.y,
					PLAYER_COLOR, rect.width / 4, rect.height / 4});
			x_pos += rect.width / 4;
			x++;
		}
		y_pos += rect.height / 4;
		y++;
	}
}