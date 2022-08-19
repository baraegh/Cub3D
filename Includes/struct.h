/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 11:48:30 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/08/19 20:24:16 by eel-ghan         ###   ########.fr       */
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
	t_point the_hit_point;
	float	distance;
	int		is_facing_down;
	int		is_facing_up;
	int		is_facing_left;
	int		is_facing_right;
	int		is_vert_hit;
	float	angle;
	int		color;
} t_cast_ray;

typedef struct s_player
{
	t_point	p;
	t_point	step;
	t_point	move_l_r;
	int		size;
	char	first_direction;
	int		turn_direction;
	float	rotate_angle;
	float	move_speed;
	float	rotate_speed;
	int		flag_angle_set;
	int		open_door;
} t_player;

typedef struct s_par
{
	float	x_intercept;
	float	y_intercept;

	float	x_step;
	float	y_step;

	float	next_touch_x; 
	float	next_touch_y;

	t_point	horz_wall_hit;
	t_point	vert_wall_hit;
	t_point	horz_door_hit;
	t_point	vert_door_hit;

	int		found_a_wall;
	int		found_a_door;
	int		there_is_a_door;
	
	float	horz_wall_distance;
	float	vert_wall_distance;
	float	vert_door_distance;
	float	horz_door_distance;
	
} t_par;

typedef struct s_data
{
	void		*mlx;
	void		*mlx_win;
	char		**map;
	t_img		map_img;
	t_img		no_tex;
	t_img		so_tex;
	t_img		we_tex;
	t_img		ea_tex;
	t_img		door_tex;
	t_img		texture;
	t_player	p;
	int			tile;
	int			num_rays;
	t_ray		ray;
	t_point		door_hit;
	int			door_is_open;
	time_t		door_opened_time;
 } t_data;

#endif