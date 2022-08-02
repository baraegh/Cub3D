/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 12:04:56 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/08/02 17:25:26 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
# include "../src/libft/libft.h"
# include "mlx_keys.h"
# include "struct.h"

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
# define MAP_SCALE 0.3
# define COLOR 0xFFC18E

char	**check_map(char *str);
char	*get_next_line(int fd);
void	display(t_data *data);
void	init_win(t_data *data);
void	init_img(t_data *data);
void	init_player(t_data *data);
void	render(t_data *data);
void	render_player(t_data *data);
void	hooks(t_data *data);
void	img_pix_put(t_data *data, int x, int y, int color);
void	put_imgs(t_data *data, t_rect rect);
void	init_player(t_data * data);
void	dda(t_data *data, t_ray ray);
void	cast_rays(t_data *data);

#endif