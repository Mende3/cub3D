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

int get_a_line(t_game *game)
{
    int fd;
    char *line;
    int start_read;
    int result;

    start_read = FALSE;        
    fd = open(game->file_name, O_RDONLY);
    if (fd < 0)
        return FALSE;
    while ((line = get_next_line(fd)) != NULL)
    {
        view_cors(line, game);
        view_colors(line, game);
        result = view_map(line, game, &start_read);
        if (result == FALSE && start_read == TRUE)
        {
            free (line);
            ft_exit_error_on_file(EXIT, game);
        }
        free (line);
    }
    if (!check_count(game))
        return FALSE;    
    view_player_on_map (game);
    close(fd);
    return TRUE;
}

int validation (t_game *game)
{
    if (get_a_line (game))
    {
        return TRUE;
    }
    return FALSE;
}