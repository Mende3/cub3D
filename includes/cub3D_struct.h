#ifndef CUB3D_STRUCT
# define CUB3D_STRUCT

typedef struct s_game t_game;
typedef struct s_assets t_assets;

typedef struct s_player
{    
    int     count_n;
    int     count_s;
    int     count_e;
    int     count_w;
} t_palyer;


typedef struct s_game
{
    void    *mlx;
    void    *win;
    char    **map;
    int     map_width;
    int     map_heigth;
    int     player_x;
    int     player_y;
    t_palyer player; 
} t_game;

typedef struct s_assets
{
    void    *bg_ground;
    void    *bg_well;
} t_assets;

#endif
