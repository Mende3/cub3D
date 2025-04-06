#include "../../includes/cub3D.h"

int check_count (t_game *game)
{
    if (game->mark_cors.total_cors != 4 ||
        game->colors.total_colors != 2)
    {
        if (game->mark_cors.total_cors > 4 ||
            game->colors.total_colors > 2
        )
            ft_putstr_fd (T_BIGGER, 1);
        else if (game->mark_cors.total_cors < 4 ||
            game->colors.total_colors < 2)
            ft_putstr_fd (T_MINOR, 1);
        return FALSE;
    }
    return TRUE;
}