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
    char *new_color;
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

typedef struct s_key
{
    int w;
    int s;
    int a;
    int d;
    int left;
    int right;
} t_key;


typedef struct s_mark_cors
{
    char    *new_cors;
    int     no;
    int     so;
    int     we;
    int     ea;
    int     total_cors;
} t_mark_cors;

typedef struct s_assets
{
    char *asset_no;
    char *asset_so;
    char *asset_we;
    char *asset_ea;

    void *asset_no_img;
    void *asset_so_img;
    void *asset_we_img;
    void *asset_ea_img;

    char *asset_no_addr;
    char *asset_so_addr;
    char *asset_we_addr;
    char *asset_ea_addr;

    int asset_width;
    int asset_height;
    int asset_bpp;
    int asset_line_len;
    int asset_endian;
} t_assets;


typedef struct s_img
{
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}   t_img;

typedef struct s_ray
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	int		step_x;
	int		step_y;
	int		side;
}	t_ray;


typedef struct s_game
{
    void        *mlx;
    void        *win;
    char        *file_name;
    char        **map;
    int         map_width;
    int         map_heigth;
    t_mark_cors mark_cors;
    int         player_x;
    int         player_y;
    int         check_spaces;
    double      pos_x;      // posição exata do jogador
    double      pos_y;
    double      dir_x;      // direção de onde o jogador está a olhar
    double      dir_y;
    double      plane_x;    // vetor perpendicular à direção (define o FOV)
    double      plane_y;
    double      move_speed;
    double      rot_speed;
    t_key       keys;
    t_palyer    player;
    t_assets    assets;
    t_colors    colors;
    t_cn        cn;
    t_img       img;
} t_game;


#endif
