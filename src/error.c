/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 17:17:31 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/08/23 17:20:04 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/header.h"

int	error(char *msg, t_pars *pars)
{
	printf("Error\n %s\n", msg);
	if (pars)
		close(pars->fd);
	exit(0);
}