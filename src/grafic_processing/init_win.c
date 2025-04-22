/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiala <gkiala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 20:42:57 by gkiala            #+#    #+#             */
/*   Updated: 2025/04/19 11:46:17 by gkiala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int loop_hook(t_game *game)
{
    update_keys(game);
    render_frame(game);
    return (0);
}

void init_win(t_game *game)
{
    game->mlx = mlx_init();
    game->win = mlx_new_window(game->mlx, WIDTH_WIN, HIGHT_WIN, "cub3D"); 

    // Criação da imagem principal
    game->img.img = mlx_new_image(game->mlx, WIDTH_WIN, HIGHT_WIN);
    game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel, &game->img.line_length, &game->img.endian);

    // Carrega as texturas
    game->assets.asset_ea_img = mlx_xpm_file_to_image(game->mlx, game->assets.asset_ea, &game->assets.asset_width, &game->assets.asset_height);
    game->assets.asset_so_img = mlx_xpm_file_to_image(game->mlx, game->assets.asset_so, &game->assets.asset_width, &game->assets.asset_height);
    game->assets.asset_we_img = mlx_xpm_file_to_image(game->mlx, game->assets.asset_we, &game->assets.asset_width, &game->assets.asset_height);
    game->assets.asset_no_img = mlx_xpm_file_to_image(game->mlx, game->assets.asset_no, &game->assets.asset_width, &game->assets.asset_height);

    if (!game->assets.asset_ea_img || !game->assets.asset_so_img ||
        !game->assets.asset_we_img || !game->assets.asset_no_img)
    {
        game->cn.free_asset_path = 1;
        ft_exit_program(FAIL_IMG, EXIT, game);
    }

    // Pega o endereço dos dados das texturas
    game->assets.asset_ea_addr = mlx_get_data_addr(game->assets.asset_ea_img, &game->assets.asset_bpp, &game->assets.asset_line_len, &game->assets.asset_endian);
    game->assets.asset_so_addr = mlx_get_data_addr(game->assets.asset_so_img, &game->assets.asset_bpp, &game->assets.asset_line_len, &game->assets.asset_endian);
    game->assets.asset_we_addr = mlx_get_data_addr(game->assets.asset_we_img, &game->assets.asset_bpp, &game->assets.asset_line_len, &game->assets.asset_endian);
    game->assets.asset_no_addr = mlx_get_data_addr(game->assets.asset_no_img, &game->assets.asset_bpp, &game->assets.asset_line_len, &game->assets.asset_endian);

    // Hooks
    mlx_hook(game->win, 2, 1L << 0, key_press, game);      // key down
    mlx_hook(game->win, 3, 1L << 1, key_release, game);    // key up
    mlx_hook(game->win, 17, 0, ft_close_x, game);          // close window
    
    
    mlx_loop_hook(game->mlx, loop_hook, game);
    mlx_loop(game->mlx);
}


