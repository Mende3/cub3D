#include "../../includes/cub3D.h"

void assign_color (char *color, t_game *game, char *key)
{
    if (ft_strcmp(key, "C") == 0)
    {
        free_subject (game->colors.color_c);
        game->colors.color_c = ft_strdup(color);
    }
    else if (ft_strcmp(key, "F") == 0)
    {
        free_subject (game->colors.color_f);
        game->colors.color_f = ft_strdup(color);
    }
}


/*
int is_valid_rgb(const char *str) {
    int r, g, b;
    return (sscanf(str, "%d,%d,%d", &r, &g, &b) == 3 && 
            r >= 0 && r <= 255 && 
            g >= 0 && g <= 255 && 
            b >= 0 && b <= 255);
}*/