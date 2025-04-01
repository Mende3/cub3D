#include "../../includes/cub3D.h"

void assign_color (char *color, t_game *game, char *key) {
    if (ft_strcmp(key, "C") == 0) {
        game->colors.color_c = ft_strdup(color);
    } else if (ft_strcmp(key, "F") == 0) {
        game->colors.color_f = ft_strdup(color);
    }
    printf("%s\n", color);
}


int check_colors_count (t_game *game)
{
    game->colors.total_colors += (game->colors.count_c);
    game->colors.total_colors += (game->colors.count_f);


    printf ("%d\n", game->colors.total_colors);    

    if (game->colors.total_colors != 2)
        return FALSE;
    return TRUE;
}