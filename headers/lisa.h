#ifndef LISA_H
# define LISA_H

/*Parsing*/
int	parsing(char *file, t_data *data, t_parsing *utils);
int	parse_map(char *path, t_parsing *utils, t_data *data);
/*Utils parsing*/
int	is_empty(char *line);
int	ft_open(char *path);
/*Utils fill map*/
int is_map(char *line);
int is_valid(char c);
/*Fill map*/
int get_size_map(char *path, t_parsing *utils, char *line);
int fill_map(char *path, t_parsing *utils, t_data *data, char *line);
int count_line(t_data *data, t_parsing *utils);
#endif