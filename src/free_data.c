/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 18:06:51 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/08/25 18:15:19 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/header.h"

void	free_data(t_data *data)
{
	int	i;

	free(data->no_tex_path);
	free(data->so_tex_path);
	free(data->we_tex_path);
	free(data->ea_tex_path);
	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	mlx_destroy_image(data->mlx, data->no_tex.img);
	mlx_destroy_image(data->mlx, data->so_tex.img);
	mlx_destroy_image(data->mlx, data->we_tex.img);
	mlx_destroy_image(data->mlx, data->ea_tex.img);
	mlx_destroy_image(data->mlx, data->map_img.img);
	if (data->mlx && data->mlx_win)
		mlx_destroy_window(data->mlx, data->mlx_win);
}
