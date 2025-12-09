/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaimaqaroot <omaimaqaroot@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 20:27:28 by omaimaqaroo       #+#    #+#             */
/*   Updated: 2025/10/17 20:27:40 by omaimaqaroo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;

	i = 0;
	j = 0;
	while (j < dstsize && dst[j])
		j++;
	dst_len = j;
	while (src[i])
	{
		if (j < dstsize - 1 && j != dstsize)
		{
			dst[j] = src[i];
			j++;
		}
		i++;
	}
	if (j != dstsize)
		dst[j] = '\0';
	return (dst_len + i);
}
