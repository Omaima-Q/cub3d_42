/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaimaqaroot <omaimaqaroot@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 19:39:12 by omaimaqaroo       #+#    #+#             */
/*   Updated: 2025/10/17 19:39:15 by omaimaqaroo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static int	is_open(t_resources *c, int row, int col)
{
	if (row >= c->row_qty || row < 0 || col >= c->col_qty || col < 0)
		return (1);
	if (c->map[row][col] == ' ')
		return (1);
	return (0);
}

int	check_map(t_resources *c)
{
	int	i;
	int	j;

	if (additional_check(c) < 1)
		return (0);
	i = 0;
	while (i < c->row_qty)
	{
		j = 0;
		while (j < c->col_qty)
		{
			if (c->map[i][j] != ' ' && c->map[i][j] != '1')
			{
				if (is_open(c, i - 1, j) || is_open(c, i, j + 1) || is_open(c, i
						+ 1, j) || is_open(c, i, j - 1))
				{
					write(STDERR_FILENO, "Error\nMap not enclosed\n", 23);
					return (0);
				}
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	add_rownode(t_resources *c, t_row_list *node)
{
	t_row_list	*tmp;

	if (c->rowlist == NULL)
		c->rowlist = node;
	else
	{
		tmp = c->rowlist;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = node;
	}
	return (1);
}

static int	init_map(t_resources *c)
{
	int	i;

	c->map = (int **)malloc(sizeof(int *) * (c->row_qty + 1));
	if (!c->map)
		return (-2 - write(STDERR_FILENO, "Error\n", 6));
	i = 0;
	while (i <= c->row_qty)
	{
		c->map[i] = NULL;
		i++;
	}
	i = 0;
	while (i < c->row_qty)
	{
		c->map[i] = (int *)malloc(sizeof(int) * (c->col_qty));
		if (!c->map)
		{
			write(STDERR_FILENO, "Error\n", 6);
			return (-1);
		}
		i++;
	}
	return (1);
}

int	list_to_matrix(t_resources *c)
{
	int			i;
	int			j;
	t_row_list	*tmp;

	if (init_map(c) <= 0)
		return (-1);
	i = 0;
	tmp = c->rowlist;
	while (i < c->row_qty)
	{
		j = 0;
		while (j < c->col_qty)
		{
			if (j < tmp->size)
				c->map[i][j] = tmp->row[j];
			else
				c->map[i][j] = ' ';
			j++;
		}
		tmp = tmp->next;
		i++;
	}
	return (1);
}
