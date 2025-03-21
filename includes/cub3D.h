#ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "../minilibx-linux/mlx.h"
#include "../libft/libft.h"
#include "cub3D_struct.h"


// Códigos ANSI para cores
#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN    "\033[1;36m"
#define WHITE   "\033[1;37m"

//utils
# define WIDTH_WIN 1600
# define HIGHT_WIN 800
# define BUFFER_SIZE 42

//numbers
# define FALSE 0
# define TRUE 1
# define ESC_KEY 65307

//Messages
# define EXIT RED "Feichando o programa.\n" RESET
# define NO_ARG CYAN "Error\nPasse o dir de um mapa.\n" RESET
# define NO_EXT CYAN "Error\nextensao não identificada.\n" RESET
# define NO_FILE CYAN "Error\nArquivo não existente.\n" RESET
# define INVALID_MAP RED "Mapa inválido.\n" RESET
# define EMPTY_MAP CYAN "Error\nMapa inválido ou vasio.\n" RESET
# define NOT_FOUND CYAN "Error\nO mapa deve ter um indicador de jogador! Encontrado:" RESET
# define PLAYER_NOT_FOUND CYAN "Error\nJogar não encontrado no mapa\n" RESET

//chekc_utils.c
int extension_checker (const char *arg, const char *ext);
int ft_strcmp (const char *s1,const char *s2);

//exit_program.c
void ft_exit_program (char *str, char *str2, t_game *game);
void exit_check_error (char *str);

//init_win.c
void init_win (char *arg, t_game *game);
int ft_close_x (t_game *game);

//close_win
int ft_close_esc (int keycode);

//ft_free_program
void    ft_free_program (t_game *game);

//ft_get_next_line
char	*get_next_line(int fd);

//file_process.c
int ft_open_file (char *path, t_game *game);
int read_file (char *line, t_game *game);

//render_assets
void render_assets (t_game *game);

//validations_map
int validate_map(t_game *game);

#endif