/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaimaqaroot <omaimaqaroot@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 20:28:53 by omaimaqaroo       #+#    #+#             */
/*   Updated: 2025/10/25 16:40:45 by omaimaqaroo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Save a copy of a string.
 * @details The ft_strdup() function allocates sufficient memory for a copy of
 * the string s1, does the copy, and returns a pointer to it. If malloc failed,
 * NULL is returned and errno is set to ENOMEM.
 * @param s1 A string to be copied.
 * @return A pointer to a new copied string. NULL if error occured.
*/
char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		i;

	if (!s1)
		return (NULL);
	i = 0;
	while (s1[i])
		i++;
	ptr = NULL;
	ptr = malloc(sizeof(char) * (i + 1));
	if (ptr)
	{
		i = 0;
		while (s1[i])
		{
			ptr[i] = s1[i];
			i++;
		}
		ptr[i] = 0;
	}
	return (ptr);
}
