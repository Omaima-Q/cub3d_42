/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_wspace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaimaqaroot <omaimaqaroot@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 16:40:05 by omaimaqaroo       #+#    #+#             */
/*   Updated: 2025/10/25 16:40:06 by omaimaqaroo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

static size_t	calc_size(char const *s)
{
	size_t	size;
	size_t	i;

	while (ft_isspace(*s) && *s != 0)
		s++;
	i = 0;
	size = 1;
	if (*s)
		size = 2;
	while (s[i])
	{
		if (ft_isspace(s[i]) && !ft_isspace(s[i + 1]) && s[i + 1] != 0)
			size++;
		i++;
	}
	return (size);
}

static char	*cpy_until_c(char const *s)
{
	size_t	i;
	char	*str;

	while (ft_isspace(*s) && *s)
		s++;
	i = 0;
	while (!ft_isspace(s[i]) && s[i])
		i++;
	str = (char *) malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (!ft_isspace(s[i]) && s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

static char	*next_str(char const *s)
{
	while (*s && ((ft_isspace(*s) && ft_isspace(*(s + 1))) || !ft_isspace(*s)))
	{
		s++;
	}
	if (*s)
		s++;
	return ((char *) s);
}

/**
 * @brief Splits string into substrings separated by white spaces.
 * @details Function splits a string into substrings using a separators
 * defined by ft_isspace(). Substrings are terminated by a NULL pointer.
 * @param s A string to be splitted.
 * @return A pointer to a first substring. NULL if error occured.
*/
char	**ft_split_wspace(char const *s)
{
	char	**str_arr;
	size_t	size;
	size_t	i;

	if (!s)
		return (NULL);
	size = calc_size(s);
	str_arr = (char **) malloc(sizeof(char *) * size);
	if (!str_arr)
		return (NULL);
	i = 0;
	while (ft_isspace(*s) && *s)
		s++;
	while (i < size - 1)
	{
		str_arr[i] = (char *) cpy_until_c(s);
		if (!str_arr[i++])
		{
			free(str_arr);
			return (NULL);
		}
		s = next_str(s);
	}
	str_arr[size - 1] = NULL;
	return (str_arr);
}
