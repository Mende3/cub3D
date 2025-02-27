#include "../../includes/cub3D.h"

void render_assets (t_game *game)
{
    int i = 0;
    printf("Conteúdo do mapa:\n");
    while (i < game->map_heigth) {
        printf("%s", game->map[i]); // Não precisa de \n, pois já está na linha lida
        i++;
    }
    printf("\n");
}