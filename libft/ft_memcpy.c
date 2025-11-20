/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaimaqaroot <omaimaqaroot@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 16:37:54 by omaimaqaroo       #+#    #+#             */
/*   Updated: 2025/10/25 16:37:56 by omaimaqaroo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*dest_str;
	char	*src_str;

	if (dest == NULL && src == NULL)
		return (dest);
	dest_str = (char *) dest;
	src_str = (char *) src;
	while (n)
	{
		n--;
		dest_str[n] = src_str[n];
	}
	return (dest);
}
