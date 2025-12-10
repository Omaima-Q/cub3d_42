/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 19:39:12 by omaimaqaroo       #+#    #+#             */
/*   Updated: 2025/12/09 10:19:03 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static int	is_open(t_resources *content, int row, int col)
{
	if (row >= content->row_qty || row < 0 || col >= content->col_qty
		|| col < 0)
		return (1);
	if (content->map[row][col] == ' ')
		return (1);
	return (0);
}

int	check_map(t_resources *content)
{
	int	i;
	int	j;

	if (additional_check(content) < 1)
		return (0);
	i = 0;
	while (i < content->row_qty)
	{
		j = 0;
		while (j < content->col_qty)
		{
			if (content->map[i][j] != ' ' && content->map[i][j] != '1')
			{
				if (is_open(content, i - 1, j) || is_open(content, i, j + 1)
					|| is_open(content, i + 1, j) || is_open(content, i, j - 1))
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

int	add_rownode(t_resources *content, t_row_list *node)
{
	t_row_list	*tmp;

	if (content->rowlist == NULL)
		content->rowlist = node;
	else
	{
		tmp = content->rowlist;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = node;
	}
	return (1);
}

static int	init_map(t_resources *content)
{
	int	i;

	content->map = (int **)malloc(sizeof(int *) * (content->row_qty + 1));
	if (!content->map)
		return (-2 - write(STDERR_FILENO, "Error\n", 6));
	i = 0;
	while (i <= content->row_qty)
	{
		content->map[i] = NULL;
		i++;
	}
	i = 0;
	while (i < content->row_qty)
	{
		content->map[i] = (int *)malloc(sizeof(int) * (content->col_qty));
		if (!content->map)
		{
			write(STDERR_FILENO, "Error\n", 6);
			return (-1);
		}
		i++;
	}
	return (1);
}

int	list_to_matrix(t_resources *content)
{
	int			i;
	int			j;
	t_row_list	*tmp;

	if (init_map(content) <= 0)
		return (-1);
	i = 0;
	tmp = content->rowlist;
	while (i < content->row_qty)
	{
		j = 0;
		while (j < content->col_qty)
		{
			if (j < tmp->size)
				content->map[i][j] = tmp->row[j];
			else
				content->map[i][j] = ' ';
			j++;
		}
		tmp = tmp->next;
		i++;
	}
	return (1);
}
