/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 11:48:30 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/07/24 12:35:52 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct	s_img {
	void	*img;
	char	*addr;
	int		line_length;
	int		endian;
	int		bpp;
	int		width;
	int		height;
} t_img;

typedef struct s_xpm_img
{
	void	*img;
	char	*path;
	int		img_width;
	int		img_height;
} t_xpm_img;

typedef struct s_size
{
	int		win_size;
	int		win_width;
	int		win_height;
	int		nbr_x;
	int		nbr_y;
} t_size;

typedef struct s_point
{
	int	x;
	int	y;
} t_point;

typedef	struct s_rect
{
	float	x;
	float	y;
	int		color;
	float	width;
	float	height;
}	t_rect;

typedef struct s_data
{
	void		*mlx;
	void		*mlx_win;
	char		**map;
	t_img		img;
	char		p_direction;

	char	**player_matrix;

	t_size	win;
} t_data;

#endif