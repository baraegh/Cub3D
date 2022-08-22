/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 17:35:42 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/08/22 15:05:19 by eel-ghan         ###   ########.fr       */
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

int	error(char  *msg)
{
	printf("Error\n %s\n", msg);
	// return (0);
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

int	check_tex(t_pars *pars, char c)
{
	pars_advance(pars);
	if (pars->c != c)
		return (error("Invalid identifier"));
	else
		pars_advance(pars);
	if (pars->c == ' ')
			skip_space(pars);
	else
		return (error("Invalid identifier"));
	printf("tex: %s\n", get_tex_path(pars));
	pars->order_flag++;
	return (1);
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
		if (s[i] < '0' || s[i] > '9')
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
		(ft_strlen(pars->line) - 1) - pars->i);
	str = ft_split(s, ',');
	// if (!str)
		// return
	i = 0;
	while (str[i])
	{
		if (!check_nbr(str[i]))
			return (error("Invalid color"));
		i++;
	}
	i = 0;
	printf("color: ");
	while (str[i])
	{
		printf("%d ", ft_atoi(str[i]));
		i++;
	}
	printf("\n");
	pars->order_flag++;
	return (1);
}

int	check_floor_ceilling_elemt(t_pars *pars)
{
	pars_advance(pars);
	if (pars->c == ' ')
		skip_space(pars);
	else
		return (error("Invalid identifier"));
	if (nbr_of_comma(pars) == 2)
		return (check_color_value(pars));
	else
		return (error("Invalid color"));
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

void	check_first_last_line(char **map, int index)
{
	int	i;

	i = 0;
	while (map[index][i])
	{
		if (map[index][i] != '1' && map[index][i] != ' ')
			error("The map should be surrounded by walls !");
		i++;
	}
}

void	check_first_column(char **map)
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
				error("The map should be surrounded by walls !");
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

	check_first_last_line(map, 0);
	check_first_last_line(map, pars->map_height - 1);
	check_first_column(map);
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
					error("The map should be surrounded by walls !");
				if(i != pars->map_height - 1
					&& (map[i + 1][j] != '1' && map[i + 1][j] != ' '))
					error("The map should be surrounded by walls !");
					// printf("here\n");
				if (j != 0
					&& (map[i][j - 1] != '1' && map[i][j - 1] != ' '))
					error("The map should be surrounded by walls !");
				if (j != ft_strlen(map[i]) - 1
					&& (map[i][j + 1] != '1' && map[i][j + 1] != ' '))
					error("The map should be surrounded by walls !");
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
		i = 0;
		while (pars->line[i])
		{
			if (pars->line[i] == '1' || pars->line[i] == '0' || pars->line[i] == 'N'
				|| pars->line[i] == 'S' || pars->line[i] == 'W' || pars->line[i] == 'E'
				|| pars->line[i] == '\n' || pars->line[i] == ' ')
				map = ft_strjoin(map, char_to_str(pars->line[i]));
			else
				error("Invalid Map!");
			i++;
		}
		if (pars->line[i - 2] != '1')
			error("The map should be surrounded by walls !");
		pars->map_height++;
		re_init_pars(pars);
	}
	two_dim_map = ft_split(map, '\n');
	free(map);
	two_dim_map = correct_map(two_dim_map);
	i = 0;
	while (two_dim_map[i])
	{
		printf("|%s|\n", two_dim_map[i]);
		i++;
	}
	check_is_surrounded_by_walls(pars, two_dim_map);
}

void	is_a_valid_elem(t_pars *pars)
{
	if (pars->c == ' ' && pars->order_flag != 6)
		skip_space(pars);
	if (pars->c == 'N' && !pars->no_f)
		pars->no_f = check_tex(pars, 'O');
	else if (pars->c == 'S' && !pars->so_f)
		pars->so_f = check_tex(pars, 'O');
	else if (pars->c == 'W' && !pars->we_f)
		pars->we_f = check_tex(pars, 'E');
	else if (pars->c == 'E' && !pars->ea_f)
		pars->ea_f = check_tex(pars, 'A');
	else if (pars->c == 'F' && !pars->floor_f)
		pars->floor_f = check_floor_ceilling_elemt(pars);
	else if (pars->c == 'C' && !pars->ceilling_f)
		pars->ceilling_f = check_floor_ceilling_elemt(pars);
	else if (pars->c == '\n')
		return ;
	else if (pars->order_flag == 6)
		check_map(pars);
	else
		error("Invalid file!");
}

void	check_file(char *path)
{
	t_pars	pars;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		error("file not found!");
		return ;
	}
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
}