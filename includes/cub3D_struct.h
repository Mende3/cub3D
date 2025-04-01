#ifndef CUB3D_STRUCT
# define CUB3D_STRUCT

typedef struct s_game t_game;
typedef struct s_assets t_assets;
typedef struct s_mark_cors t_mark_cors;
typedef struct s_colors t_colors;
typedef struct s_controls_num t_cn;

typedef struct s_controls_num
{
    int free_asset_path;
} t_cn;

typedef struct s_colors
{
    char *color_f;
    char *color_c;
    int     count_f;
    int     count_c;
    int     total_colors;
} t_colors;

typedef struct s_player
{    
    int     count_n;
    int     count_s;
    int     count_e;
    int     count_w;
} t_palyer;

typedef struct s_mark_cors
{
    int     no;
    int     so;
    int     we;
    int     ea;
    int     total_cors;
} t_mark_cors;

typedef struct s_assets
{
    char    *asset_no;
    char    *asset_so;
    char    *asset_ea;
    char    *asset_we;
    int     asset_width;
    int     asset_height;
    void    *asset_so_img;
    void    *asset_no_img;
    void    *asset_ea_img;
    void    *asset_we_img;
} t_assets;



typedef struct s_game
{
    void    *mlx;
    void    *win;
    char    *file_name;
    char    **map;
    int     map_width;
    int     map_heigth;
    t_mark_cors mark_cors;
    int     player_x;
    int     player_y;
    t_palyer    player;
    t_assets    assets;
    t_colors    colors;
    t_cn        cn;
} t_game;

#endif
