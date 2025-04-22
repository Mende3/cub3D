/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiala <gkiala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:42:25 by gkiala            #+#    #+#             */
/*   Updated: 2025/04/19 12:29:42 by gkiala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void init_player_dir_and_plane(t_game *game, char orientation)
{
    if (orientation == 'N')
    {
        game->dir_x = 0;
        game->dir_y = -1;
        game->plane_x = 0.66;
        game->plane_y = 0;
        game->move_speed = 0.06;

    }
    else if (orientation == 'S')
    {
        game->dir_x = 0;
        game->dir_y = 1;
        game->plane_x = -0.66;
        game->plane_y = 0;
        game->move_speed = 0.04;

    }
    else if (orientation == 'E')
    {
        game->dir_x = 1;
        game->dir_y = 0;
        game->plane_x = 0;
        game->plane_y = 0.66;
        game->move_speed = 0.04;

    }
    else if (orientation == 'W')
    {
        game->dir_x = -1;
        game->dir_y = 0;
        game->plane_x = 0;
        game->plane_y = -0.66;
        game->move_speed = 0.04;

    }
}

void my_mlx_pixel_put(t_game *game, int x, int y, int color)
{
    char *dst;

    if (x < 0 || x >= WIDTH_WIN || y < 0 || y >= HIGHT_WIN)
        return;
    dst = game->img.addr + (y * game->img.line_length + x * (game->img.bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

void	draw_ceiling_and_floor(t_game *game)
{
	int y = 0;
	while (y < HIGHT_WIN)
	{
		unsigned int color;
		if (y < HIGHT_WIN / 2)
			color = strtol(game->colors.color_c, NULL, 16);
		else
			color = strtol(game->colors.color_f, NULL, 16);

		int x = 0;
		while (x < WIDTH_WIN)
		{
			my_mlx_pixel_put(game, x, y, color);
			x++;
		}
		y++;
	}
}

void    init_ray(t_game *game, int x, t_ray *ray)
{
    ray->camera_x = 2 * x / (double)WIDTH_WIN - 1;
    ray->ray_dir_x = game->dir_x + game->plane_x * ray->camera_x;
    ray->ray_dir_y = game->dir_y + game->plane_y * ray->camera_x;

    ray->map_x = (int)game->pos_x;
    ray->map_y = (int)game->pos_y;

    if (ray->ray_dir_x == 0)
        ray->delta_dist_x = 1e30;
    else
        ray->delta_dist_x = fabs(1 / ray->ray_dir_x);

    if (ray->ray_dir_y == 0)
        ray->delta_dist_y = 1e30;
    else
        ray->delta_dist_y = fabs(1 / ray->ray_dir_y);

    if (ray->ray_dir_x < 0)
    {
        ray->step_x = -1;
        ray->side_dist_x = (game->pos_x - ray->map_x) * ray->delta_dist_x;
    }
    else
    {
        ray->step_x = 1;
        ray->side_dist_x = (ray->map_x + 1.0 - game->pos_x) * ray->delta_dist_x;
    }

    if (ray->ray_dir_y < 0)
    {
        ray->step_y = -1;
        ray->side_dist_y = (game->pos_y - ray->map_y) * ray->delta_dist_y;
    }
    else
    {
        ray->step_y = 1;
        ray->side_dist_y = (ray->map_y + 1.0 - game->pos_y) * ray->delta_dist_y;
    }
}


void perform_dda(t_game *game, t_ray *ray)
{
    int hit = 0;

    while (!hit)
    {
        if (ray->side_dist_x < ray->side_dist_y)
        {
            ray->side_dist_x += ray->delta_dist_x;
            ray->map_x += ray->step_x;
            ray->side = 0;
        }
        else
        {
            ray->side_dist_y += ray->delta_dist_y;
            ray->map_y += ray->step_y;
            ray->side = 1;
        }

        //  Verifica antes de acessar o mapa
        if (ray->map_x < 0 || ray->map_x >= game->map_width ||
            ray->map_y < 0 || ray->map_y >= game->map_heigth)
        {
            break;
        }

        if (game->map[ray->map_y][ray->map_x] == '1')
            hit = 1;
    }
}


void draw_wall_column(t_game *game, int x, t_ray *ray)
{
	double perp_wall_dist;
	if (ray->side == 0)
		perp_wall_dist = ray->side_dist_x - ray->delta_dist_x;
	else
		perp_wall_dist = ray->side_dist_y - ray->delta_dist_y;

	int line_height = (int)(HIGHT_WIN / perp_wall_dist);
	int draw_start = CLAMP(-line_height / 2 + HIGHT_WIN / 2, 0, HIGHT_WIN);
	int draw_end = CLAMP(line_height / 2 + HIGHT_WIN / 2, 0, HIGHT_WIN);

	// --- Escolher textura e calcular wall_x ---
	char *texture = get_texture_addr(game, ray);
	double wall_x;

	if (ray->side == 0)
		wall_x = game->pos_y + perp_wall_dist * ray->ray_dir_y;
	else
		wall_x = game->pos_x + perp_wall_dist * ray->ray_dir_x;
	wall_x -= floor(wall_x); // Só a parte decimal

	// --- Coordenada X da textura ---
	int tex_x = (int)(wall_x * (double)game->assets.asset_width);
	if ((ray->side == 0 && ray->ray_dir_x > 0) || (ray->side == 1 && ray->ray_dir_y < 0))
		tex_x = game->assets.asset_width - tex_x - 1;

	// --- Desenho da coluna com textura ---
	for (int y = draw_start; y < draw_end; y++)
	{
		int d = y * 256 - HIGHT_WIN * 128 + line_height * 128;
		int tex_y = ((d * game->assets.asset_height) / line_height) / 256;

		unsigned int color = get_texture_pixel(
			texture, tex_x, tex_y,
			game->assets.asset_line_len,
			game->assets.asset_bpp);

		my_mlx_pixel_put(game, x, y, color);
	}
}

void	render_frame(t_game *game)
{
	int x = 0;
	t_ray ray;

	draw_ceiling_and_floor(game);
	while (x < WIDTH_WIN)
	{
		init_ray(game, x, &ray);
		perform_dda(game, &ray);
		draw_wall_column(game, x, &ray);
		x++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
}
