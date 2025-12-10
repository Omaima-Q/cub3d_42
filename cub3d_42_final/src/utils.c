/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 19:40:01 by omaimaqaroo       #+#    #+#             */
/*   Updated: 2025/12/09 11:31:37 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

long int	get_time(t_game *data)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		error_msg("gettimeofday() failed in get_time()\n", data);
	return ((tv.tv_sec * (long int)1000) + (tv.tv_usec / 1000));
}

void	rotate(t_game *data, double rad)
{
	double	old_dir;
	double	old_plane_x;

	old_dir = data->dir_x;
	data->dir_x = data->dir_x * cos(rad) - data->dir_y * sin(rad);
	data->dir_y = old_dir * sin(rad) + data->dir_y * cos(rad);
	old_plane_x = data->plane_x;
	data->plane_x = data->plane_x * cos(rad) - data->plane_y * sin(rad);
	data->plane_y = old_plane_x * sin(rad) + data->plane_y * cos(rad);
}

void	get_move_rot_speeds(t_game *data)
{
	data->old_time = data->time;
	data->time = get_time(data);
	data->frame_time = (data->time - data->old_time) / 1000.0;
	data->move_speed = data->frame_time * 50.0;
	data->rot_speed = data->frame_time * 12.0;
}
