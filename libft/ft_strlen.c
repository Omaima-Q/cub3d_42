/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaimaqaroot <omaimaqaroot@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 20:08:49 by omaimaqaroo       #+#    #+#             */
/*   Updated: 2025/10/17 20:08:51 by omaimaqaroo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s || s == NULL)
	{
		printf("arg is NULL in ft_strlen\n");
		return (0);
	}
	i = 0;
	while (s && *(s + i))
	{
		i++;
	}
	return (i);
}
