/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaimaqaroot <omaimaqaroot@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 19:37:24 by omaimaqaroo       #+#    #+#             */
/*   Updated: 2025/10/17 19:37:29 by omaimaqaroo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	update_vars_(t_game *d)
{
	if (d->ray_dir_x < 0)
	{
		d->step_x = -1;
		d->side_dist_x = (d->pos_x - d->map_x) * d->delta_dist_x;
	}
	else
	{
		d->step_x = 1;
		d->side_dist_x = (d->map_x + 1.0 - d->pos_x) * d->delta_dist_x;
	}
	if (d->ray_dir_y < 0)
	{
		d->step_y = -1;
		d->side_dist_y = (d->pos_y - d->map_y) * d->delta_dist_y;
	}
	else
	{
		d->step_y = 1;
		d->side_dist_y = (d->map_y + 1.0 - d->pos_y) * d->delta_dist_y;
	}
}

void	update_vars(int x, t_game *d)
{
	d->camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
	d->ray_dir_x = d->dir_x + d->plane_x * d->camera_x;
	d->ray_dir_y = d->dir_y + d->plane_y * d->camera_x;
	d->map_x = (int)d->pos_x;
	d->map_y = (int)d->pos_y;
	if (d->ray_dir_x == 0)
		d->delta_dist_x = 1e30;
	else
		d->delta_dist_x = fabs(1 / d->ray_dir_x);
	if (d->ray_dir_y == 0)
		d->delta_dist_y = 1e30;
	else
		d->delta_dist_y = fabs(1 / d->ray_dir_y);
	update_vars_(d);
}

static unsigned char	get_texture_index(t_game *d)
{
	unsigned char	i;

	i = 0;
	if (d->side == 0 && d->pos_x < d->map_x)
		i = 2;
	else if (d->side == 0 && d->pos_x > d->map_x)
		i = 0;
	else if (d->side == 1 && d->pos_y > d->map_y)
		i = 3;
	else if (d->side == 1 && d->pos_y < d->map_y)
		i = 1;
	return (i);
}

static void	fill_strip_buffer(t_game *d, int x)
{
	unsigned char	i;
	int				y;
	int				tex_y;
	double			tex_pos;
	int				pix;

	y = d->draw_start - 1;
	d->step = 1.0 * (int)TEX_HEIGHT / d->line_height;
	tex_pos = (d->draw_start - d->view_shift - d->screen_height / 2
			+ d->line_height / 2) * d->step;
	i = get_texture_index(d);
	while (++y < d->draw_end)
	{
		tex_y = (int)tex_pos & (TEX_HEIGHT - 1);
		tex_pos += d->step;
		pix = y * d->l_bytes + x * 4;
		d->buf[pix + 0] = d->texture[i]->buf[d->texture[i]->l_bytes * tex_y
			+ d->tex_x * 4];
		d->buf[pix + 1] = d->texture[i]->buf[d->texture[i]->l_bytes * tex_y
			+ d->tex_x * 4 + 1];
		d->buf[pix + 2] = d->texture[i]->buf[d->texture[i]->l_bytes * tex_y
			+ d->tex_x * 4 + 2];
		d->buf[pix + 3] = d->texture[i]->buf[d->texture[i]->l_bytes * tex_y
			+ d->tex_x * 4 + 3];
	}
}

void	draw_strip(t_game *d, int x)
{
	d->tex_num = d->world_map[d->map_x][d->map_y] - 1;
	if (d->side == 0)
		d->wall_x = d->pos_y + d->perp_wall_dist * d->ray_dir_y;
	else
		d->wall_x = d->pos_x + d->perp_wall_dist * d->ray_dir_x;
	d->wall_x -= floor(d->wall_x);
	d->tex_x = (int)(d->wall_x * (double)TEX_WIDTH);
	if (d->side == 0 && d->ray_dir_x > 0)
		d->tex_x = (int)TEX_WIDTH - d->tex_x - 1;
	if (d->side == 1 && d->ray_dir_y < 0)
		d->tex_x = (int)TEX_WIDTH - d->tex_x - 1;
	fill_strip_buffer(d, x);
}
