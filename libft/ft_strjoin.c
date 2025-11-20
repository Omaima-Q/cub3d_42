/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaimaqaroot <omaimaqaroot@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 20:27:55 by omaimaqaroo       #+#    #+#             */
/*   Updated: 2025/10/17 20:28:06 by omaimaqaroo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strjoin;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = 0;
	len2 = 0;
	while (s1[len1])
		len1++;
	while (s2[len2])
		len2++;
	strjoin = (char *) malloc(sizeof(char) * (len1 + len2 + 1));
	if (!strjoin)
		return (NULL);
	len1 = 0;
	while (*s1)
		strjoin[len1++] = *(s1++);
	while (*s2)
		strjoin[len1++] = *(s2++);
	strjoin[len1] = 0;
	return (strjoin);
}
