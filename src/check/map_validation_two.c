#include "../../includes/cub3D.h"

void get_color (char *ptr, t_game *game, char *key)
{
    char *color;
    int i;
    int j;
    int len;

    i = 0;
    while (ptr[i] == ' ' || ptr[i] == '\t')
        i++;
    len = 0;
    while(ptr[i + len] != '\0' && ptr[i + len] != '\n')
        len++;
    color = malloc(sizeof(char) * (len + 1));
    if (color == NULL)
        ft_exit_error_on_file(EXIT, "", game);
    j = 0;
    while (j < len)
    {
        color[j] = ptr[i + j];
        j++;
    }
    color[j] = '\0';
    assign_color (color, game, key);
    free (color);
}

void view_colors (char *this_line, t_game *game)
{
    int i;
    char *key_colors[] = {"C", "F"};
    int *counters[] = {&game->colors.count_c, &game->colors.count_f};

    i = 0;
    while (i < 2)
    {
        char *ptr = ft_strstr(this_line, key_colors[i]);
        if (ptr && (ptr[1] == ' ' || ptr[1] == '\t'))
        {
            ptr += 1;
            get_color (ptr, game, key_colors[i]);
            (*counters[i])++;
        }
        i++;
    }
}