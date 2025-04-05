#include "../../includes/cub3D.h"


void free_temp_map (char **temp_map)
{
    int i;

    i = 0;
    while (temp_map[i])
    {
        free (temp_map[i]);
        i++;
    }
    free (temp_map);
}

void map_extend (char **temp_map, t_game *game)
{
    int y;

    y = 0;
    if (is_empty_line (&temp_map[0][0]))
    {
        free_temp_map (temp_map);
        ft_putstr_fd (EMPTY_FST_LINE, 1);
        ft_exit_error_on_file (EXIT, game);
    }
    while (temp_map[y] != NULL)
    {
        if (is_char_native_file(temp_map[y])  && is_empty_after_identifier(temp_map[y]))
        {
            free_temp_map (temp_map);
            ft_putstr_fd (MORE_NATIVE_CHAR, 1);
            ft_exit_error_on_file (EXIT, game);
        }
        y++;
    }
}

void fill_map (int count, t_game *game)
{
    char **temp_map;
    char *line;
    int fd;
    int y;

    fd = open (game->file_name, O_RDONLY);
    y = 0;
    temp_map = malloc( sizeof(char *) * (count + 1));
    if (!temp_map)
        return ;
    while (((line = get_next_line (fd)) != NULL))
    {
        temp_map[y++] = line;
    }
    temp_map[y] = NULL;
    close (fd);
    map_extend (temp_map, game);
    free_temp_map (temp_map);
}

int ft_open_file (t_game *game)
{
    int fd;
    char *line;
    int count;

    count = 0;
    fd = open (game->file_name, O_RDONLY);
    if (fd < 0)
        return FALSE;
    while ((line = get_next_line(fd)) != NULL)
    {
        count++;
        if (is_other_char (line, game))
        {
            ft_putendl_fd (IS_OTHER_CHAR, 1);
            ft_exit_error_on_file (EXIT, game);
        }
        free (line);
    }
    fill_map (count, game);
    close (fd);
    return TRUE;
}