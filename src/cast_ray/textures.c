/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:31:31 by gkiala            #+#    #+#             */
/*   Updated: 2025/04/14 15:31:32 by gkiala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

unsigned int get_texture_pixel(char *addr, int x, int y, int line_length, int bpp)
{
    return *(unsigned int *)(addr + y * line_length + x * (bpp / 8));
}

char *get_texture_addr(t_game *game, t_ray *ray)
{
	if (ray->side == 0 && ray->ray_dir_x > 0)
		return game->assets.asset_we_addr;
	if (ray->side == 0 && ray->ray_dir_x < 0)
		return game->assets.asset_ea_addr;
	if (ray->side == 1 && ray->ray_dir_y > 0)
		return game->assets.asset_no_addr;
	return game->assets.asset_so_addr;
}
