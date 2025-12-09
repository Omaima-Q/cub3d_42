/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaimaqaroot <omaimaqaroot@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 20:17:48 by omaimaqaroo       #+#    #+#             */
/*   Updated: 2025/10/17 20:17:51 by omaimaqaroo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	total_size;

	if (count >= INT_MAX && size >= INT_MAX)
		return (NULL);
	if (size == 0 || count == 0)
	{
		count = 1;
		size = 1;
	}
	if (count >= ((size_t) - 1) / size)
		return (NULL);
	total_size = count * size;
	ptr = (void *) malloc(total_size);
	if (!ptr)
		return (NULL);
	while (total_size)
	{
		total_size--;
		*(char *)(ptr + total_size) = 0;
	}
	return (ptr);
}
