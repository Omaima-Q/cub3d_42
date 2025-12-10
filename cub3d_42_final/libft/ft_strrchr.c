/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaimaqaroot <omaimaqaroot@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 20:05:20 by omaimaqaroo       #+#    #+#             */
/*   Updated: 2025/10/17 20:05:55 by omaimaqaroo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*last_pos = NULL;

	while (*s)
	{
		if (*s == (char)c)
			last_pos = s;
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return ((char *)last_pos);
}