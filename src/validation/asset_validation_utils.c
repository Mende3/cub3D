#include "../../includes/cub3D.h"

int extension_checker_assets(const char *arg, const char *ext)
{
    const char *dot;
    const char *last_dot = NULL;
    
    dot = arg;
    while ((dot = ft_strchr(dot, '.')) != NULL)
    {
        last_dot = dot;
        dot++;
    }
    
    if (!last_dot || *(last_dot + 1) == '\0')
        return (FALSE);
    return (ft_strcmp((char *)(last_dot + 1), (char *)ext) == 0);
}

void extension_checker_adapter (char *this_line, char *file, t_game *game)
{
    if (!extension_checker_assets (file, "xpm"))
    {        
        free (file);
        free (this_line),
        ft_putstr_fd (ERROR_EXT_ASSET, 1);
        ft_exit_error_on_file (EXIT, game);
    }
}

void assign_asset_path(char *this_line, char *file, t_game *game, char *key)
{
    extension_checker_adapter (this_line, file, game);   
    if (ft_strcmp(key, "NO") == 0)
    {
        free_subject (game->assets.asset_no);
        game->assets.asset_no = ft_strdup(file);
    }
    else if (ft_strcmp(key, "SO") == 0)
    {
        free_subject (game->assets.asset_so);
        game->assets.asset_so = ft_strdup(file);
    }
    else if (ft_strcmp(key, "WE") == 0)
    {
        free_subject (game->assets.asset_we);
        game->assets.asset_we = ft_strdup(file);
    }
    else if (ft_strcmp(key, "EA") == 0)
    {
        free_subject (game->assets.asset_ea);
        game->assets.asset_ea = ft_strdup(file);
    }
}