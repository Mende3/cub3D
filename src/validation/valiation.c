#include "../../includes/cub3D.h"

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
        free(line);
    }
    printf("\n"); //depois tirar
    close(fd);
    if (!check_count(game))
        return FALSE;
    return TRUE;
}

int validation_true (t_game *game)
{
    if (get_a_line (game))
        return TRUE;
    return FALSE;
}