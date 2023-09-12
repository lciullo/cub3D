#ifndef CLEM_H
# define CLEM_H

int		launch_mlx(t_data *data);
int		quit_game(t_data *data);
void	print_error_messages(int error_code);
void	hook(t_data *data);
int		key_hook(int key_code, t_data *data);
#endif