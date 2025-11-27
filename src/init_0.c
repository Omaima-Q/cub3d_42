/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaimaqaroot <omaimaqaroot@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 19:38:24 by omaimaqaroo       #+#    #+#             */
/*   Updated: 2025/10/27 17:30:34 by omaimaqaroo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_player_position(t_game *d)
{
	int	i;
	int	j;
	int	l;

	i = 0;
	while (++i < d->map_heigth - 1)
	{
		j = 0;
		while (++j < d->map_width - 1)
		{
			l = d->world_map[i][j];
			if (l == 'N' || l == 'E' || l == 'S' || l == 'W')
			{
				d->pos_x = i + 0.5;
				d->pos_y = j + 0.5;
				return ;
			}
		}
	}
}

// find 'N/E/S/W' in map, set coordinates
// Loop through every cell of the map
// If cell contains 'N', 'E', 'S', or 'W':
// Set player position to center of that cell (+0.5)
// Stop searching
// The +0.5 centers the player in the tile (not at the corner).

static void	init_player_orientation(t_game *d)
{
	char	c;

	c = d->world_map[(int)d->pos_x][(int)d->pos_y];
	if (c == 'N')
	{
		d->dir_x = -1.0;		// Already facing North, no rotation needed
		d->dir_y = 0.0;
	}
	else if (c == 'E')
		rotate_right(d, M_PI_2);
	else if (c == 'S')
		rotate_right(d, M_PI);
	else if (c == 'W')
		rotate_right(d, 3 * M_PI_2);
}

// Once position is found, this sets the direction vector based on the letter:
// Letter Meaning dir_xdir_y 
// N North (up)-1.00.0 
// E East (right)rotates 90°
// S South (down)rotates 180°
// W West (left)rotates 270°
// -1 for North because In the 2D array, row 0 is at the top.
// Moving "up" means decreasing the row index, so direction is negative on the X axis.

void	init_content(t_resources *content)
{
	content->tex_path = (char **)malloc(sizeof(char *) * 4);
	content->tex_path[0] = NULL;
	content->tex_path[1] = NULL;
	content->tex_path[2] = NULL;
	content->tex_path[3] = NULL;
	content->floor_rgb[0] = -1;
	content->floor_rgb[1] = -1;
	content->floor_rgb[2] = -1;
	content->ceil_rgb[0] = -1;
	content->ceil_rgb[1] = -1;
	content->ceil_rgb[2] = -1;
	content->map = NULL;
	content->rowlist = NULL;
	content->row_qty = 0;
	content->col_qty = 0;
}

void	init_ceiling_and_floor(t_game *d, t_resources *c)
{
	d->ceiling_color = get_hex_from_rgb(c->ceil_rgb[0], c->ceil_rgb[1],
			c->ceil_rgb[2]);
	d->floor_color = get_hex_from_rgb(c->floor_rgb[0], c->floor_rgb[1],
			c->floor_rgb[2]);
}

void	init(t_game *d, t_resources *c)
{
	d->assets = c;
	d->map_width = c->col_qty;
	d->map_heigth = c->row_qty;
	d->screen_height = SCREEN_HEIGHT;
	d->screen_width = SCREEN_WIDTH;
	d->mlx = mlx_init();
	if (d->mlx == NULL)
		error_msg("ERROR: d->mlx is NULL\n", d);
	d->win = mlx_new_window(d->mlx, SCREEN_WIDTH, d->screen_height, "CUB3D");
	if (d->win == NULL)
		error_msg("ERROR: d->win is NULL\n", d);
	d->img = NULL;
	d->world_map = c->map;
	init_player_position(d);
	d->dir_x = -1.0;
	d->dir_y = 0.0;
	d->plane_x = 0.0;
	d->plane_y = 0.66;
	init_player_orientation(d);
	init_ceiling_and_floor(d, c);
	d->time = get_time(d);
	d->old_time = 0.0;
	d->view_shift = 0;
	d->texture = init_texture(d, c);
}
