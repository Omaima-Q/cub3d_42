/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 19:39:23 by omaimaqaroo       #+#    #+#             */
/*   Updated: 2025/12/09 10:11:20 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>
#include <unistd.h>

int	additional_check(t_resources *content)
{
	if (content->row_qty == 0)
	{
		write(STDERR_FILENO, "Error\nNo map\n", 13);
		return (0);
	}
	if (check_char(0, 1) != 1)
	{
		write(STDERR_FILENO, "Error\nNo player\n", 16);
		return (0);
	}
	return (1);
}
