/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 19:38:12 by omaimaqaroo       #+#    #+#             */
/*   Updated: 2025/12/09 10:46:57 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	w_s_keys(int key, t_game *data)
{
	if (key == KEY_W)
	{
		if (data->assets->map[(int)(data->pos_x + data->dir_x
				* data->move_speed)][(int)data->pos_y] != '1')
			data->pos_x += data->dir_x * data->move_speed;
		if (data->assets->map[(int)data->pos_x][(int)(data->pos_y + data->dir_y
			* data->move_speed)] != '1')
			data->pos_y += data->dir_y * data->move_speed;
	}
	if (key == KEY_S)
	{
		if (data->assets->map[(int)(data->pos_x - data->dir_x
				* data->move_speed)][(int)data->pos_y] != '1')
			data->pos_x -= data->dir_x * data->move_speed;
		if (data->assets->map[(int)data->pos_x][(int)(data->pos_y - data->dir_y
			* data->move_speed)] != '1')
			data->pos_y -= data->dir_y * data->move_speed;
	}
}

static void	a_d_keys(int key, t_game *data)
{
	if (key == KEY_D)
	{
		if (data->assets->map[(int)(data->pos_x + data->plane_x
				* data->move_speed)][(int)data->pos_y] != '1')
			data->pos_x += data->plane_x * data->move_speed;
		if (data->assets->map[(int)data->pos_x][(int)(data->pos_y
			+ data->plane_y * data->move_speed)] != '1')
			data->pos_y += data->plane_y * data->move_speed;
	}
	if (key == KEY_A)
	{
		if (data->assets->map[(int)(data->pos_x - data->plane_x
				* data->move_speed)][(int)data->pos_y] != '1')
			data->pos_x -= data->plane_x * data->move_speed;
		if (data->assets->map[(int)data->pos_x][(int)(data->pos_y
			- data->plane_y * data->move_speed)] != '1')
			data->pos_y -= data->plane_y * data->move_speed;
	}
}

int	close_window(t_game *data)
{
	free_all(data);
	exit(0);
	return (0);
}

int	key_handler(int key, t_game *data)
{
	if (key != ESC)
	{
		if (key == KEY_W || key == KEY_S)
			w_s_keys(key, data);
		if (key == KEY_A || key == KEY_D)
			a_d_keys(key, data);
		if (key == KEY_LEFT_ARROW)
			rotate(data, data->rot_speed);
		if (key == KEY_RIGHT_ARROW)
			rotate(data, -data->rot_speed);
		render(data);
	}
	if (key == ESC)
		close_window(data);
	return (0);
}
