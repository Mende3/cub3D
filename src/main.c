#include "../includes/cub3D.h"

// Exemplo no código de leitura do mapa
void init_struct_vars(char *arg, t_game *game)
{
    ft_bzero(game, sizeof(t_game));
    game->file_name = arg;
    game->assets.asset_width = 64;
    game->assets.asset_height = 64;
    game->map_heigth = HIGHT_WIN;
    game->map_width = WIDTH_WIN;
    game->map_heigth = 0;
    game->map_width = 0;
    game->map = NULL;

    // Adicionando inicialização da direção do jogador
    char player_orientation = 'N'; // Exemplo, o valor pode vir do mapa
    init_player_dir_and_plane(game, player_orientation);
}


int main(int ac, char **av)
{
    t_game *game;
    const char *extension;

    if (ac == 2)
    {
        game = malloc(sizeof(t_game));
        if (!game)
            return (1);
        
        extension = "cub";
        if (extension_checker(av[1], extension))
        {
            init_struct_vars (av[1], game);
            if (ft_open_file(game))
            {
                if (validation(game))
                    init_win (game);
                else
                    ft_exit_error_on_file (EXIT, game);
            }
            else
                ft_exit_program(EXIT, NO_FILE, game);
        }
        else
            ft_exit_program(EXIT, NO_EXT, game);
    }
    else
        ft_putstr_fd(NO_ARG, 2);
    return (0);
}
