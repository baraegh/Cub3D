/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 11:48:30 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/07/29 11:55:06 by eel-ghan         ###   ########.fr       */
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
	float	x;
	float	y;
} t_point;

typedef	struct s_rect
{
	float	x;
	float	y;
	int		color;
	float	width;
	float	height;
}	t_rect;

typedef struct s_ray
{
	t_point p0;
	t_point p1;
	int		color;
} t_ray;

typedef struct s_cast_ray
{
	int	wall_hit_x;
	int	wall_hit_y;
	int	distance;
	int	is_facing_down;
	int	is_facing_up;
	int	is_facing_left;
	int	is_facing_right;
} t_cast_ray;

typedef struct s_player
{
	t_point	p;
	int		size;
	char	first_direction;
	int		turn_direction;
	float	rotate_angle;
	float	move_speed;
	float	rotate_speed;
	int		flag_angle_set;
} t_player;

typedef struct s_data
{
	void		*mlx;
	void		*mlx_win;
	char		**map;
	t_img		img;
	t_player	p;
	int			tile;
	int			num_rays;
	t_ray		ray;
} t_data;

#endif