#include "../../includes/cub3D.h"

int ft_close_esc (int keycode)
{
    if (keycode == ESC_KEY)
        return 1;
    return 0;
}

int ft_close_x (t_game *game)
{
    ft_exit_program (EXIT, "other", game);
    return 0;
}