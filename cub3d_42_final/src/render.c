/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 19:39:50 by omaimaqaroo       #+#    #+#             */
/*   Updated: 2025/12/11 14:16:17 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_ray(int x, t_game *data)
{
	data->camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
	data->ray_dir_x = data->dir_x + data->plane_x * data->camera_x;
	data->ray_dir_y = data->dir_y + data->plane_y * data->camera_x;
	data->map_x = (int)data->pos_x;
	data->map_y = (int)data->pos_y;
	if (data->ray_dir_x == 0)
		data->delta_dist_x = 1e30;
	else
		data->delta_dist_x = fabs(1 / data->ray_dir_x);
	if (data->ray_dir_y == 0)
		data->delta_dist_y = 1e30;
	else
		data->delta_dist_y = fabs(1 / data->ray_dir_y);
	init_dda_steps(data);
}

static void	run_dda(t_game *data)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (data->side_dist_x < data->side_dist_y)
		{
			data->side_dist_x += data->delta_dist_x;
			data->map_x += data->step_x;
			data->side = 0;
		}
		else
		{
			data->side_dist_y += data->delta_dist_y;
			data->map_y += data->step_y;
			data->side = 1;
		}
		if (data->assets->map[data->map_x][data->map_y] == 49)
			hit = 1;
	}
}

static void	calc_start_end(t_game *data)
{
	if (data->side == 0)
		data->perp_wall_dist = data->side_dist_x - data->delta_dist_x;
	else
		data->perp_wall_dist = data->side_dist_y - data->delta_dist_y;
	data->line_height = (int)(SCREEN_HEIGHT / data->perp_wall_dist);
	data->draw_start = -data->line_height / 2 + SCREEN_HEIGHT / 2;
	if (data->draw_start < 0)
		data->draw_start = 0;
	data->draw_end = data->line_height / 2 + SCREEN_HEIGHT / 2;
	if (data->draw_end >= SCREEN_HEIGHT)
		data->draw_end = SCREEN_HEIGHT - 1;
}

static void	draw_strip(t_game *data, int x)
{
	if (data->side == 0)
		data->wall_x = data->pos_y + data->perp_wall_dist * data->ray_dir_y;
	else
		data->wall_x = data->pos_x + data->perp_wall_dist * data->ray_dir_x;
	data->wall_x -= floor(data->wall_x);
	data->tex_x = (int)(data->wall_x * (double)TEX_WIDTH);
	if (data->side == 0 && data->ray_dir_x > 0)
		data->tex_x = (int)TEX_WIDTH - data->tex_x - 1;
	if (data->side == 1 && data->ray_dir_y < 0)
		data->tex_x = (int)TEX_WIDTH - data->tex_x - 1;
	fill_strip_buffer(data, x);
}

void	render(t_game *data)
{
	int	x;

	if (!data->img)
	{
		data->img = mlx_new_image(data->mlx, SCREEN_WIDTH,
				SCREEN_HEIGHT);
		data->buf = mlx_get_game_addr(data->img, &data->pix_bits,
				&data->l_bytes, &data->endi);
		data->buf_size = SCREEN_HEIGHT * data->l_bytes;
	}
	draw_floor_and_ceiling(data);
	x = -1;
	data->time = get_time(data);
	while (++x < SCREEN_WIDTH)
	{
		init_ray(x, data);
		run_dda(data);
		calc_start_end(data);
		draw_strip(data, x);
	}
	get_move_rot_speeds(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
