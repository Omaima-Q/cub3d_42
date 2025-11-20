/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaimaqaroot <omaimaqaroot@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 19:38:58 by omaimaqaroo       #+#    #+#             */
/*   Updated: 2025/10/17 19:39:01 by omaimaqaroo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	check_char(int c, int check)
{
	static int	p_found;

	if (check)
		return (p_found);
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
	{
		if (p_found)
		{
			write(STDERR_FILENO, "Error\nPlayer Duplicate\n", 23);
			return (0);
		}
		p_found = 1;
	}
	else if (c != ' ' && c != '1' && c != '0')
	{
		write(STDERR_FILENO, "Error\nUnexpected symbol: \"", 26);
		write(STDERR_FILENO, &c, 1);
		write(STDERR_FILENO, "\"\n", 2);
		return (0);
	}
	return (1);
}

static int	add_rowlist(char *str, t_resources *c, int size)
{
	t_row_list	*node;
	int			i;

	node = (t_row_list *)malloc(sizeof(t_row_list));
	if (!node)
		return (-1);
	node->row = (int *)malloc(sizeof(int) * size);
	if (!node->row)
	{
		free(node);
		return (-1);
	}
	node->size = size;
	node->next = NULL;
	i = 0;
	while (i < size)
	{
		node->row[i] = str[i];
		i++;
	}
	if (add_rownode(c, node) <= 0)
		return (0);
	if (node->size > c->col_qty)
		c->col_qty = node->size;
	return (1);
}

int	add_mapline(char *str, t_resources *c, int done)
{
	int	i;

	if (done || !c->tex_path[0] || !c->tex_path[2] || !c->tex_path[3]
		|| !c->tex_path[1] || c->floor_rgb[0] == -1 || c->ceil_rgb[0] == -1)
	{
		write(STDERR_FILENO, "Error\nWrong scene descriptor format\n", 36);
		return (0);
	}
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		if (check_char(str[i], 0) <= 0)
			return (0);
		i++;
	}
	if (add_rowlist(str, c, i) <= 0)
		return (-1);
	c->row_qty++;
	return (1);
}

static int	assign_int(int *val, char *str)
{
	if (ft_isdigit(*str) == 0)
	{
		write(STDERR_FILENO, "Error\nWrong RGB value\n", 22);
		return (0);
	}
	*val = 0;
	while (ft_isdigit(*str))
	{
		*val = ((*val) * 10) + (*str - '0');
		if (*val > 255)
		{
			*val = -1;
			write(STDERR_FILENO, "Error\nWrong RGB value\n", 22);
			return (0);
		}
		str++;
	}
	return (1);
}

int	assign_rgb(int *rgb, char *str)
{
	int	i;

	if (rgb[0] != -1)
	{
		write(STDERR_FILENO, "Error\nElement duplicate\n", 24);
		return (0);
	}
	i = 0;
	while (i < 3)
	{
		while (ft_isspace(*str))
			str++;
		if (assign_int(rgb + i, str) <= 0)
			return (0);
		while (ft_isdigit(*str) || ft_isspace(*str))
			str++;
		if (*str == ',')
			str++;
		i++;
	}
	return (1);
}
