#include "../../includes/cub3D.h"

char	**ft_dup_map(char **map)
{
	int		len;
	char	**new_map;
	int		i;

	len = 0;
	while (map[len])
		len++;
	new_map = (char **)malloc(sizeof(char *) * (len + 1));
	if (!new_map)
		return (NULL);
	new_map[len] = NULL;
	i = 0;
	while (map[i] != NULL)
	{
		new_map[i] = ft_strdup(map[i]);
		if (!new_map[i])
		{
			free_matrix(new_map);
			return (NULL);
		}
		i++;
	}
	return (new_map);
}

void	fill_map(char **map, int y, int x, t_game *game)
{
	if (y < 0 || x < 0 || y >= game->map_heigth || map[y] == NULL || map[y][x] == '\0')
		return ;

	if (map[y][x] == 32)
	{
		game->check_spaces++;
		map[y][x] = 'F';
	}
        
    if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	map[y][x] = 'F';
	fill_map(map, y, x - 1, game);
	fill_map(map, y, x + 1, game);
	fill_map(map, y - 1, x, game);
	fill_map(map, y + 1, x, game);
}

void can_play (t_game *game)
{
	int y;
    int x;
    char **temp;

    y = 0;
    while (y < game->map_heigth)
    {
        x = 0;
        while (game->map[y][x])
        {
            if (game->map[y][x] == 'N' || game->map[y][x] == 'S' ||
                game->map[y][x] == 'E' || game->map[y][x] == 'W')
            {
                temp = ft_dup_map (game->map);
                fill_map (temp, y, x, game);
                if (game->check_spaces != 0)
				{
					ft_exit_error_on_file (SPACE_INTERNAL, game);
				}
            }
            x++;
        }
        y++;        
    }
}