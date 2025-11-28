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
	// Store previous frame's timestamp
	d->old_time = d->time;

	// Get current timestamp in milliseconds
	d->time = get_time(d);

	// Calculate how long this frame took (in seconds)
    // Dividing by 1000.0 converts milliseconds to seconds
	d->frame_time = (d->time - d->old_time) / 1000.0;

	// Movement speed: 50 units per second
    // Multiplying by frame_time gives distance to move THIS frame
    // Example: at 60 FPS, frame_time ≈ 0.0167s, so move_speed ≈ 0.835 units
	d->move_speed = d->frame_time * 50.0;

	// Rotation speed: 12 radians per second (very fast rotation)
    // About 687 degrees per second
	d->rot_speed = d->frame_time * 12.0;
}

// Make movement same speed on all computers

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

// Draw one pixel to screen buffer

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

// Calculate wall strip height and position

void	render(t_game *d)
{
	int	x;
	
	// create the image buffer we'll draw into
	if (!d->img)
	{
		// Get direct access to the image's pixel buffer
        // buf = pointer to pixel data array
        // pix_bits = bits per pixel (usually 32)
        // l_bytes = bytes per line (width * 4)
        // endi = endianness (byte order: 0=little, 1=big)
		d->img = mlx_new_image(d->mlx, d->screen_width, d->screen_height);
		d->buf = mlx_get_game_addr(d->img, &d->pix_bits, &d->l_bytes, &d->endi);

		// Calculate total buffer size for bounds checking
		d->buf_size = d->screen_height * d->l_bytes;
	}
	// Step 1: Fill background with ceiling and floor colors
	draw_floor_and_ceiling(d);
	x = -1;  					// Start at -1 because we increment at loop start
	d->time = get_time(d);      // Get current timestamp for this frame

	// Step 2: Cast one ray for each vertical column of pixels
    // This creates the 3D perspective effect
	while (++x < SCREEN_WIDTH)
	{
		// Calculate this ray's direction based on column position
		update_vars(x, d);

		// Trace the ray through the map until it hits a wall
		run_dda(d);

		// Calculate how tall the wall should appear on screen
		calc_start_end(d);

		// Draw this vertical strip with the appropriate texture
		draw_strip(d, x);
	}
	// Calculate movement and rotation speeds based on frame time
    // This ensures consistent movement regardless of frame rate
	get_move_rot_speeds(d);

	// Finally, display the completed image on the window
	mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
}


