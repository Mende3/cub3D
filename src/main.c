#include "../includes/cub3D.h"


void ini_struct_vars (t_game *game)
{
    ft_bzero (game, sizeof(t_game));
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
            ini_struct_vars (game);
            if (ft_open_file(av[1], game))
            {
                if (validate_map(game))
                    init_win(av[1], game);
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
