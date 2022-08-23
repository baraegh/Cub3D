/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 15:49:49 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/08/23 15:53:32 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

void	hooks(t_data *data);
int		is_a_wall(t_data *data, float x, float y);
void	move(t_data *data, int y, int x);
void	rotate_line(t_data *data);
int		is_a_door(t_data *data, float x, float y);
int		is_an_open_door(t_data *data, float x, float y);
void	open_door(t_data *data);
void	close_door(t_data *data);
int		ready_to_close_door(t_data *data);

#endif