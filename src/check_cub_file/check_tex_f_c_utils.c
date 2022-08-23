/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tex_f_c_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 14:01:23 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/08/23 14:01:42 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/header.h"

void	check_no_tex(t_pars *pars)
{
	pars->data.no_tex_path = check_tex(pars, 'O');
	pars->no_f = 1;
}

void	check_so_tex(t_pars *pars)
{
	pars->data.so_tex_path = check_tex(pars, 'O');
	pars->so_f = 1;
}

void	check_we_tex(t_pars *pars)
{
	pars->data.we_tex_path = check_tex(pars, 'E');
	pars->we_f = 1;
}

void	check_ea_tex(t_pars *pars)
{
	pars->data.ea_tex_path = check_tex(pars, 'A');
	pars->ea_f = 1;
}

void	check_floor(t_pars *pars)
{
	pars->data.floor_color = check_floor_ceilling_elemt(pars);
	pars->floor_f = 1;
}
