#include "../../includes/cub3D.h"

int	is_map_surrounded_by_walls(t_game *game)
{
	int	x;
	int	y;

	x = -1;
	while (++x < game->map_width)
	{
		if (game->map[0][x] != '1')
			return (FALSE);
	}
	x = -1;
	while (++x < game->map_width)
	{
		if (game->map[game->map_heigth - 1][x] != '1')
			return (FALSE);
	}
	y = -1;
	while (++y < game->map_heigth)
	{
		if (game->map[y][0] != '1')
			return (FALSE);
		if (game->map[y][game->map_width - 1] != '1')
			return (FALSE);
	}
	return (TRUE);
}