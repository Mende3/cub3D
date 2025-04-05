#include "../../includes/cub3D.h"

void print_map(t_game *game)
{
    int i;
    int j;
    
    if (!game || !game->map)
        return;
    
    i = 0;
    while (i < game->map_heigth)
    {
        j = 0;
        while (game->map[i][j] != '\0')
        {
            printf("%c", game->map[i][j]);
            j++;
        }
        i++;
    }
}


int read_file (char *line, t_game *game)
{
    int i;
    char **temp;

	game->map_heigth= 0;
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
    temp[i] = line; 
    if (game->map)
        free (game->map);
    game->map = temp;
    print_map (game);
    return (TRUE);
}