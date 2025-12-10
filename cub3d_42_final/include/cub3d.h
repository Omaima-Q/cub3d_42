/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 19:40:22 by omaimaqaroo       #+#    #+#             */
/*   Updated: 2025/12/10 15:42:02 by yalkhidi         ###   ########.fr       */
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
# include <stdint.h>

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
	int					draw_start;
	int					draw_end;
	double				wall_x;
	int					tex_x;
	long double			frame_time;
	double				move_speed;
	double				rot_speed;
	t_resources			*assets;
	t_texture			**texture;
}						t_game;

void					init(t_game *data, t_resources *content);
void					render(t_game *data);
void					get_move_rot_speeds(t_game *data);
void					plot(int x, int y, t_game *data, int color[]);
void					draw_floor_and_ceiling(t_game *data);
void					init_dda_steps(t_game *data);
void					fill_strip_buffer(t_game *data, int x);
int						close_window(t_game *data);
int						key_handler(int key, t_game *data);
void					error_msg(char *str, t_game *dataata);
long int				get_time(t_game *data);
void					free_all(t_game *data);
int						parse(int argc, char *argv[], t_resources *content);
int						assign_rgb(int *rgb, char *str);
int						add_mapline(char *str, t_resources *content, int done);
int						add_rownode(t_resources *content, t_row_list *node);
void					clean_content(t_resources *content);
int						list_to_matrix(t_resources *content);
int						check_map(t_resources *content);
int						check_char(int c, int check);
int						additional_check(t_resources *content);
void					init_content(t_resources *content);
void					rotate(t_game *data, double rad);
int						free_gnl(char *line, int fd, int ret_val);
#endif
