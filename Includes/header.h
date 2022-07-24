/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 12:04:56 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/07/24 11:49:16 by eel-ghan         ###   ########.fr       */
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
# define WIN_HEIGHT 512
# define PLAYER_COLOR 0xA6D1E6
# define PLAT_COLOR 0xFEFBF6
# define WALL_COLOR 0x7F5283

char	**check_map(char *str);
char	*get_next_line(int fd);
void	display(t_data *data);
void	render(t_data *data);
void	render_player(t_data *data, t_rect rect);
void	hooks(t_data *data);
void	img_pix_put(t_data *data, int x, int y, int color);
void	put_imgs(t_data *data, t_rect rect);
void	init_player(t_data * data);

#endif