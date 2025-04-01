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
# define WIDTH_ASSET 64
# define HEIGHT_ASSET 64

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
# define FAIL_IMG CYAN "Error\nFalha ao carregar imagem.\n" RESET

//chekc_utils.c
int extension_checker (const char *arg, const char *ext);
int ft_strcmp (const char *s1,const char *s2);

//exit_program.c
void ft_exit_error_on_file (char *str1, char *str2, t_game *game);
void ft_exit_program (char *str, char *str2, t_game *game);
void exit_check_error (char *str);

//init_win.c
void init_win (t_game *game);
int ft_close_x (t_game *game);

//close_win
int ft_close_esc (int keycode);

//ft_free_program
void    ft_free_program (t_game *game);

//ft_get_next_line
char	*get_next_line(int fd);

//file_process.c
int ft_open_file (t_game *game);
int read_file (char *line, t_game *game);

//validations_map
int validate_map(t_game *game);
int validation_true (t_game *game);

//validation_map_utils1
void get_path_file(char *ptr, t_game *game, char *key);
int get_a_line (t_game *game);
void view_cors(char *this_line, t_game *game);
void view_colors(char *this_line, t_game *game);

//validation_map_utils2
void assign_asset_path(char *file, t_game *game, char *key);
void assign_color(char *color, t_game *game, char *key);
char *ft_strstr(const char *haystack, const char *needle);
int check_cors_count (t_game *game);
int check_colors_count (t_game *game);
int find_file(char *asset_path);


#endif