#include "cub3D.h"

static int parse_map(char *path, t_parsing *utils, t_data *data);
static int parse_file(char *file);

int parsing(char *file, t_data *data, t_parsing *utils)
{
	if (parse_file(file) == FAILURE)
		return (FAILURE);
	if (parse_map(file, utils, data) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

static int parse_file(char *file)
{
	char *line;

	line = NULL;
	if (type_file_check(file) == FAILURE)
		return (FAILURE);
	if (is_empty_map(file, line) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
static int parse_map(char *path, t_parsing *utils, t_data *data)
{
	char *line;

	line = NULL;
	if (get_size_map(path, data, line) == FAILURE)
		return (FAILURE);
	if (fill_map(path, data, line) == FAILURE)
		return (FAILURE);
	if (fill_len_line_array(data) == FAILURE)
		return (FAILURE);
	if (is_valid_map(data, utils) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}