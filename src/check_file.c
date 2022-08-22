/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 17:35:42 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/08/22 22:38:26 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/header.h"

t_pars	init_pars(char *line, int fd)
{
	t_pars	pars;

	// if (!line)
		// smt
	pars.line = line;
	pars.i = 0;
	pars.c = pars.line[pars.i];
	pars.fd = fd;
	pars.order_flag = 0;
	pars.no_f = 0;
	pars.so_f = 0;
	pars.we_f = 0;
	pars.ea_f = 0;
	pars.floor_f = 0;
	pars.ceilling_f = 0;
	pars.map_height = 0;
	pars.data.map = NULL;
	return (pars);
}

void	pars_advance(t_pars *pars)
{
	if (pars->c != '\0'
		&& pars->i < ft_strlen(pars->line) - 1)
	{
		pars->i++;
		pars->c = pars->line[pars->i];
	}
}

int	error(char  *msg, t_pars *pars)
{
	printf("Error\n %s\n", msg);
	if (pars)
		close(pars->fd);
	exit(0);
}

void	skip_space(t_pars *pars)
{
	while (pars->line[pars->i]
		&& pars->line[pars->i] != '\n'
		&& pars->line[pars->i] == ' ')
		pars->i++;
	pars->c = pars->line[pars->i];
}

char	*char_to_str(char c)
{
	char	*s;

	s = ft_calloc(2, sizeof(char));
	// if (!s)
		// return
	s[0] = c;
	return (s);
}

char	*get_tex_path(t_pars *pars)
{
	char	*tex_path;

	tex_path = ft_calloc(2, sizeof(char));
	// if (!tex_path)
		// return
	while (pars->c != '\n' && pars->c != '\0')
	{
		tex_path = ft_strjoin(tex_path, char_to_str(pars->c));
		// if (!tex_path)
		// return
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

int	check_nbr(char *s)
{
	int	i;
	if (ft_atoi(s) < 0 || ft_atoi(s) > 255)
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

t_color	check_color_value(t_pars *pars)
{
	char	**str;
	char	*s;
	int		i;

	s = ft_substr(pars->line, pars->i,
		ft_strlen(pars->line) - pars->i);
	str = ft_split(s, ',');
	// if (!str)
		// return
	i = 0;
	while (str[i])
	{
		if (!check_nbr(str[i]))
			error("Invalid color", pars);
		i++;
	}
	free(s);
	pars->order_flag++;
	return ((t_color){ft_atoi(str[0]), ft_atoi(str[1]), ft_atoi(str[2])});
}

t_color	check_floor_ceilling_elemt(t_pars *pars)
{
	pars_advance(pars);
	if (pars->c == ' ')
		skip_space(pars);
	else
		error("Invalid identifier", pars);
	if (nbr_of_comma(pars) == 2)
		return (check_color_value(pars));
	else
		error("Invalid color", pars);
	return ((t_color){-1, -1, -1});
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
			{
				if (i != 0
					&& (map[i - 1][j] != '1' && map[i - 1][j] != ' '))
					error("The map should be surrounded by walls !", pars);
				if(i != pars->map_height - 1
					&& (map[i + 1][j] != '1' && map[i + 1][j] != ' '))
					error("The map should be surrounded by walls !", pars);
				if (j != 0
					&& (map[i][j - 1] != '1' && map[i][j - 1] != ' '))
					error("The map should be surrounded by walls !", pars);
				if (j != ft_strlen(map[i]) - 1
					&& (map[i][j + 1] != '1' && map[i][j + 1] != ' '))
					error("The map should be surrounded by walls !", pars);
			}
			j++;
		}
		i++;
	}
}

char	**correct_map(char **map)
{
	int	i;
	int	length;
	int	line_len;

	i = 0;
	length = 0;
	line_len = 0;
	while (map[i])
	{
		line_len = ft_strlen(map[i]);
		if (line_len > length)
			length = line_len;
		i++;
	}
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
			if ((map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'W' || map[i][j] == 'E')
				&& !flag)
				flag = 1;
			else if ((map[i][j] == 'N' || map[i][j] == 'S'
					|| map[i][j] == 'W' || map[i][j] == 'E')
					&& flag)
				error("Found more then one start position!", pars);
			j++;
		}
		i++;
	}
	if (!flag)
		error("Start position not found!", pars);
}

void	check_map(t_pars *pars)
{
	int		i;
	char	*map;
	char	**two_dim_map;

	map = ft_strdup("\0");
	// if (!map)
		// return ;
	while (pars->line)
	{
		if (pars->line[0] == '\n')
		{
			error("Found newline in map element!", NULL);
			// re_init_pars(pars);
			// continue ;
		}
		i = 0;
		while (pars->line[i])
		{
			if (pars->line[i] == '1' || pars->line[i] == '0' || pars->line[i] == 'N'
				|| pars->line[i] == 'S' || pars->line[i] == 'W' || pars->line[i] == 'E'
				|| pars->line[i] == '\n' || pars->line[i] == ' ')
				map = ft_strjoin(map, char_to_str(pars->line[i]));
			else
				error("Invalid Map!", pars);
			i++;
		}
		if (pars->line[i - 2] != '1')
			error("The map should be surrounded by walls !", pars);
		pars->map_height++;
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

void	is_a_valid_elem(t_pars *pars)
{
	if (pars->c == ' ' && pars->order_flag != 6)
		skip_space(pars);
	if (pars->c == 'N' && !pars->no_f)
	{
		pars->data.no_tex_path = check_tex(pars, 'O');
		pars->no_f = 1;
	}
	else if (pars->c == 'S' && !pars->so_f)
	{

		pars->data.so_tex_path = check_tex(pars, 'O');
		pars->so_f = 1;
	}
	else if (pars->c == 'W' && !pars->we_f)
	{
		pars->data.we_tex_path = check_tex(pars, 'E');
		pars->we_f = 1;
	}
	else if (pars->c == 'E' && !pars->ea_f)
	{
		pars->data.ea_tex_path = check_tex(pars, 'A');
		pars->ea_f = 1;
	}
	else if (pars->c == 'F' && !pars->floor_f)
	{
		pars->data.floor_color = check_floor_ceilling_elemt(pars);
		pars->floor_f = 1;
	}
	else if (pars->c == 'C' && !pars->ceilling_f)
	{
		pars->data.ceilling_color = check_floor_ceilling_elemt(pars);
		pars->ceilling_f = 1;
	}
	else if (pars->c == '\n')
		return ;
	else if (pars->order_flag == 6)
		check_map(pars);
	else
		error("Invalid file!", pars);
}

t_data	check_file(char *path)
{
	t_pars	pars;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		error("file not found!", NULL);
	pars = init_pars(get_next_line(fd), fd);
	while (pars.line)
	{
		if (pars.line[0] == '\n')
		{
			re_init_pars(&pars);
			continue ;
		}
		is_a_valid_elem(&pars);
		re_init_pars(&pars);
	}
	close(pars.fd);
	if (pars.order_flag == 6 && !pars.data.map)
		error("Map  element is missing!", NULL);
	return (pars.data);
}