/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 14:26:07 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/07/28 15:17:51 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/header.h"

void	bresenham(t_data *data, t_point b_p, t_point e_p, int color)
{
	int		dx;
	int		dy;
	int		step_x;
	int		step_y;
	int		err;
	int		err_i;
	t_point	p;

	dx = fabs(e_p.x - b_p.x);
	dy = -fabs(e_p.y - b_p.y);
	step_x = 1;
	step_y = 1;
	if (b_p.x > e_p.x)
		step_x = -1;
	if (b_p.y > e_p.y)
		step_y = -1;
	err = dx + dy;
	p = b_p;
	while (1)
	{
		img_pix_put(data, p.x, p.y, color);
		err_i = 2 * err;
		if (err_i >= dy)
		{
			if (p.x == e_p.x)
				break ;
			err += dy;
			p.x += step_x;
		}
		if (err_i <= dx)
		{
			if (p.y == e_p.y)
				break ;
			err += dx;
			p.y += step_y;
		}
	}
}

void	dda(t_data *data, t_ray ray)
{
	// calculate dx & dy
	int dx = ray.p1.x - ray.p0.x;
	int dy = ray.p1.y - ray.p0.y;

	// calculate steps required for generating pixels
	int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
 
	// calculate increment in x & y for each steps
	float x_inc = dx / (float) steps;
	float y_inc = dy / (float) steps;
 
	// Put pixel for each step
	float x = ray.p0.x;
	float y = ray.p0.y;
	for (int i = 0; i <= steps; i++)
	{
		img_pix_put(data, round(x), round(y), ray.color);	// put pixel at (X,Y)
		x += x_inc;		// increment in x at each step
		y += y_inc;		// increment in y at each step
    }
}