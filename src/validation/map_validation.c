#include "../../includes/cub3D.h"

int is_map_line(char *line)
{
    int i;
    int has_valid_char;
    int only_spaces;

    if (!line || *line == '\0')
        return (FALSE);
    if (is_char_native_file (line))
        return (FALSE);    
    has_valid_char = 0;
    only_spaces = 1;    
    i = 0;
    while (line[i] != '\0')
    {
        if (!ft_isspace(line[i]))
            only_spaces = 0;            
        if (is_char_valid(line, i))
        {
            if (line[i] != ' ')
                has_valid_char = 1;
        }
        else
            return (FALSE);
        i++;
    }    
    int result = (only_spaces == 0 && has_valid_char == 1);
    return result;
}

int view_map(char *this_line, t_game *game, int *start_read)
{
    if (game->mark_cors.total_cors == 4 && 
        game->colors.total_colors == 2 && 
        is_map_line(this_line))
    {
        *start_read = TRUE;
        ft_read_file (this_line, game);
        return TRUE;
    }
    else if (*start_read)
    {
        ft_putstr_fd(NO_CHAR_MAP, 1);
        return FALSE;
    }
    return TRUE;
}
