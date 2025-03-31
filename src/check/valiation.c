#include "../../includes/cub3D.h"

int validation_true (t_game *game)
{
    if (get_a_line (game))
        return TRUE;
    return FALSE;
}