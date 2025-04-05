#include "../../includes/cub3D.h"


void free_map(char **map)
{
    free(map);
}

void free_subject (char *subject)
{
    if (subject)
        free (subject);
}

void free_colors (t_game *game)
{
    if (game->colors.color_c)
        free (game->colors.color_c);
    if (game->colors.color_f)
        free (game->colors.color_f);
}

void free_cors (t_game *game)
{
    if (game->assets.asset_ea)
        free (game->assets.asset_ea);
    if (game->assets.asset_no)
        free (game->assets.asset_no);
    if (game->assets.asset_so)
        free (game->assets.asset_so);
    if (game->assets.asset_we)
        free (game->assets.asset_we);    
    game->assets.asset_no = NULL;
    game->assets.asset_so = NULL;
    game->assets.asset_we = NULL;
    game->assets.asset_ea = NULL;
}

void ft_free_program(t_game *game)
{
    if (game)
    {
        if (game->map)
            free_map(game->map);
        free_cors (game);
        free_colors (game);
        if (game->mlx)
        {
            if (game->assets.asset_so_img)
                mlx_destroy_image(game->mlx, game->assets.asset_so_img);
            if (game->assets.asset_no_img)
                mlx_destroy_image(game->mlx, game->assets.asset_no_img);
            if (game->assets.asset_ea_img)
                mlx_destroy_image(game->mlx, game->assets.asset_ea_img);
            if (game->assets.asset_we_img)
                mlx_destroy_image(game->mlx, game->assets.asset_we_img);
            if (game->win)
                mlx_destroy_window(game->mlx, game->win);
            mlx_destroy_display(game->mlx);
            free(game->mlx);
        }
        free(game);
    }
}

