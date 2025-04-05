#include "../../includes/cub3D.h"

void get_path_file(char *this_line, char *ptr, t_game *game, char *key)
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
        return ;
    j = 0;
    while (j < len)
    {
        file[j] = ptr[i + j];
        j++;
    }
    file[j] = '\0';
    assign_asset_path(this_line, file, game, key);
    free (file);
}

void view_cors (char *this_line, t_game *game)
{
    int i;
    char *keys_cors[] = {"NO", "SO", "WE", "EA"};


    i = 0;
    while (i < 4)
    {
        char *ptr = ft_strstr(this_line, keys_cors[i]);
        if (ptr && (ptr[2] == ' ' || ptr[2] == '\t'))
        {
            ptr += 2;
            get_path_file(this_line ,ptr, game, keys_cors[i]);
            game->mark_cors.total_cors++;
        }
        i++;
    }
}

