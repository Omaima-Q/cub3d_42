/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaimaqaroot <omaimaqaroot@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 19:39:50 by omaimaqaroo       #+#    #+#             */
/*   Updated: 2025/10/17 19:39:53 by omaimaqaroo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_move_rot_speeds(t_game *d)
{
	d->old_time = d->time;
	d->time = get_time(d);
	d->frame_time = (d->time - d->old_time) / 1000.0;
	d->move_speed = d->frame_time * 50.0;
	d->rot_speed = d->frame_time * 12.0;
}

void	plot(int x, int y, t_game *d, int color)
{
	int	pix;

	pix = (y * d->l_bytes) + (x * 4);
	if (x >= 0 && x * 4 < d->l_bytes && y >= 0 && pix < d->buf_size)
	{
		if (d->endi == 1)
		{
			d->buf[pix + 0] = (color >> 24);
			d->buf[pix + 1] = (color >> 16) & 0xFF;
			d->buf[pix + 2] = (color >> 8) & 0xFF;
			d->buf[pix + 3] = (color)&0xFF;
		}
		else
		{
			d->buf[pix + 0] = (color)&0xFF;
			d->buf[pix + 1] = (color >> 8) & 0xFF;
			d->buf[pix + 2] = (color >> 16) & 0xFF;
			d->buf[pix + 3] = (color >> 24);
		}
	}
}

void	draw_floor_and_ceiling(t_game *d)
{
	int	x;
	int	y;
	int	end;

	x = -1;
	y = -1;
	end = d->buf_size / 2;
	while (++x < SCREEN_WIDTH)
	{
		while (++y < SCREEN_HEIGHT / 2)
			plot(x, y, d, d->ceiling_color);
		while (++y < SCREEN_HEIGHT)
			plot(x, y, d, d->floor_color);
		y = 0;
	}
}

static void	calc_start_end(t_game *d)
{
	if (d->side == 0)
		d->perp_wall_dist = d->side_dist_x - d->delta_dist_x;
	else
		d->perp_wall_dist = d->side_dist_y - d->delta_dist_y;
	d->line_height = (int)(d->screen_height / d->perp_wall_dist);
	d->draw_start = -d->line_height / 2 + d->screen_height / 2 + d->view_shift;
	if (d->draw_start < 0)
		d->draw_start = 0;
	d->draw_end = d->line_height / 2 + d->screen_height / 2 + d->view_shift;
	if (d->draw_end >= d->screen_height)
		d->draw_end = d->screen_height - 1;
}

void	render(t_game *d)
{
	int	x;

	if (!d->img)
	{
		d->img = mlx_new_image(d->mlx, d->screen_width, d->screen_height);
		d->buf = mlx_get_game_addr(d->img, &d->pix_bits, &d->l_bytes, &d->endi);
		d->buf_size = d->screen_height * d->l_bytes;
	}
	draw_floor_and_ceiling(d);
	x = -1;
	d->time = get_time(d);
	while (++x < SCREEN_WIDTH)
	{
		update_vars(x, d);
		run_dda(d);
		calc_start_end(d);
		draw_strip(d, x);
	}
	get_move_rot_speeds(d);
	mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
}
