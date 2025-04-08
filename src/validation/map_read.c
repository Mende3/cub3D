#include "../../includes/cub3D.h"

int ft_read_file (char *line, t_game *game)
{
    int i;
    char **temp;

    if (!line)
        return (FALSE);
    game->map_heigth++;
    temp = (char **) malloc(sizeof (char *) * (game->map_heigth + 1));
    if (!temp)
        return (FALSE);
    temp[game->map_heigth] = NULL;
    i = -1;
    while (++i < game->map_heigth - 1)
        temp[i] = game->map[i];
    temp[i] = ft_strdup(line);
    if (game->map)
        free (game->map);
    game->map = temp;
    return (TRUE);
}