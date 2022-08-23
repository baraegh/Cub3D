/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3D.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 17:34:04 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/08/23 17:15:47 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/header.h"

int	get_color(t_data *data, int x, int y)
{
	int	color;

	color = (int)data->texture.addr + (y * data->texture.line_length
			+ x * (data->texture.bpp / 8));
	return (0);
}

void	render_floor(t_data *data, int wall_bottom_pixel, int ray_id)
{
	int		y;

	y = 0;
	while (y < wall_bottom_pixel)
	{
		img_pix_put(&data->map_img, ray_id, y, data->floor_color);
		y++;
	}
}

void	render_ceiling(t_data *data, int wall_bottom_pixel, int ray_id)
{
	int	y;

	y = wall_bottom_pixel;
	while (y < data->map_img.height)
	{
		img_pix_put(&data->map_img, ray_id, y, data->ceilling_color);
		y++;
	}
}

void	init_line(t_line *line, t_cast_ray *cast_ray, t_data *data)
{
	line->correct_wall_distance = cast_ray->distance
		* cos(cast_ray->angle - data->p.rotate_angle);
	line->distance_proj_plane = (data->map_img.width / 2)
		/ tan(data->p.fov_angle / 2);
	line->wall_height = (TILE / line->correct_wall_distance)
		* line->distance_proj_plane;
	line->wall_top_pixel = (data->map_img.height / 2) - (line->wall_height / 2);
	if (line->wall_top_pixel < 0)
		line->wall_top_pixel = 0;
	line->wall_bottom_pixel = (data->map_img.height / 2)
		+ (line->wall_height / 2);
	if (line->wall_bottom_pixel > data->map_img.height)
		line->wall_bottom_pixel = data->map_img.height;
}

void	render_line(t_data *data, t_cast_ray *cast_ray, int ray_id)
{
	t_line	line;

	init_line(&line, cast_ray, data);
	render_floor(data, line.wall_bottom_pixel, ray_id);
	if (cast_ray->is_vert_hit)
		line.texture_offset_x = (int)cast_ray->the_hit_point.y % TILE;
	else
		line.texture_offset_x = (int)cast_ray->the_hit_point.x % TILE;
	line.y = line.wall_top_pixel;
	while (line.y < line.wall_bottom_pixel)
	{
		line.distance_from_top = line.y
			+ (line.wall_height / 2) - (data->map_img.height / 2);
		line.texture_offset_y = line.distance_from_top
			* ((float) data->texture.height / line.wall_height);
		line.color = *(int *)(data->texture.addr
				+ (line.texture_offset_y * data->texture.line_length)
				+ line.texture_offset_x * (data->texture.bpp / 8));
		img_pix_put(&data->map_img, ray_id, line.y, line.color);
		line.y++;
	}
	render_ceiling(data, line.wall_bottom_pixel, ray_id);
}
