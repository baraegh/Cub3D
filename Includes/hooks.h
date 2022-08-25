/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 15:49:49 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/08/25 18:07:38 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

void	hooks(t_data *data);
int		is_a_wall(t_data *data, float x, float y);
void	move(t_data *data, int y, int x);
void	rotate_line(t_data *data);
void	free_data(t_data *data);

#endif