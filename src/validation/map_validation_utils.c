#include "../../includes/cub3D.h"

int  is_char_valid (char *this_line, int i)
{
    return (this_line[i] == '0' || this_line[i] == '1' ||
            this_line[i] == 'N' || this_line[i] == 'S' ||
            this_line[i] == 'E'|| this_line[i] == 'W'||
            ft_isspace(this_line[i]));
}