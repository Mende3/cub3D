#include "../../includes/cub3D.h"

int get_a_line(t_game *game)
{
    int fd;
    char *line;

    fd = open(game->file_name, O_RDONLY);
    if (fd < 0)
        ft_exit_program(EXIT, NO_FILE, game);

    while ((line = get_next_line(fd)) != NULL)
    {
        view_cors (line, game);
        view_colors (line, game);
        free(line);
    }
    close(fd);
    if (!check_cors_count (game) || !check_colors_count(game))
        return FALSE;
    return TRUE;
}

int validation_true (t_game *game)
{
    if (get_a_line (game))
        return TRUE;
    return FALSE;
}