/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 13:53:13 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/08/23 17:19:39 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H

t_data	check_file(char *path);
void	is_a_valid_elem(t_pars *pars);
void	skip_space(t_pars *pars);
void	pars_advance(t_pars *pars);
t_pars	init_pars(char *line, int fd);
void	check_no_tex(t_pars *pars);
void	check_so_tex(t_pars *pars);
void	check_we_tex(t_pars *pars);
void	check_ea_tex(t_pars *pars);
void	check_floor(t_pars *pars);
int		check_nbr(char *s);
int		check_color_value(t_pars *pars);
int		check_floor_ceilling_elemt(t_pars *pars);
int		rgb(t_color color);
char	*char_to_str(char c);
char	*get_tex_path(t_pars *pars);
char	*check_tex(t_pars *pars, char c);
int		nbr_of_comma(t_pars *pars);
void	check_map(t_pars *pars);
char	*check_map_utils(t_pars *pars, char *map);
void	check_start_position(t_pars *pars, char **map);
int		check_condt_2(char **map, int flag, int i, int j);
int		check_condt_1(char **map, int flag, int i, int j);
char	**correct_map(char **map);
int		get_map_len(char **map);
void	check_is_surrounded_by_walls(t_pars *pars, char **map);
void	check_first_last_line(t_pars *pars, char **map, int index);
void	check_walls(int i, int j, t_pars *pars, char **map);
void	check_first_column(t_pars *pars, char **map);
void	re_init_pars(t_pars *pars);

#endif
