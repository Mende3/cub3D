#include "../includes/cub3D.h"

void ft_free_program (t_game *game)
{
    if (game)
    {
        if (game->mlx)
        {
            mlx_destroy_window (game->mlx, game->win);
            mlx_destroy_display (game->mlx);
            free (game->mlx);
        }
        free (game);
    }
}