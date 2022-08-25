/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 11:48:30 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/08/25 18:09:43 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_img {
	void	*img;
	char	*addr;
	int		line_length;
	int		endian;
	int		bpp;
	int		width;
	int		height;
}	t_img;

typedef struct s_xpm_img
{
	void	*img;
	char	*path;
	int		img_width;
	int		img_height;
}	t_xpm_img;

typedef struct s_size
{
	int	win_size;
	int	win_width;
	int	win_height;
	int	nbr_x;
	int	nbr_y;
}	t_size;

typedef struct s_point
{
	float	x;
	float	y;
}	t_point;

typedef struct s_int_point
{
	int	x;
	int	y;
}	t_int_point;

typedef struct s_rect
{
	float	x;
	float	y;
	int		color;
	float	width;
	float	height;
}	t_rect;

typedef struct s_ray
{
	t_point	p0;
	t_point	p1;
	int		color;
}	t_ray;

typedef struct s_cast_ray
{
	t_point	the_hit_point;
	float	distance;
	int		is_facing_down;
	int		is_facing_up;
	int		is_facing_left;
	int		is_facing_right;
	int		is_vert_hit;
	float	angle;
	int		color;
}	t_cast_ray;

typedef struct s_player
{
	t_point	p;
	t_point	step;
	t_point	move_l_r;
	float	fov_angle;
	int		size;
	char	first_direction;
	int		turn_direction;
	float	rotate_angle;
	float	move_speed;
	float	rotate_speed;
	int		flag_angle_set;
	int		open_door;
}	t_player;

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
	int		found_a_wall;
	float	horz_wall_distance;
	float	vert_wall_distance;
	int		wall_flag;
	int		is_wall_vert_hit;
	float	wall_distance;
	int		flag;
}	t_par;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_data
{
	void		*mlx;
	void		*mlx_win;
	char		**map;
	char		*no_tex_path;
	char		*so_tex_path;
	char		*we_tex_path;
	char		*ea_tex_path;
	int			floor_color;
	int			ceilling_color;
	t_img		map_img;
	t_img		no_tex;
	t_img		so_tex;
	t_img		we_tex;
	t_img		ea_tex;
	t_img		texture;
	int			render;
	t_player	p;
	int			num_rays;
	t_ray		ray;
}	t_data;

typedef struct s_pars
{
	char	*line;
	int		i;
	char	c;
	int		order_flag;
	int		fd;
	int		no_f;
	int		so_f;
	int		we_f;
	int		ea_f;
	int		floor_f;
	int		ceilling_f;
	int		map_height;
	t_data	data;
}	t_pars;

typedef struct s_line
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
}	t_line;

#endif
