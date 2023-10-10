/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lisa.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lciullo <lciullo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 09:58:31 by lciullo           #+#    #+#             */
/*   Updated: 2023/10/10 13:35:05 by lciullo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISA_H
# define LISA_H

//===================== PARSING =====================

int		parsing(char *file, t_data *data, t_parsing *utils);

//==== File ====

int		type_file_check(char *file);
int		ft_open(char *path);
int		is_empty_map(char *file, char *line);

//==== Map ====

// --- Utils map ---
int		is_map(char *line);
int		is_empty_line(char *line);
int		is_valid(char c);
char	**ft_copy_map(t_data *data);

// --- Fill map ---
int		get_size_map(char *path, t_data *data, char *line);
int		fill_map(char *path, t_data *data, char *line);
int		fill_len_line_array(t_data *data);

//--- Is valid map ---
int		is_one_player(t_data *data, t_parsing *utils);

//--- Get position ---
void	get_player_position(t_data *data);

//--- Is Map Closed ---
int		is_map_closed(t_data *data);
int		check_around(t_data *data, int y, int x, char **copy);
int		check_up(t_data *data, int y, int x, char **copy);
int		check_down(t_data *data, int y, int x, char **copy);
int		check_left(int y, int x, char **copy);
int		check_right(t_data *data, int y, int x, char **copy);
int		move_on_map(t_data *data, int y, int x, char **copy);

//==== Textures ====

// --- Read map ---
int		read_to_get_asset(char *path, t_parsing *utils, t_data *data);
int		is_right_asset_number(char *path, t_parsing *utils);
int		type_texture_check(t_parsing *utils, t_data *data);
int		asset_line_len(char *s);
char	*copy_asset(char *texture, char *s);
int		get_colors(t_parsing *utils, t_data *data);

// --- Free textures ---

void	free_textures(t_data *data);
void	clean_gnl(int fd, char *line);
void	free_asset(t_parsing *utils, t_data *data);
void	free_texture(char *texture);
void	free_all_colors(t_parsing *utils);
#endif