#include "../../includes/cub3D.h"

int  is_char_valid (char *this_line, int i)
{
    return (this_line[i] == '0' || this_line[i] == '1' ||
            this_line[i] == 'N' || this_line[i] == 'S' ||
            this_line[i] == 'E'|| this_line[i] == 'W'||
            ft_isspace(this_line[i]));
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
                init_player_dir_and_plane(game, game->map[y][x]);
                game->pos_x = x + 0.5;
                game->pos_y = y + 0.5;
                return;
            }
            x++;
        }
        y++;
    }
    ft_putstr_fd(PLAYER_NOT_FOUND, 2);
    ft_exit_error_on_file(EXIT, game);
}

void count_identifier_player (t_game *game)
{
    int y = 0;
    int x;

    while (game->map[y])
    {
        x = 0;
        while (game->map[y][x])
        {
            if (game->map[y][x] == 'N')
                game->player.count_n++;
            if (game->map[y][x] == 'S')
                game->player.count_s++;
            if (game->map[y][x] == 'E')
                game->player.count_e++;
            if (game->map[y][x] == 'W')
                game->player.count_w++;
            x++;
        }
        y++;
    }
}

void view_player_on_map (t_game *game)
{
    count_identifier_player (game);
    if ((game->player.count_n +  game->player.count_s +  game->player.count_e +  game->player.count_w) != 1)
    {
        printf("%s N=%d, S=%d, E=%d, W=%d\n", NOT_FOUND,  game->player.count_n,  game->player.count_s,  game->player.count_e,  game->player.count_w);
        ft_exit_program(EXIT, INVALID_MAP, game);
    }
    find_player(game);
}