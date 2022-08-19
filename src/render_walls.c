/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 17:34:04 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/08/19 20:19:56 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/header.h"

int	get_color(t_data* data, int x, int y)
{
	int	color;

	color = (int)data->texture.addr + (y * data->texture.line_length  + x * (data->texture.bpp / 8));
	// printf("color: %d\n", color);
	return (0);
}

void	render_floor(t_data *data, int wall_bottom_pixel, int ray_id)
{
	int		y;

	y = 0;
	while (y < wall_bottom_pixel)
	{
		img_pix_put(&data->map_img, ray_id, y, CEILLING_COLOR);
		y++;
	}
}

void	render_ceiling(t_data *data, int wall_bottom_pixel, int ray_id)
{
	int	y;

	y = wall_bottom_pixel;
	while (y < data->map_img.height)
	{
		img_pix_put(&data->map_img, ray_id, y, FLOOR_COLOR);
		y++;
	}
}

void	render_line(t_data *data, t_cast_ray *cast_ray, int ray_id)
{
	int		distance_proj_plane;
	int		wall_height;
	float	correct_wall_distance;
	int		wall_top_pixel;
	int		wall_bottom_pixel;
	int		texture_offset_x;
	int		texture_offset_y;
	int		color;
	int		distance_from_top;
	int		y;

	correct_wall_distance = cast_ray->distance * cos(cast_ray->angle - data->p.rotate_angle);
	distance_proj_plane = (data->map_img.width / 2) / tan(FOV_ANGLE / 2);
	wall_height = (TILE / correct_wall_distance) * distance_proj_plane;
	wall_top_pixel = (data->map_img.height / 2) - (wall_height / 2);
	// if (wall_top_pixel < 0)
	// 	wall_top_pixel = 0;
	wall_bottom_pixel = (data->map_img.height / 2) + (wall_height / 2);
	// if (wall_bottom_pixel > data->map_img.height)
	// 	wall_bottom_pixel = data->map_img.height;
	render_floor(data, wall_bottom_pixel, ray_id);
	if (cast_ray->is_vert_hit)
		texture_offset_x = (int)cast_ray->the_hit_point.y % TILE;
	else
		texture_offset_x = (int)cast_ray->the_hit_point.x % TILE;
	y = wall_top_pixel;
	while (y < wall_bottom_pixel)
	{
		distance_from_top = y + (wall_height / 2) - (data->map_img.height / 2);
		texture_offset_y = distance_from_top * ((float) data->texture.height / wall_height);
		color = *(int *)(data->texture.addr + (texture_offset_y * data->texture.line_length)
			+ texture_offset_x * (data->texture.bpp / 8));
		img_pix_put(&data->map_img, ray_id, y, color);
		y++;
	}
	render_ceiling(data, wall_bottom_pixel, ray_id);
}