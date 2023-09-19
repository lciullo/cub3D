#ifndef LISA_H
# define LISA_H

int parsing(char *file, t_data *data);
int read_map(char *path, t_data *data);
int is_map(char *line);
int	is_empty(char *line);

typedef struct s_parsing {
	int size_map;
    int nb_colors;
    int nb_directions;                
}	t_parsing;



#endif