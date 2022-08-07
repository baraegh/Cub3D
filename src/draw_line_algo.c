/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 14:26:07 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/08/02 18:51:33 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/header.h"

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
		img_pix_put(&data->map_img, round(x), round(y), ray.color);	// put pixel at (X,Y)
		x += x_inc;		// increment in x at each step
		y += y_inc;		// increment in y at each step
    }
}