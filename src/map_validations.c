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
    ft_exit_program("Error: No player found on the map!\n", NULL, game); // Jogador não encontrado
}

static int validate_map_chars(t_game *game, int *count_n, int *count_s, int *count_e, int *count_w)
{
    int x, y;

    if (!game->map || !game->map[0])
    {
        printf("Error: Map is empty or invalid!\n");
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
                printf("Error: Invalid char '%c' in map at (%d, %d)\n", game->map[y][x], x, y);
                return (0);
            }
            if (game->map[y][x] == 'N') (*count_n)++;
            else if (game->map[y][x] == 'S') (*count_s)++;
            else if (game->map[y][x] == 'E') (*count_e)++;
            else if (game->map[y][x] == 'W') (*count_w)++;
            x++;
        }
        y++;
    }
    return (1);
}

int validate_map(t_game *game)
{
    int count_n = 0, count_s = 0, count_e = 0, count_w = 0;

    if (!validate_map_chars(game, &count_n, &count_s, &count_e, &count_w))
        ft_exit_program("Error: Invalid map!\n", NULL, game);

    if ((count_n + count_s + count_e + count_w) != 1)
    {
        printf("Error: Map must have exactly one player! Found: N=%d, S=%d, E=%d, W=%d\n",
               count_n, count_s, count_e, count_w);
        ft_exit_program("Error: Invalid map!\n", NULL, game);
    }

    find_player(game); // O jogador foi localizado

    return (1);
}