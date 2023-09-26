#ifndef LISA_H
# define LISA_H

//===================== PARSING =====================

int	parsing(char *file, t_data *data, t_parsing *utils);

//==== File ====

int	type_file_check(char *file);
int	ft_open(char *path);
int is_empty_map(char *file, char *line);
//==== Map ====

// --- Utils map ---
int is_map(char *line);
int	is_empty_line(char *line);
int is_valid(char c);
// --- Fill map ---
int get_size_map(char *path, t_data *data, char *line);
int fill_map(char *path, t_data *data, char *line);
int fill_len_line_array(t_data *data);

//--- Is valid map ---
int is_valid_map(t_data *data, t_parsing *utils);

//--- Get position ---
void get_pos(t_data *data);
#endif