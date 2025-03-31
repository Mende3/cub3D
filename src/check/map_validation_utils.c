
#include "../../includes/cub3D.h"

void assign_asset_path(char *file, t_game *game, char *key) {
    if (ft_strcmp(key, "NO") == 0) {
        game->assets.asset_no = file;
    } else if (ft_strcmp(key, "SO") == 0) {
        game->assets.asset_so = file;
    } else if (ft_strcmp(key, "WE") == 0) {
        game->assets.asset_we = file;
    } else if (ft_strcmp(key, "EA") == 0) {
        game->assets.asset_ea = file;
    }
    printf("%s\n", file);
}


char *ft_strstr(const char *haystack, const char *needle)
{
    if (haystack[0] == '\t' || haystack[0] == 32)
        return NULL;
    while (*haystack)
    {
        const char *h = haystack;
        const char *n = needle;
        while (*h && *n && (*h == *n))
        {
            h++;
            n++;
        }
        if (*n == '\0')
            return (char *)haystack;  // Encontrou a string
        haystack++;
    }
    return NULL;
}

int check_cors_count (t_game *game)
{
    game->mark_cors.total_cors += (game->mark_cors.no);
    game->mark_cors.total_cors += (game->mark_cors.so);
    game->mark_cors.total_cors += (game->mark_cors.we);
    game->mark_cors.total_cors += (game->mark_cors.ea); 


    printf ("%d\n", game->mark_cors.total_cors);    

    if (game->mark_cors.total_cors != 4)
        return TRUE;
    return FALSE;
}

int find_file(char *asset_path)
{
    int fd;

    fd = open(asset_path, O_RDONLY);
    if (fd < 0)
        return FALSE;
    close(fd);    
    return TRUE;
}