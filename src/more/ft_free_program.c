#include "../../includes/cub3D.h"


void free_map(char **map)
{
    int i = 0;

    if (!map)
        return;
    while (map[i])
    {
        free(map[i]);
        i++;
    }
    free(map);
}

void ft_free_program (t_game *game)
{
   
    if (game)
    {
        if (game->map)
            free_map (game->map);

        if (game->mlx)
        {
            mlx_destroy_window (game->mlx, game->win);
            mlx_destroy_display (game->mlx);
            free (game->mlx);
        }
        free (game);
    }
}
