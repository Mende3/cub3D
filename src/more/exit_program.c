#include "../../includes/cub3D.h"

void exit_check_error (char *str)
{
    ft_putstr_fd (str, 2);
    exit (1);
}

void ft_exit_program (char *str, char *str2, t_game *game)
{   
    if (str2)
    {
        if ((ft_strcmp (str2, NO_FILE) == 0 || ft_strcmp (str2, NO_EXT) == 0))
        {
            free (game);
            ft_putstr_fd (str2, 2);
        }
        else if (ft_strcmp (str2, INVALID_MAP) == 0)
        {
            ft_free_program (game);
            ft_putstr_fd (str2, 2);
        }
        else
            ft_free_program (game);
    }
    ft_putstr_fd (str, 2);
    exit (1);
}