/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 19:38:42 by omaimaqaroo       #+#    #+#             */
/*   Updated: 2025/12/10 19:18:43 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	print_content(t_resources *content)
{
	int	i;
	int	j;

	printf("North Texture	\"%s\"\n", content->tex_path[0]);
	printf("South Texture	\"%s\"\n", content->tex_path[2]);
	printf("West Texture	\"%s\"\n", content->tex_path[3]);
	printf("East Texture	\"%s\"\n", content->tex_path[1]);
	printf("Floor %i,%i,%i\n", content->floor_rgb[0], content->floor_rgb[1],
		content->floor_rgb[2]);
	printf("Ceiling %i,%i,%i\n", content->ceil_rgb[0], content->ceil_rgb[1],
		content->ceil_rgb[2]);
	printf("MAP:\n");
	i = 0;
	while (i < content->row_qty)
	{
		j = 0;
		while (j < content->col_qty)
		{
			printf("%c", content->map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_game		data;
	t_resources	content;

	errno = 0;
	init_content(&content);
	if (parse(argc, argv, &content) <= 0)
		return (EXIT_FAILURE);
	print_content(&content);
	init(&data, &content);
	render(&data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_hook(data.win, 2, 0, key_handler, &data);
	mlx_loop(data.mlx);
	clean_content(&content);
	return (EXIT_SUCCESS);
}
