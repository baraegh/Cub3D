/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 12:14:16 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/08/25 17:58:41 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/header.h"

void	check_cub(char *str)
{
	int		i;
	char	*cub;
	int		l;

	cub = "buc.";
	i = 0;
	while (str[i])
			i++;
	i--;
	l = 0;
	while (cub[l] != '\0')
	{
		if (cub[l] != str[i])
			error("Invalid file!", NULL);
		l++;
		i--;
	}
}

int	main(int ac, char **av)
{
	t_data	data;

	if (av[1])
		check_cub(av[1]);
	data = check_file(av[1]);
	if (ac == 2)
		display(&data);
	else
		error("Invalid arguments number!", NULL);
	return (0);
}
