/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaimaqaroot <omaimaqaroot@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 19:38:42 by omaimaqaroo       #+#    #+#             */
/*   Updated: 2025/11/19 19:55:16 by omaimaqaroo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	print_content(t_resources *c)    // static means we are using this function only here , and it's only used by the int main
{
	int	i;
	int	j;

	printf("North Texture	\"%s\"\n", c->tex_path[0]);
	printf("South Texture	\"%s\"\n", c->tex_path[2]);
	printf("West Texture	\"%s\"\n", c->tex_path[3]);
	printf("East Texture	\"%s\"\n", c->tex_path[1]);
	printf("Floor %i,%i,%i\n", c->floor_rgb[0], c->floor_rgb[1],
		c->floor_rgb[2]);
	printf("Ceiling %i,%i,%i\n", c->ceil_rgb[0], c->ceil_rgb[1],
		c->ceil_rgb[2]);
	printf("MAP:\n");
	i = 0;
	while (i < c->row_qty)
	{
		j = 0;
		while (j < c->col_qty)
		{
			printf("%c", c->map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_game data;
	t_resources content;

	errno = 0;									//I reset errno to 0 to ensure clean error handling throughout the program
	init_content(&content);     				//This initializes the content structure with default/null values to avoid undefined behavior

	// Parse and validate the .cub file - returns 0 or negative on error
	if (parse(argc, argv, &content) <= 0)
		return (EXIT_FAILURE);
	print_content(&content);					// This prints the parsed data - used for debugging during development
	init(&data, &content);      				// Here I initialize the MLX connection, create the window, set up the player's starting position and direction based on the map, and prepare everything for rendering
	render(&data);              								// this draws the initial frame 
	mlx_key_hook(data.win, key_handler, &data);    				// Register keyboard input handler
	mlx_hook(data.win, 17, 0, close_window, &data);				// handle window close button
	mlx_loop(data.mlx);											// Start MLX event loop - keeps window open and responsive
	return (EXIT_SUCCESS);
}
