#include "../../includes/cub3D.h"

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

int is_char_valid (char *this_line, int i)
{
    return (this_line[i] == '0' || this_line[i] == '1' ||
            this_line[i] == 'N' || this_line[i] == 'S' ||
            this_line[i] == 'E'|| this_line[i] == 'W'||
            ft_isspace(this_line[i]));
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
