/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:30:53 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/09/01 16:33:38 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/header.h"

int	check_color_util(t_pars *pars, char **str)
{
	int		color;

	color = rgb((t_color){ft_atoi(str[0]), ft_atoi(str[1]), ft_atoi(str[2])});
	free(str[0]);
	free(str[1]);
	free(str[2]);
	free(str);
	pars->order_flag++;
	return (color);
}
