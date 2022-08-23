/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_utils01.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 15:01:57 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/08/23 17:20:22 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/header.h"

int	rgb(t_color color)
{
	return ((color.r << 16) | (color.g << 8) | color.b);
}

char	*char_to_str(char c)
{
	char	*s;

	s = ft_calloc(2, sizeof(char));
	if (!s)
		return (NULL);
	s[0] = c;
	return (s);
}

char	*get_tex_path(t_pars *pars)
{
	char	*tex_path;

	tex_path = ft_calloc(2, sizeof(char));
	if (!tex_path)
		return (NULL);
	while (pars->c != '\n' && pars->c != '\0')
	{
		tex_path = ft_strjoin(tex_path, char_to_str(pars->c));
		if (!tex_path)
			return (NULL);
		pars_advance(pars);
	}
	return (tex_path);
}

char	*check_tex(t_pars *pars, char c)
{
	pars_advance(pars);
	if (pars->c != c)
		error("Invalid identifier", pars);
	else
		pars_advance(pars);
	if (pars->c == ' ')
		skip_space(pars);
	else
		error("Invalid identifier", pars);
	pars->order_flag++;
	return (get_tex_path(pars));
}

int	nbr_of_comma(t_pars *pars)
{
	int	i;
	int	nbr;

	i = pars->i;
	nbr = 0;
	while (pars->line[i] != '\n' && pars->line[i])
	{
		if (pars->line[i] == ',')
			nbr++;
		i++;
	}
	return (nbr);
}
