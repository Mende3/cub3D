#include "../../includes/cub3D.h"

int	is_rgb_nbr(int nbr)
{
    return (nbr >= 0 && nbr <= 255);
}

int	is_color_rgb(char *str)
{
    int		i;
    int		result;
    int		temp;
    char	**rgb_colors;

    i = 0;
    int result = TRUE;
    rgb_colors = ft_split(str, 44);
    while (rgb_colors[i] != NULL)
        i++;
    if (i != 3)
        result = FALSE;
    else
    {
        i = 0;
        while (rgb_colors[i] && result)
        {
            if (!prime_is_digit(rgb_colors[i]))
                result = FALSE;
            else
            {
                temp = ft_atoi(rgb_colors[i]);
                if (!is_rgb_nbr(temp))
                    result = FALSE;
            }
            i++;
        }
    }
    free_matrix(rgb_colors);
    return result;
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
