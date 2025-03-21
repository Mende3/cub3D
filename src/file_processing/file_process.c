#include "../../includes/cub3D.h"

int ft_open_file (char *path, t_game *game)
{
    int fd;
    char *line;

    fd = open (path, O_RDONLY);
    if (fd < 0)
        return FALSE;
    game->map_heigth = 0;
    while (1)
    {
        line = get_next_line (fd);
        if (!line)
            break ;
        if (!read_file(line, game))
            break;
    }
    close (fd);
    return TRUE;
}

int read_file (char *line, t_game *game)
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
    temp[i] = line; 
    if (game->map)
        free (game->map);
    game->map = temp;
    return (TRUE);
}
