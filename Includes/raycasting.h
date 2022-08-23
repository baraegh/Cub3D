/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 16:43:53 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/08/23 16:51:43 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

void	cast_rays(t_data *data);
void	cast_ray(t_data *data, float angle, int ray_id);
void	init_horz_par(t_par *par, t_data *data, t_cast_ray cast_ray);
void	init_vert_par(t_par *par, t_data *data, t_cast_ray cast_ray);
float	normalize_angle(float angle);
void	compare_distances(t_data *data, t_par *par, t_cast_ray *cast_ray);
void	cal_vert_distance(t_par *par, t_cast_ray cast_ray, t_data *data);
void	cal_vert_distance_util(t_data *data, t_par *par, int x_offset);
void	set_vert_distance(t_par *par, t_data *data);
void	cal_horz_distance(t_par *par, t_cast_ray cast_ray, t_data *data);
void	cal_horz_distance_util(t_data *data, t_par *par, int y_offset);
void	set_horz_distance(t_par *par, t_data *data);
float	get_distance(t_point p0, t_point p1);
void	set_texture(t_data *data, t_cast_ray *cast_ray, int flag);
void	compare_distances(t_data *data, t_par *par, t_cast_ray *cast_ray);

#endif