/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 19:37:24 by omaimaqaroo       #+#    #+#             */
/*   Updated: 2025/12/10 15:42:49 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_dda_steps(t_game *data)
{
	if (data->ray_dir_x < 0)
	{
		data->step_x = -1;
		data->side_dist_x = (data->pos_x - data->map_x) * data->delta_dist_x;
	}
	else
	{
		data->step_x = 1;
		data->side_dist_x = (data->map_x + 1.0 - data->pos_x)
			* data->delta_dist_x;
	}
	if (data->ray_dir_y < 0)
	{
		data->step_y = -1;
		data->side_dist_y = (data->pos_y - data->map_y) * data->delta_dist_y;
	}
	else
	{
		data->step_y = 1;
		data->side_dist_y = (data->map_y + 1.0 - data->pos_y)
			* data->delta_dist_y;
	}
}

static unsigned char	get_texture_index(t_game *data)
{
	unsigned char	i;

	i = 0;
	if (data->side == 0 && data->pos_x < data->map_x)
		i = 2;
	else if (data->side == 0 && data->pos_x > data->map_x)
		i = 0;
	else if (data->side == 1 && data->pos_y > data->map_y)
		i = 3;
	else if (data->side == 1 && data->pos_y < data->map_y)
		i = 1;
	return (i);
}

void	fill_strip_buffer(t_game *data, int x)
{
	unsigned char	i;
	int				y;
	int				tex_y;
	double			tex_pos;
	int				pix;

	y = data->draw_start - 1;
	data->step = 1.0 * (int)TEX_HEIGHT / data->line_height;
	tex_pos = (data->draw_start - SCREEN_HEIGHT / 2
			+ data->line_height / 2) * data->step;
	i = get_texture_index(data);
	while (++y < data->draw_end)
	{
		tex_y = (int)tex_pos & (TEX_HEIGHT - 1);
		tex_pos += data->step;
		pix = y * data->l_bytes + x * 4;
		data->buf[pix + 0] = data->texture[i]->buf[data->texture[i]->l_bytes
			* tex_y + data->tex_x * 4];
		data->buf[pix + 1] = data->texture[i]->buf[data->texture[i]->l_bytes
			* tex_y + data->tex_x * 4 + 1];
		data->buf[pix + 2] = data->texture[i]->buf[data->texture[i]->l_bytes
			* tex_y + data->tex_x * 4 + 2];
		data->buf[pix + 3] = data->texture[i]->buf[data->texture[i]->l_bytes
			* tex_y + data->tex_x * 4 + 3];
	}
}

void	plot(int x, int y, t_game *data, int color[])
{
	int	pix;

	pix = (y * data->l_bytes) + (x * 4);
	if (x >= 0 && x * 4 < data->l_bytes && y >= 0 && pix < data->buf_size)
	{
		if (data->endi == 1)
		{
			data->buf[pix + 0] = 0;
			data->buf[pix + 1] = color[0];
			data->buf[pix + 2] = color[1];
			data->buf[pix + 3] = color[2];
		}
		else
		{
			data->buf[pix + 0] = color[2];
			data->buf[pix + 1] = color[1];
			data->buf[pix + 2] = color[0];
			data->buf[pix + 3] = 0;
		}
	}
}

void	draw_floor_and_ceiling(t_game *data)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (++x < SCREEN_WIDTH)
	{
		while (++y < SCREEN_HEIGHT / 2)
			plot(x, y, data, data->assets->ceil_rgb);
		y = SCREEN_HEIGHT / 2 - 1;
		while (++y < SCREEN_HEIGHT)
			plot(x, y, data, data->assets->floor_rgb);
		y = -1;
	}
}
