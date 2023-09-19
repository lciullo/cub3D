#ifndef LISA_H
# define LISA_H

int parsing(char *file, t_data *data);
int read_map(char *path, t_data *data);
int is_hedge(char *line);
#endif