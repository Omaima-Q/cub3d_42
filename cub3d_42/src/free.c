/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 19:37:44 by omaimaqaroo       #+#    #+#             */
/*   Updated: 2025/12/09 10:11:07 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clean_content(t_resources *content)
{
	t_row_list	*tmp;
	t_row_list	*tmp2;
	int			i;

	free(content->tex_path[0]);
	free(content->tex_path[1]);
	free(content->tex_path[2]);
	free(content->tex_path[3]);
	free(content->tex_path);
	tmp = content->rowlist;
	while (tmp)
	{
		tmp2 = tmp->next;
		if (tmp->row)
			free(tmp->row);
		if (tmp)
			free(tmp);
		tmp = tmp2;
	}
	i = -1;
	while (content->map && ++i < content->row_qty)
		if (content->map[i])
			free(content->map[i]);
	if (content->map)
		free(content->map);
}

static void	clean_textures(t_game *data)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		mlx_destroy_image(data->mlx, data->texture[i]->img);
		free(data->texture[i]);
	}
	free(data->texture);
}

void	error_msg(char *str, t_game *data)
{
	printf("%s\n", str);
	if (data)
		free_all(data);
	exit(0);
}

void	free_all(t_game *data)
{
	clean_content(data->assets);
	clean_textures(data);
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	return ;
}

int	free_gnl(char *line, int fd, int ret_val)
{
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	return (ret_val);
}
