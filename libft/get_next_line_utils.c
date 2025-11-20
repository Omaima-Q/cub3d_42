/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaimaqaroot <omaimaqaroot@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 19:42:18 by omaimaqaroo       #+#    #+#             */
/*   Updated: 2025/10/17 20:04:32 by omaimaqaroo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	cut_n_chars(char **str, ssize_t n, ssize_t len)
{
	ssize_t	i;
	char	*tmp;

	if (n == len)
	{
		free(*str);
		*str = NULL;
		return (1);
	}
	tmp = (char *) malloc(sizeof(char) * (len - n));
	if (!tmp)
		return (-1);
	i = 0;
	while (i < (len - n))
	{
		tmp[i] = (*str)[n + i];
		i++;
	}
	free(*str);
	*str = tmp;
	return (1);
}
