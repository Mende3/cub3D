/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:13:22 by gkiala            #+#    #+#             */
/*   Updated: 2025/03/20 13:13:25 by gkiala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int is_valid_map_char(char c)
{
    return (c == 'N' || c == '\n' || c == 'S' || c == 'E' || c == 'W' || c == '1' || c == '0');
}

void find_player(t_game *game)
{
    int y = 0;
    int x;

    while (game->map[y])
    {
        x = 0;
        while (game->map[y][x])
        {
            if (game->map[y][x] == 'N' || game->map[y][x] == 'S' ||
                game->map[y][x] == 'E' || game->map[y][x] == 'W')
            {
                game->player_x = x;
                game->player_y = y;
                return;
            }
            x++;
        }
        y++;
    }
    ft_exit_program(PLAYER_NOT_FOUND, NULL, game);
}

static int validate_map_chars(t_game *game)
{
    int x, y;

    if (!game->map || !game->map[0])
    {
        printf("%s\n", EMPTY_MAP);
        return (0);
    }

    y = 0;
    while (game->map[y])
    {
        x = 0;
        while (game->map[y][x])
        {
            if (!is_valid_map_char(game->map[y][x]))
            {
                printf(CYAN"Error\nCaracter errado '%c' no mapa em (%d, %d)\n"RESET, game->map[y][x], x, y);
                return (0);
            }
            if (game->map[y][x] == 'N') (game->player.count_n)++;
            else if (game->map[y][x] == 'S') (game->player.count_s)++;
            else if (game->map[y][x] == 'E') (game->player.count_e)++;
            else if (game->map[y][x] == 'W') (game->player.count_w)++;
            x++;
        }
        y++;
    }
    return (1);
}

int validate_map(t_game *game)
{   
    if (!validate_map_chars(game))
        ft_exit_program(EXIT, INVALID_MAP, game);

    if (( game->player.count_n +  game->player.count_s +  game->player.count_e +  game->player.count_w) != 1)
    {
        printf("%s N=%d, S=%d, E=%d, W=%d\n", NOT_FOUND,  game->player.count_n,  game->player.count_s,  game->player.count_e,  game->player.count_w);
        ft_exit_program(EXIT, INVALID_MAP, game);
    }

    find_player(game); // O jogador foi localizado

    return (1);
}