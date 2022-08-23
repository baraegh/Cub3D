/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 14:06:34 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/08/23 17:21:33 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/header.h"

int	check_condt_1(char **map, int flag, int i, int j)
{
	if ((map[i][j] == 'N' || map[i][j] == 'S'
		|| map[i][j] == 'W' || map[i][j] == 'E')
		&& !flag)
		return (1);
	return (0);
}

int	check_condt_2(char **map, int flag, int i, int j)
{
	if ((map[i][j] == 'N' || map[i][j] == 'S'
		|| map[i][j] == 'W' || map[i][j] == 'E')
		&& flag)
		return (1);
	return (0);
}

void	check_start_position(t_pars *pars, char **map)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	flag = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (check_condt_1(map, flag, i, j))
				flag = 1;
			else if (check_condt_2(map, flag, i, j))
				error("Found more then one start position!", pars);
			j++;
		}
		i++;
	}
	if (!flag)
		error("Start position not found!", pars);
}

char	*check_map_utils(t_pars *pars, char *map)
{
	int	i;

	i = 0;
	while (pars->line[i])
	{
		if (pars->line[i] == '1' || pars->line[i] == '0'
			|| pars->line[i] == 'N' || pars->line[i] == 'S'
			|| pars->line[i] == 'W' || pars->line[i] == 'E'
			|| pars->line[i] == '\n' || pars->line[i] == ' '
			|| pars->line[i] == '5' || pars->line[i] == '2')
			map = ft_strjoin(map, char_to_str(pars->line[i]));
		else
			error("Invalid Map!", pars);
		i++;
	}
	if (pars->line[i - 2] != '1')
		error("The map should be surrounded by walls !", pars);
	pars->map_height++;
	return (map);
}

void	check_map(t_pars *pars)
{
	char	*map;
	char	**two_dim_map;
	int		i;

	map = ft_strdup("\0");
	if (!map)
		return ;
	while (pars->line)
	{
		i = 0;
		if (pars->line[0] == '\n')
			error("Found newline in the map element!", NULL);
		map = check_map_utils(pars, map);
		re_init_pars(pars);
	}
	if (pars->map_height < 3)
		error("Invalid map!", pars);
	two_dim_map = ft_split(map, '\n');
	free(map);
	two_dim_map = correct_map(two_dim_map);
	check_is_surrounded_by_walls(pars, two_dim_map);
	check_start_position(pars, two_dim_map);
	pars->data.map = two_dim_map;
}
