/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_distance.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 16:49:12 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/08/24 20:42:32 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/header.h"

void	set_horz_distance(t_par *par, t_data *data)
{
	if (par->found_a_wall)
		par->horz_wall_distance = get_distance(data->ray.p0,
				par->horz_wall_hit);
	else
		par->horz_wall_distance = MAXFLOAT;
}

void	set_vert_distance(t_par *par, t_data *data)
{
	if (par->found_a_wall)
		par->vert_wall_distance = get_distance(data->ray.p0,
				par->vert_wall_hit);
	else
		par->vert_wall_distance = MAXFLOAT;
}
