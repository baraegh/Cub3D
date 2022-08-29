/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 14:59:56 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/08/29 17:17:32 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/header.h"

void	check_first_column(t_pars *pars, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == ' ')
				j++;
			else if (map[i][j] != '1')
				error("The map should be surrounded by walls !", pars);
			else
				break ;
		}
		i++;
	}
}

void	check_walls(int i, int j, t_pars *pars, char **map)
{
	if (i != 0
		&& (map[i - 1][j] != '1' && map[i - 1][j] != ' '))
		error("The map should be surrounded by walls !", pars);
	if (i != pars->map_height - 1
		&& (map[i + 1][j] != '1' && map[i + 1][j] != ' '))
		error("The map should be surrounded by walls !", pars);
	if (j != 0
		&& (map[i][j - 1] != '1' && map[i][j - 1] != ' '))
		error("The map should be surrounded by walls !", pars);
	if (j != ft_strlen(map[i]) - 1
		&& (map[i][j + 1] != '1' && map[i][j + 1] != ' '))
		error("The map should be surrounded by walls !", pars);
}

void	check_is_surrounded_by_walls(t_pars *pars, char **map)
{
	int	i;
	int	j;

	check_first_last_line(pars, map, 0);
	check_first_last_line(pars, map, pars->map_height - 1);
	check_first_column(pars, map);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == ' ')
				check_walls(i, j, pars, map);
			j++;
		}
		i++;
	}
}

int	get_map_len(char **map)
{
	int	i;
	int	line_len;
	int	len;

	line_len = 0;
	len = 0;
	i = 0;
	while (map[i])
	{
		line_len = ft_strlen(map[i]);
		if (line_len > len)
			len = line_len;
		i++;
	}
	return (len);
}

char	**correct_map(char **map)
{
	int	i;
	int	length;
	int	line_len;

	length = get_map_len(map);
	i = 0;
	while (map[i])
	{
		line_len = ft_strlen(map[i]);
		if (line_len < length)
		{
			while (line_len < length)
			{
				map[i] = ft_strjoin(map[i], " ");
				line_len++;
			}
		}
		i++;
	}
	return (map);
}
