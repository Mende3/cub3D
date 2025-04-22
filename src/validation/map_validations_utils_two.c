#include "../../includes/cub3D.h"

#include "../../includes/cub3D.h"

int check_internal_lines (t_game *game)
{
	int y;
	int x;
	int last_index;

	y = 1;
	while (game->map[y])
	{
		if (y >= game->map_heigth -1)
			break ;
		x = 0;
		while (game->map[y][x] && ft_isspace(game->map[y][x]))
			x++;
		if (game->map[y][x] && game->map[y][x] != '1')
			return FALSE;
		
		last_index = ft_strlen(game->map[y]) - 1;
		while (last_index >= 0 && ft_isspace(game->map[y][last_index]))
			last_index--;
		
		if (last_index >= 0 && game->map[y][last_index] != '1')
			return FALSE;	
		y++;
	}
	return TRUE;
} 

int check_external_line (t_game *game)
{
	int xf;
	int xl;
	int y;

	xf = 0;
	xl = 0;
	while (game->map[0][xf])
	{
		if (!ft_isspace(game->map[0][xf]) && game->map[0][xf] != 49)
			return FALSE;
		xf++;
	}
	printf ("\n");
	y = game->map_heigth - 1;
	while (game->map[y][xl])
	{
		if (!ft_isspace(game->map[y][xl]) && game->map[y][xl] != 49)
			return FALSE;
		xl++;
	}
	return TRUE;
}

void	is_map_surrounded_by_walls(t_game *game)
{
	if (!check_external_line(game) || !check_internal_lines(game))
	{
		ft_putstr_fd (NO_ARROUND_WALLS, 2);
		ft_exit_program (EXIT, INVALID_MAP, game);
	}
}
