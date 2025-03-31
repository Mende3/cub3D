#include "../../includes/cub3D.h"

// Função para tratar eventos de teclas
int key_listiner(int keycode, t_game *game)
{
    if (ft_close_esc(keycode))  // Função para verificar se a tecla ESC foi pressionada
        ft_exit_program(EXIT, "other", game);  // Fechar o programa
    else
        printf("%d\n", keycode);  // Imprimir o código da tecla pressionada

    return 0;
}

void init_win(t_game *game)
{
    game->mlx = mlx_init();
    game->win = mlx_new_window(game->mlx, WIDTH_WIN, HIGHT_WIN, "cub3D"); 
    game->assets.asset_ea_img = mlx_xpm_file_to_image(game->mlx, game->assets.asset_ea, &game->assets.asset_width, &game->assets.asset_height);
    game->assets.asset_so_img = mlx_xpm_file_to_image(game->mlx, game->assets.asset_so, &game->assets.asset_width, &game->assets.asset_height);
    game->assets.asset_we_img = mlx_xpm_file_to_image(game->mlx, game->assets.asset_we, &game->assets.asset_width, &game->assets.asset_height);
    game->assets.asset_no_img = mlx_xpm_file_to_image(game->mlx, game->assets.asset_no, &game->assets.asset_width, &game->assets.asset_height);
    if (!game->assets.asset_ea_img || !game->assets.asset_so_img || !game->assets.asset_we_img || !game->assets.asset_no_img)
    {
        ft_exit_program(FAIL_IMG, EXIT, game);
    }
    mlx_put_image_to_window(game->mlx, game->win, game->assets.asset_ea_img, 64, 64);
    mlx_put_image_to_window(game->mlx, game->win, game->assets.asset_so_img, 128, 64);
    mlx_put_image_to_window(game->mlx, game->win, game->assets.asset_we_img, 192, 64);
    mlx_put_image_to_window(game->mlx, game->win, game->assets.asset_no_img, 256, 64);
    mlx_key_hook(game->win, key_listiner, game);
    mlx_hook(game->win, 17, 0, ft_close_x, game);
    mlx_loop(game->mlx);
}
