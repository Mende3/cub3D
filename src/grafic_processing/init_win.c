#include "../../includes/cub3D.h"

int key_listiner (int keycode, t_game *game)
{
    if (ft_close_esc (keycode))
        ft_exit_program (EXIT , "other", game);
    return 0;
}

void init_win (char *arg, t_game *game)
{
    (void)arg;
    game->mlx = mlx_init();
    game->win = mlx_new_window (game->mlx, WIDTH_WIN, HIGHT_WIN, "cub3D"); 
    mlx_key_hook (game->win, key_listiner, &game->mlx);
    mlx_hook(game->win, 17, 0, ft_close_x, game);
    mlx_loop (game->mlx);
}