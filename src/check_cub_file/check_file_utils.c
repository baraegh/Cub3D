/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 13:50:13 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/09/01 16:33:52 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/header.h"

void	check_first_last_line(t_pars *pars, char **map, int index)
{
	int	i;

	i = 0;
	while (map[index][i])
	{
		if (map[index][i] != '1' && map[index][i] != ' ')
			error("The map should be surrounded by walls !", pars);
		i++;
	}
}

int	check_nbr(char *s)
{
	int	i;

	if (ft_atoi(s) < 0 || ft_atoi(s) > 255
		|| s[0] == '\n')
		return (0);
	i = 0;
	while (s[i])
	{
		if ((s[i] < '0' || s[i] > '9')
			&& s[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	check_color_value(t_pars *pars)
{
	char	**str;
	char	*s;
	int		i;

	s = ft_substr(pars->line, pars->i,
			ft_strlen(pars->line) - pars->i);
	str = ft_split(s, ',');
	free(s);
	if (!str)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (!check_nbr(str[i]))
			error("Invalid color!", pars);
		i++;
	}
	if (i != 3)
		error("Invalid color!", pars);
	return (check_color_util(pars, str));
}

int	check_floor_ceilling_elemt(t_pars *pars)
{
	int	color;

	pars_advance(pars);
	if (pars->c == ' ')
		skip_space(pars);
	else
		error("Invalid identifier", pars);
	if (nbr_of_comma(pars) == 2)
	{
		color = check_color_value(pars);
		if (color == -1)
			error("Invalid color!", pars);
		return (color);
	}
	else
		error("Invalid color", pars);
	return (-1);
}

void	re_init_pars(t_pars *pars)
{
	free(pars->line);
	pars->line = get_next_line(pars->fd);
	if (!pars->line)
		return ;
	pars->i = 0;
	pars->c = pars->line[pars->i];
}
