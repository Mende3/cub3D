#include "../../includes/cub3D.h"

int is_rgb_nbr (int nbr)
{
    return (nbr >= 0 && nbr <= 255);
}

int is_color_rgb (char *str)
{
    int i;
    int temp;
    int count;
    char **rgb_colors;

    rgb_colors = ft_split (str, 44);
    count = 0;
    while (rgb_colors[count] != NULL)
        count++;
    if (count != 3)
        return FALSE;
    i = 0;
    while (rgb_colors[i])
    {
        if (!prime_is_digit (rgb_colors[i]))
            return FALSE;
        temp = ft_atoi (rgb_colors[i]);
        if (!is_rgb_nbr(temp))
            return FALSE;                
        i++;
    }
    return TRUE;
}

void assign_color (char *this_line, char *color, t_game *game, char *key)
{
    if (!is_color_rgb (color))
    {
        free (color);
        free (this_line);
        ft_putstr_fd (ERROR_RGB_COLOR, 1);
        ft_exit_error_on_file (EXIT, game);
    }
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