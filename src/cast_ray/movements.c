/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiala <gkiala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:36:48 by gkiala            #+#    #+#             */
/*   Updated: 2025/04/19 12:29:23 by gkiala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int ft_arrlen(char **arr)
{
    int i = 0;
    while (arr[i])
        i++;
    return (i);
}

void move_player(t_game *game, int keycode)
{
    double next_x = game->pos_x;
    double next_y = game->pos_y;

    if (keycode == W_KEY)
    {
        next_x += game->dir_x * game->move_speed;
        next_y += game->dir_y * game->move_speed;
    }
    else if (keycode == S_KEY)
    {
        next_x -= game->dir_x * game->move_speed;
        next_y -= game->dir_y * game->move_speed;
    }
    else if (keycode == A_KEY)
    {
        next_x -= game->plane_x * game->move_speed;
        next_y -= game->plane_y * game->move_speed;
    }
    else if (keycode == D_KEY)
    {
        next_x += game->plane_x * game->move_speed;
        next_y += game->plane_y * game->move_speed;
    }
    else
        return;

    // Proteção antes de acessar o mapa
    int map_height = ft_arrlen(game->map);
    int map_width = ft_strlen(game->map[0]);

    int x_check = (int)next_x;
    int y_check = (int)next_y;

    // Verifica se a posição Y está dentro dos limites
    if (y_check >= 0 && y_check < map_height &&
        (int)game->pos_x >= 0 && (int)game->pos_x < map_width &&
        game->map[y_check][(int)game->pos_x] != '1')
        game->pos_y = next_y;

    // Verifica se a posição X está dentro dos limites
    if ((int)game->pos_y >= 0 && (int)game->pos_y < map_height &&
        x_check >= 0 && x_check < map_width &&
        game->map[(int)game->pos_y][x_check] != '1')
        game->pos_x = next_x;
}


void rotate_camera(t_game *game, int keycode)
{
    double old_dir_x;
    double old_plane_x;
    double rot_speed = 0.02;
    
    if (keycode == LEFT_KEY)
    {
        old_dir_x = game->dir_x;
        old_plane_x = game->plane_x;

        game->dir_x = game->dir_x * cos(-rot_speed) - game->dir_y * sin(-rot_speed);
        game->dir_y = old_dir_x * sin(-rot_speed) + game->dir_y * cos(-rot_speed);

        game->plane_x = game->plane_x * cos(-rot_speed) - game->plane_y * sin(-rot_speed);
        game->plane_y = old_plane_x * sin(-rot_speed) + game->plane_y * cos(-rot_speed);
    }
    else if (keycode == RIGHT_KEY)
    {
        old_dir_x = game->dir_x;
        old_plane_x = game->plane_x;

        game->dir_x = game->dir_x * cos(rot_speed) - game->dir_y * sin(rot_speed);
        game->dir_y = old_dir_x * sin(rot_speed) + game->dir_y * cos(rot_speed);

        game->plane_x = game->plane_x * cos(rot_speed) - game->plane_y * sin(rot_speed);
        game->plane_y = old_plane_x * sin(rot_speed) + game->plane_y * cos(rot_speed);
    }
}

int key_press(int keycode, t_game *game)
{
    if (keycode == ESC_KEY)
        ft_exit_program(EXIT, "ESC pressed", game);
    else if (keycode == W_KEY)
        game->keys.w = 1;
    else if (keycode == S_KEY)
        game->keys.s = 1;
    else if (keycode == A_KEY)
        game->keys.a = 1;
    else if (keycode == D_KEY)
        game->keys.d = 1;
    else if (keycode == LEFT_KEY)
        game->keys.left = 1;
    else if (keycode == RIGHT_KEY)
        game->keys.right = 1;
    return (0);
}

int key_release(int keycode, t_game *game)
{
    if (keycode == W_KEY)
        game->keys.w = 0;
    else if (keycode == S_KEY)
        game->keys.s = 0;
    else if (keycode == A_KEY)
        game->keys.a = 0;
    else if (keycode == D_KEY)
        game->keys.d = 0;
    else if (keycode == LEFT_KEY)
        game->keys.left = 0;
    else if (keycode == RIGHT_KEY)
        game->keys.right = 0;
    return (0);
}

void update_keys(t_game *game)
{
    if (game->keys.w)
        move_player(game, W_KEY);
    if (game->keys.s)
        move_player(game, S_KEY);
    if (game->keys.a)
        move_player(game, A_KEY);
    if (game->keys.d)
        move_player(game, D_KEY);
    if (game->keys.left)
        rotate_camera(game, LEFT_KEY);
    if (game->keys.right)
        rotate_camera(game, RIGHT_KEY);
}
