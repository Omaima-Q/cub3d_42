/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaimaqaroot <omaimaqaroot@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 19:40:22 by omaimaqaroo       #+#    #+#             */
/*   Updated: 2025/10/27 17:39:52 by omaimaqaroo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "mlx.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define SCREEN_WIDTH 1200
# define SCREEN_HEIGHT 800
# define TEX_WIDTH 256
# define TEX_HEIGHT 256
# define MAP_WIDTH 24
# define MAP_HEIGHT 24

# define ESC 53
# define KEY_7 89
# define KEY_8 91
# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2
# define KEY_RIGHT_ARROW 124
# define KEY_LEFT_ARROW 123

typedef struct s_texture
{
	int					height;
	int					width;
	void				*img;
	char				*path;
	char				*buf;
	int					pix_bits;
	int					l_bytes;
	int					endi;
}						t_texture;

typedef struct s_row_list
{
	int					*row;
	int					size;
	struct s_row_list	*next;
}						t_row_list;

typedef struct s_game_assets
{
	char				**tex_path;
	int					floor_rgb[3];
	int					ceil_rgb[3];
	int					**map;
	t_row_list			*rowlist;
	int					row_qty;
	int					col_qty;
}						t_resources;

typedef struct s_data
{
	void				*mlx;
	void				*win;
	int					pix_bits;
	int					l_bytes;
	int					endi;
	void				*img;
	char				*buf;
	int					buf_size;
	int					map_width;
	int					map_heigth;
	int					screen_width;
	int					screen_height;
	int					**world_map;
	double				pos_x;
	double				pos_y;
	double				dir_x;
	double				dir_y;
	double				plane_x;
	double				plane_y;
	long int			time;
	long int			old_time;
	double				camera_x;
	double				ray_dir_x;
	double				ray_dir_y;
	int					map_x;
	int					map_y;
	double				side_dist_x;
	double				side_dist_y;
	double				delta_dist_x;
	double				delta_dist_y;
	double				perp_wall_dist;
	int					step_x;
	int					step_y;
	double				step;
	int					side;
	int					line_height;
	int					view_shift;
	int					draw_start;
	int					draw_end;
	int					tex_num;
	double				wall_x;
	int					tex_x;
	long double			frame_time;
	double				move_speed;
	double				rot_speed;
	int					floor_color;
	int					ceiling_color;
	t_resources			*assets;
	t_texture			**texture;
}						t_game;

void					init(t_game *d, t_resources *content);
void					render(t_game *d);
void					run_dda(t_game *d);
void					get_move_rot_speeds(t_game *d);
void					plot(int x, int y, t_game *d, int color);
void					draw_floor_and_ceiling(t_game *d);
void					render(t_game *d);
void					update_vars(int x, t_game *d);
void					draw_strip(t_game *d, int x);
int						close_window(t_game *d);
int						key_handler(int key, t_game *d);
void					error_msg(char *str, t_game *data);
long int				get_time(t_game *d);
void					free_all(t_game *d);
int						parse(int argc, char *argv[], t_resources *content);
int						assign_rgb(int *rgb, char *str);
int						add_mapline(char *str, t_resources *c, int done);
int						add_rownode(t_resources *c, t_row_list *node);
void					clean_content(t_resources *c);
int						list_to_matrix(t_resources *c);
int						check_map(t_resources *c);
int						check_char(int c, int check);
int						additional_check(t_resources *c);
void					init_content(t_resources *content);
void					rotate_right(t_game *d, double rad);
void					rotate_left(t_game *d, double rad);
uint32_t				get_hex_from_rgb(unsigned char r, unsigned char g,
							unsigned char b);
t_texture				**init_texture(t_game *d, t_resources *content);

#endif
