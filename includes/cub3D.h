#ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>
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
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define LEFT_KEY 65361
# define RIGHT_KEY 65363


//Messages
# define CLAMP(x, low, high) ((x) < (low) ? (low) : ((x) > (high) ? (high) : (x)))
# define EXIT RED "Feichando o programa.\n" RESET
# define NO_ARG CYAN "Error\nPasse o dir de um mapa.\n" RESET
# define NO_EXT CYAN "Error\nextensao não identificada.\n" RESET
# define NO_FILE CYAN "Error\nArquivo não existente.\n" RESET
# define INVALID_MAP RED "Mapa inválido.\n" RESET
# define EMPTY_MAP CYAN "Error\nMapa inválido ou vasio.\n" RESET
# define NOT_FOUND CYAN "Error\nO mapa deve ter um indicador de jogador! Encontrado:" RESET
# define PLAYER_NOT_FOUND CYAN "Error\nJogar não encontrado no mapa\n" RESET
# define FAIL_IMG CYAN "Error\nFalha ao carregar imagem.\n" RESET
# define T_BIGGER CYAN "Error\nHá assets ou cores repetidas.\n" RESET
# define T_MINOR CYAN "Error\nHá menos assets ou cores.\n" RESET
# define NO_VALID CYAN "Error\nArquivo não validado.\n" RESET
# define NO_CHAR_MAP CYAN "Error\nMapa com caracteres inválidos.\n" RESET
# define ERROR_EXT_ASSET CYAN "Error\nErro na extenção de um ou mais arquivos asset.\n" RESET
# define ERROR_RGB_COLOR CYAN "Error\nAs duas ou uma das cores não está no padrão RGB.\n" RESET
# define EMPTY_FST_LINE CYAN "Error\nA primeira linha do mapa está vaiza.\n" RESET
# define MORE_NATIVE_CHAR CYAN "Error\nDemasiados identificadores nativos.\n" RESET
# define IS_OTHER_CHAR CYAN "Error\nCaracteres estranhos identificados.\n" RESET
# define NO_ARROUND_WALLS CYAN "Error\nO mapa precisa estar cercado por parede.\n" RESET
# define SPACE_INTERNAL CYAN "Error\nEspaços no interior do mapa.\n" RESET
//chekc_utils.c

//exit_program.c
void ft_exit_error_on_file (char *str1, t_game *game);
void ft_exit_program (char *str, char *str2, t_game *game);
void exit_check_error (char *str);
//init_win.c
void init_win (t_game *game);
int ft_close_x (t_game *game);

//close_win
int ft_close_esc (int keycode);
//ft_free_program
void free_matrix (char **tem_matrix);
void    ft_free_program (t_game *game);
void free_subject (char *fsubject);
void free_cors (t_game *game);

//ft_get_next_line
char	*get_next_line(int fd);

//file_process
int ft_open_file (t_game *game);
int ft_read_file (char *line, t_game *game);
//utils
int is_empty_line(char *this_line);
int is_char_native_file (char *this_line);
int is_empty_after_identifier(char *line);
int is_other_char (char *this_line,  t_game *game);

//validation
int get_a_line (t_game *game);
int validation (t_game *game);

//assets_validation
void view_cors(char *this_line, t_game *game);
//assets_validation_utils
void assign_asset_path(char *this_line, char *file, t_game *game, char *key);

//color_validation
void view_colors(char *this_line, t_game *game);
//color_validation_utils
void assign_color(char *this_line, char *color, t_game *game, char *key);

//validation_map
int is_map_line(char *line);
int view_map(char *this_line, t_game *game, int *start_read);
//validation_map_utils
void find_player(t_game *game);
void view_player_on_map (t_game *game);
int is_char_valid (char *this_line, int i);
//validation_map_utils2
void	is_map_surrounded_by_walls(t_game *game);
//validation_map_utils3
void can_play (t_game *game);

//check_utils_one
int ft_isspace(int c);
int prime_is_digit (char *str);
int ft_strcmp (const char *s1,const char *s2);
char *ft_strstr(const char *haystack, const char *needle);
int extension_checker (const char *arg, const char *ext);
//check_utils_two
int check_count (t_game *game);

// cast_ray.
void render_frame(t_game *game);
int render_frame_wrapper(void *param);
void init_player_dir_and_plane(t_game *game, char orientation);
char *get_texture_addr(t_game *game, t_ray *ray);
unsigned int get_texture_pixel(char *addr, int x, int y, int line_length, int bpp);


//movements
void move_player(t_game *game, int keycode);
void rotate_camera(t_game *game, int keycode);
void update_keys(t_game *game);
int key_release(int keycode, t_game *game);
int key_press(int keycode, t_game *game);
int loop_hook(t_game *game);

#endif
