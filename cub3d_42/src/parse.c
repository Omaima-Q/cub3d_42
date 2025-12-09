/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 19:39:34 by omaimaqaroo       #+#    #+#             */
/*   Updated: 2025/12/09 10:57:02 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_warning(int argc, char *argv[], t_resources *content)
{
	int	fd;
	int	i;

	if (argc != 2 || !argv || !argv[0] || !argv[1])
	{
		write(STDERR_FILENO, "Error\nNumber of arguments expected: 1\n", 38);
		return (clean_content(content), -1);
	}
	i = 0;
	while (argv[1][i])
		i++;
	if (ft_strcmp(argv[1] + i - 4, ".cub") != 0)
	{
		write(STDERR_FILENO, "Error\nExtension expected: \".cub\"\n", 33);
		return (clean_content(content), -1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		write(STDERR_FILENO, "Error\n", 6);
		perror(NULL);
		return (clean_content(content), -1);
	}
	return (fd);
}

static int	assign_texture(char **texture, char *str)
{
	int	i;

	if (*texture)
		return (1 - write(STDERR_FILENO, "Error\nElement duplicate\n", 24));
	*texture = ft_strdup(str);
	if (*texture == NULL)
	{
		write(STDERR_FILENO, "Error\n", 6);
		perror(NULL);
		return (-1);
	}
	i = 0;
	while ((*texture)[i] && (*texture)[i] != '\n')
		i++;
	(*texture)[i] = 0;
	i = open(*texture, O_RDONLY);
	if (i < 0 || read(i, str, 1) < 0)
	{
		if (i >= 0)
			close(i);
		return (1 - write(STDERR_FILENO, "Error\nWrong texture file\n", 25));
	}
	close(i);
	return (1);
}

static int	parse_line(char *str, t_resources *content)
{
	static int	map_done;
	int			i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == 0 || str[i] == '\n')
	{
		if (map_done == 0 && content->rowlist)
			map_done = 1;
		return (1);
	}
	if (ft_strncmp(str + i, "NO", 2) == 0 && ft_isspace(str[i + 2]))
		return (assign_texture(&content->tex_path[0], str + i + 3));
	if (ft_strncmp(str + i, "SO", 2) == 0 && ft_isspace(str[i + 2]))
		return (assign_texture(&content->tex_path[2], str + i + 3));
	if (ft_strncmp(str + i, "WE", 2) == 0 && ft_isspace(str[i + 2]))
		return (assign_texture(&content->tex_path[3], str + i + 3));
	if (ft_strncmp(str + i, "EA", 2) == 0 && ft_isspace(str[i + 2]))
		return (assign_texture(&content->tex_path[1], str + i + 3));
	if (str[i] == 'F' && ft_isspace(str[i + 1]))
		return (assign_rgb(content->floor_rgb, str + i + 2));
	if (str[i] == 'C' && ft_isspace(str[i + 1]))
		return (assign_rgb(content->ceil_rgb, str + i + 2));
	return (add_mapline(str, content, map_done));
}

static int	parse_elements(int fd, t_resources *resources)
{
	char	*str;

	str = get_next_line(fd);
	while (str)
	{
		if (parse_line(str, resources) <= 0)
			return (free_gnl(str, fd, 0));
		free(str);
		str = get_next_line(fd);
	}
	if (errno != 0)
	{
		write(STDERR_FILENO, "Error\n", 6);
		perror(NULL);
		return (free_gnl(str, fd, -1));
	}
	if (list_to_matrix(resources) <= 0)
		return (free_gnl(str, fd, 0));
	if (check_map(resources) <= 0)
		return (free_gnl(str, fd, 0));
	return (free_gnl(str, fd, 1));
}

int	parse(int argc, char *argv[], t_resources *content)
{
	int	fd;

	fd = check_warning(argc, argv, content);
	if (fd < 0)
		return (0);
	if (parse_elements(fd, content) <= 0)
	{
		close(fd);
		clean_content(content);
		return (0);
	}
	if (close(fd) < 0)
	{
		write(STDERR_FILENO, "Error\n", 6);
		perror(NULL);
		return (0);
	}
	return (1);
}
