/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiala <gkiala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 20:42:24 by gkiala            #+#    #+#             */
/*   Updated: 2025/04/14 20:42:34 by gkiala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int ft_close_esc (int keycode)
{
    if (keycode == ESC_KEY)
        return 1;
    return 0;
}

int ft_close_x (t_game *game)
{
    ft_exit_program (EXIT, "other", game);
    return 0;
}