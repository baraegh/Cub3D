/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 12:04:56 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/08/23 17:19:16 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
# include <fcntl.h>
# include "../src/libft/libft.h"
# include "mlx_keys.h"
# include "struct.h"
# include <time.h>
# include "file.h"
# include "hooks.h"
# include "raycasting.h"

# define WIN_WIDTH 1024
# define WIN_HEIGHT 540
# define TILE 32
# define PLAYER_COLOR 0xA6D1E6
# define PLAT_COLOR 0xFEFBF6
# define WALL_COLOR 0x7F5283
# define RAY_COLOR 0xA6D1E6
# define CASTING_RAYS_COLOR 0xCA4E79
# define WALL_STRIP_WIDTH  1
# define MAP_SCALE 0.25
# define BLACK_COLOR 0x000000
# define DOOR_COLOR 0xF29393

int		error(char *msg, t_pars *pars);
char	*get_next_line(int fd);
void	display(t_data *data);
void	init_win(t_data *data);
void	init_map_img(t_data *data);
void	init_player(t_data *data);
int		render(t_data *data);
void	render_player(t_data *data);
void	img_pix_put(t_img *img, int x, int y, int color);
void	put_rect(t_img *img, t_rect rect);
void	init_player(t_data *data);
void	init_cast_ray(t_cast_ray *cast_ray, float angle);
void	dda(t_data *data, t_ray ray);
void	render_line(t_data *data, t_cast_ray *cast_ray, int ray_id);
void	init_direction_ray(t_data *data);
void	init_texture(t_data *data);
void	set_ray_rotate_angle(t_data *data);
void	init_direction_ray(t_data *data);
void	init_player_corr(t_data *data);
void	init_img_h_w(t_data *data);
void	set_text_addr(t_data *data);
void	put_rect(t_img *img, t_rect rect);
void	draw_direction_ray(t_data *data);

#endif