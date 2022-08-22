/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 12:04:56 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/08/22 22:45:09 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
#include <fcntl.h>
# include "../src/libft/libft.h"
# include "mlx_keys.h"
# include "struct.h"
# include <time.h>

# define WIN_WIDTH 1024
# define WIN_HEIGHT 540
# define TILE 32
# define PLAYER_COLOR 0xA6D1E6
# define PLAT_COLOR 0xFEFBF6
# define WALL_COLOR 0x7F5283
# define RAY_COLOR 0xA6D1E6
# define CASTING_RAYS_COLOR 0xCA4E79
# define FOV_ANGLE 60 * (M_PI / 180)
# define WALL_STRIP_WIDTH  1
# define MAP_SCALE 0.25
# define COLOR 0xFFC18E
# define WHITE_COLOR 0xFEFBF6
# define WHITE_SHADE_COLOR 0xF5F5F5
# define BLACK_COLOR 0x000000
# define FLOOR_COLOR 0x31087B
# define CEILLING_COLOR 0x1C6DD0
# define DOOR_COLOR 0xF29393

t_data	check_file(char *path);
int		error(char  *msg, t_pars *pars);
char	*get_next_line(int fd);
void	display(t_data *data);
void	init_win(t_data *data);
void	init_map_img(t_data *data);
void	init_player(t_data *data);
int 	render(t_data *data);
void	render_player(t_data *data);
void	hooks(t_data *data);
void	img_pix_put(t_img *img, int x, int y, int color);
void	put_rect(t_img *img, t_rect rect);
void	init_player(t_data * data);
void	init_cast_ray(t_cast_ray *cast_ray, float angle);
void	dda(t_data *data, t_ray ray);
void	cast_rays(t_data *data);
void	render_line(t_data *data, t_cast_ray *cast_ray, int ray_id);
void	init_direction_ray(t_data *data);
void	init_texture(t_data *data);
int		is_a_door(t_data *data, float x, float y);

#endif