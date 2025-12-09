/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 19:38:24 by omaimaqaroo       #+#    #+#             */
/*   Updated: 2025/12/09 11:08:06 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_content(t_resources *content)
{
	int	i;

	content->tex_path = (char **)malloc(sizeof(char *) * 4);
	i = 0;
	while (i < 4)
	{
		content->tex_path[i] = NULL;
		i++;
	}
	i = 0;
	while (i < 3)
	{
		content->floor_rgb[i] = -1;
		content->ceil_rgb[i] = -1;
		i++;
	}
	content->map = NULL;
	content->rowlist = NULL;
	content->row_qty = 0;
	content->col_qty = 0;
}

static void	init_player_position(t_game *data)
{
	int	i;
	int	j;
	int	l;

	i = 0;
	while (++i < data->assets->row_qty - 1)
	{
		j = 0;
		while (++j < data->assets->col_qty - 1)
		{
			l = data->assets->map[i][j];
			if (l == 'N' || l == 'E' || l == 'S' || l == 'W')
			{
				data->pos_x = i + 0.5;
				data->pos_y = j + 0.5;
				return ;
			}
		}
	}
}

static void	init_player_orientation(t_game *data)
{
	char	c;

	c = data->assets->map[(int)data->pos_x][(int)data->pos_y];
	if (c == 'N')
	{
		data->dir_x = -1.0;
		data->dir_y = 0.0;
	}
	else if (c == 'E')
		rotate(data, -M_PI_2);
	else if (c == 'S')
		rotate(data, -M_PI);
	else if (c == 'W')
		rotate(data, -3 * M_PI_2);
}

static t_texture	**init_texture(t_game *data, t_resources *content)
{
	t_texture	**tex;
	int			i;

	tex = (t_texture **)malloc(sizeof(t_texture *) * 4);
	i = -1;
	while (++i < 4)
		tex[i] = (t_texture *)malloc(sizeof(t_texture));
	i = -1;
	while (++i < 4)
	{
		tex[i]->path = content->tex_path[i];
		tex[i]->img = mlx_xpm_file_to_image(data->mlx, tex[i]->path,
				&tex[i]->width, &tex[i]->height);
		if (tex[i]->img == NULL)
			error_msg("ERROR: tex[i]->img is NULL", data);
		tex[i]->buf = mlx_get_game_addr(tex[i]->img, &tex[i]->pix_bits,
				&tex[i]->l_bytes, &tex[i]->endi);
	}
	return (tex);
}

void	init(t_game *data, t_resources *content)
{
	data->assets = content;
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		error_msg("ERROR: data->mlx is NULL\n", data);
	data->win = mlx_new_window(data->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "CUB3D");
	if (data->win == NULL)
		error_msg("ERROR: data->win is NULL\n", data);
	data->img = NULL;
	init_player_position(data);
	data->dir_x = -1.0;
	data->dir_y = 0.0;
	data->plane_x = 0.0;
	data->plane_y = 0.66;
	init_player_orientation(data);
	data->time = get_time(data);
	data->old_time = 0.0;
	data->texture = init_texture(data, content);
}
