#ifndef CUB3D_STRUCT
# define CUB3D_STRUCT

typedef struct s_game t_game;
typedef struct s_assets t_assets;

typedef struct s_game
{
    void    *mlx;
    void    *win;
    char    **map;
    int     map_width;
    int     map_heigth;
} t_game;

typedef struct s_assets
{
    void    *bg_ground;
    void    *bg_well;
} t_assets;

#endif
