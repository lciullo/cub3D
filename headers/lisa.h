#ifndef LISA_H
# define LISA_H

int	parsing(char *file, t_data *data, t_parsing *utils);
int	parse_map(char *path, t_parsing *utils, t_data *data);
int is_map(char *line);
int	is_empty(char *line);
int	ft_open(char *path);
#endif