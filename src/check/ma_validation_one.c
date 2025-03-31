#include "../../includes/cub3D.h"

void get_path_file(char *ptr, t_game *game, char *key)
{
    char *file;
    int i;
    int j;
    int len;
    
    i = 0;
    while (ptr[i] == ' ' || ptr[i] == '\t')
        i++;
    len = 0;
    while(ptr[i + len] != '\0' && ptr[i + len] != '\n')
        len++;
    file = malloc(sizeof(char) * (len + 1));
    if (file == NULL)
        ft_exit_error_on_file(EXIT, "", game);
    j = 0;
    ft_strlcpy (file, ptr, j < len);
    while (j < len)
    {
        file[j] = ptr[i + j];
        j++;
    }
    file[j] = '\0';
    assign_asset_path(file, game, key);
    free(file);
}

void line_view(char *this_line, t_game *game)
{
    int i;
    char *keys_cors[] = {"NO", "SO", "WE", "EA"};
    int *counters[] = {&game->mark_cors.no, &game->mark_cors.so, &game->mark_cors.we, &game->mark_cors.ea};

    i = 0;
    while (i < 4)
    {
        char *ptr = ft_strstr(this_line, keys_cors[i]);
        if (ptr && (ptr[2] == ' ' || ptr[2] == '\t'))
        {
            ptr += 2;
            get_path_file(ptr, game, keys_cors[i]);
            (*counters[i])++;
        }
        i++;
    }
}


int get_a_line(t_game *game)
{
    int fd;
    char *line;

    fd = open(game->file_name, O_RDONLY);
    if (fd < 0)
        ft_exit_program(EXIT, NO_FILE, game);

    while ((line = get_next_line(fd)) != NULL)
    {
        line_view(line, game);
        free(line);
    }
    close(fd);
    if (check_cors_count (game))
        return FALSE;
    return TRUE;
}
