/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaimaqaroot <omaimaqaroot@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 20:30:59 by omaimaqaroo       #+#    #+#             */
/*   Updated: 2025/10/17 20:31:09 by omaimaqaroo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	calc_size(char const *s, char c)
{
	size_t	size;
	size_t	i;

	while (*s == c && *s != 0)
		s++;
	i = 0;
	size = 1;
	if (*s)
		size = 2;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != 0)
			size++;
		i++;
	}
	return (size);
}

static char	*cpy_until_c(char const *s, char c)
{
	size_t	i;
	char	*str;

	while (*s == c && *s)
		s++;
	i = 0;
	while (s[i] != c && s[i])
		i++;
	str = (char *) malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] != c && s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

static char	*next_str(char const *s, char c)
{
	while (*s && ((*s == c && *(s + 1) == c) || *s != c))
	{
		s++;
	}
	if (*s)
		s++;
	return ((char *) s);
}

/**
 * @brief Splits string into substrings separated by defined character.
 * @details Function splits a string into substrings using a character 
 * as separator. Substrings are terminated by a NULL pointer.
 * @param s A string to be splitted.
 * @param c A separator character.
 * @return A pointer to a first substring. NULL if error occured.
 * @warning NOT TESTED
*/
char	**ft_split(char const *s, char c)
{
	char	**str_arr;
	size_t	size;
	size_t	i;

	if (!s)
		return (NULL);
	size = calc_size(s, c);
	str_arr = (char **) malloc(sizeof(char *) * size);
	if (!str_arr)
		return (NULL);
	i = 0;
	while (*s == c && *s)
		s++;
	while (i < size - 1)
	{
		str_arr[i] = (char *) cpy_until_c(s, c);
		if (!str_arr[i++])
		{
			free(str_arr);
			return (NULL);
		}
		s = next_str(s, c);
	}
	str_arr[size - 1] = NULL;
	return (str_arr);
}
