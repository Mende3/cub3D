#include "../../includes/cub3D.h"


int is_other_char (char *this_line, t_game *game)
{
    int i;

    i = 0;
    (void)game;
    while (this_line[i])
    {
        if (!is_char_valid(this_line, i) &&
            !is_char_native_file(this_line))
        {
            return TRUE;
        }
        i++;
    }
    return FALSE;
}

int is_empty_line(char *this_line)
{
    int i = 0;
    
    while (this_line[i])
    {
        if (this_line[i] != ' ' && this_line[i] != '\t' && this_line[i] != '\n')
            return FALSE;
        i++;
    }
    return TRUE;
}

int is_char_native_file (char *this_line)
{
    return (((this_line[0] == 'N' && this_line[1] == 'O' && ft_isspace(this_line[2])) ||
        (this_line[0] == 'S' && this_line[1] == 'O' && ft_isspace(this_line[2])) ||
        (this_line[0] == 'E' && this_line[1] == 'A' && ft_isspace(this_line[2])) ||
        (this_line[0] == 'W' && this_line[1] == 'E' && ft_isspace(this_line[2])) ||
        (this_line[0] == 'F' && ft_isspace(this_line[1])) ||
        (this_line[0] == 'C' && ft_isspace(this_line[1]))));
}

int is_empty_after_identifier(char *line)
{
    int i = 0;
    
    if (line[0] == 'N' && line[1] == 'O' && ft_isspace(line[2]))
        i = 3;
    else if (line[0] == 'S' && line[1] == 'O' && ft_isspace(line[2]))
        i = 3;
    else if (line[0] == 'E' && line[1] == 'A' && ft_isspace(line[2]))
        i = 3;
    else if (line[0] == 'W' && line[1] == 'E' && ft_isspace(line[2]))
        i = 3;
    else if (line[0] == 'F' && ft_isspace(line[1]))
        i = 2;
    else if (line[0] == 'C' && ft_isspace(line[1]))
        i = 2;
    else
        return 0;
    while (line[i] && ft_isspace(line[i]))
        i++;
    return (line[i] == '\0');
}