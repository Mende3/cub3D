#include "../../includes/cub3D.h"

void check_around_sbj (t_game *game, int y, int x)
{
	char c;

	c = game->map[y][x];

	if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		if (y > 0 && game->map[y - 1][x] == 32)
			game->check_spaces++;
		if (game->map[y + 1] && game->map[y + 1][x] == 32)
			game->check_spaces++;
		if (x > 0 && game->map[y][x - 1] == 32)
			game->check_spaces++;
		if (game->map[y][x + 1] && game->map[y][x + 1] == 32)
			game->check_spaces++;
	}
}

void can_play (t_game *game)
{
	int y;
    int x;

    y = 0;
    while (y < game->map_heigth)
    {
        x = 0;
        while (game->map[y][x])
        {
			check_around_sbj (game, y, x);
            x++;
        }
        y++;        
    }
	if (game->check_spaces > 0)
	{
		printf (SPACE_INTERNAL);
		ft_exit_error_on_file (EXIT, game);
	}
}
