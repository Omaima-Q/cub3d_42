/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_v.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaimaqaroot <omaimaqaroot@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 16:39:55 by omaimaqaroo       #+#    #+#             */
/*   Updated: 2025/10/25 16:39:57 by omaimaqaroo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	is_sep(char const s, char const *c)
{
	while (*c)
	{
		if (s == *c)
			return (1);
		c++;
	}
	return (0);
}

static size_t	calc_size(char const *s, char const *c)
{
	size_t	size;
	size_t	i;

	while (is_sep(*s, c) && *s != 0)
		s++;
	i = 0;
	size = 1;
	if (*s)
		size = 2;
	while (s[i])
	{
		if (is_sep(s[i], c) && !is_sep(s[i + 1], c) && s[i + 1] != 0)
			size++;
		i++;
	}
	return (size);
}

static char	*cpy_until_c(char const *s, char const *c)
{
	size_t	i;
	char	*str;

	while (is_sep(*s, c) && *s)
		s++;
	i = 0;
	while (!is_sep(s[i], c) && s[i])
		i++;
	str = (char *) malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (!is_sep(s[i], c) && s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

static char	*next_str(char const *s, char const *c)
{
	while (*s && ((is_sep(*s, c) && is_sep(*(s + 1), c)) || !is_sep(*s, c)))
	{
		s++;
	}
	if (*s)
		s++;
	return ((char *) s);
}

/**
 * @brief Splits string into substrings separated by defined characters.
 * @details Function splits a string into substrings using characters in 
 * string @param c as separators. Substrings are terminated by a NULL pointer.
 * @param s A string to be splitted.
 * @param c A string containing separators.
 * @return A pointer to a first substring. NULL if error occured.
 * @warning NOT TESTED
*/
char	**ft_split_v(char const *s, char const *c)
{
	char	**str_arr;
	size_t	size;
	size_t	i;

	if (!s || !c)
		return (NULL);
	size = calc_size(s, c);
	str_arr = (char **) malloc(sizeof(char *) * size);
	if (!str_arr)
		return (NULL);
	i = 0;
	while (is_sep(*s, c) && *s)
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
