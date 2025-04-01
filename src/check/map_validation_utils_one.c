
#include "../../includes/cub3D.h"

void assign_asset_path(char *file, t_game *game, char *key) {
    if (ft_strcmp(key, "NO") == 0) {
        game->assets.asset_no = ft_strdup(file);
    } else if (ft_strcmp(key, "SO") == 0) {
        game->assets.asset_so = ft_strdup(file);
    } else if (ft_strcmp(key, "WE") == 0) {
        game->assets.asset_ea = ft_strdup(file);
    } else if (ft_strcmp(key, "EA") == 0) {
        game->assets.asset_we = ft_strdup(file);
    }
    printf("%s\n", file);
}

int check_cors_count (t_game *game)
{
    game->mark_cors.total_cors += (game->mark_cors.no);
    game->mark_cors.total_cors += (game->mark_cors.so);
    game->mark_cors.total_cors += (game->mark_cors.we);
    game->mark_cors.total_cors += (game->mark_cors.ea); 


    printf ("%d\n", game->mark_cors.total_cors);    

    if (game->mark_cors.total_cors != 4)
        return FALSE;
    return TRUE;
}