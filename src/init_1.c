/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaimaqaroot <omaimaqaroot@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 19:38:34 by omaimaqaroo       #+#    #+#             */
/*   Updated: 2025/10/17 19:38:36 by omaimaqaroo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_texture	**init_texture(t_game *d, t_resources *content)
{
	t_texture	**tex;
	int			i;

	tex = (t_texture **)malloc(sizeof(t_texture *) * 4);  // not yet allocated
	i = -1;
	while (++i < 4)
		tex[i] = (t_texture *)malloc(sizeof(t_texture));	// empty structs ready
	i = -1;
	while (++i < 4)
	{
		tex[i]->path = content->tex_path[i];					// Store the file path
		tex[i]->img = mlx_xpm_file_to_image(d->mlx, tex[i]->path,		// Load XPM file into MLX image
				&tex[i]->width, &tex[i]->height);
		if (tex[i]->img == NULL)								// Check if loading failed
			error_msg("ERROR: tex[i]->img is NULL", d);
		tex[i]->buf = mlx_get_game_addr(tex[i]->img, &tex[i]->pix_bits,		// Get direct access to pixel data
				&tex[i]->l_bytes, &tex[i]->endi);
	}
	return (tex);
}

// Purpose of This function loads the 4 wall textures (North, South, East, West) 
// from XPM image files into memory so you can draw them on walls during raycasting.
// Most modern computers (Intel, AMD) use Little Endian (endi = 0).
// MLX gives you endi so your code works on any computer:
