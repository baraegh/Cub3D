/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 14:26:07 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/08/23 15:34:00 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/header.h"

void	dda(t_data *data, t_ray ray)
{
	t_int_point	dp;
	int			steps;
	t_point		p_inc;
	t_point		p;
	int			i;

	dp.x = ray.p1.x - ray.p0.x;
	dp.y = ray.p1.y - ray.p0.y;
	steps = abs(dp.y);
	if (abs(dp.x) > abs(dp.y))
		steps = abs(dp.x);
	p_inc.x = dp.x / (float) steps;
	p_inc.y = dp.y / (float) steps;
	p.x = ray.p0.x;
	p.y = ray.p0.y;
	i = 0;
	while (i <= steps)
	{
		img_pix_put(&data->map_img, round(p.x), round(p.y), ray.color);
		p.x += p_inc.x;
		p.y += p_inc.y;
		i++;
	}
}
