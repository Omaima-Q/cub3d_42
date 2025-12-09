/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_strv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaimaqaroot <omaimaqaroot@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 16:35:30 by omaimaqaroo       #+#    #+#             */
/*   Updated: 2025/10/25 16:35:33 by omaimaqaroo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	strv_size(const char **strv)
{
	size_t	i;

	if (!strv)
		return (0);
	i = 0;
	while (strv[i])
		i++;
	return (i);
}

static void	free_strv(char **strv)
{
	while (*strv)
	{
		free(*strv);
		*strv = NULL;
		strv++;
	}
}

char	**ft_copy_strv(const char **strv)
{
	int		size;
	char	**envp;
	int		i;

	if (strv == NULL)
		return (NULL);
	size = strv_size((const char **)strv);
	envp = (char **)malloc(sizeof(char *) * (size + 1));
	if (!envp)
		return (NULL);
	i = 0;
	while (i < size)
	{
		envp[i] = ft_strdup(strv[i]);
		if (envp[i] == NULL)
		{
			free_strv(envp + size + 1);
			return (NULL);
		}
		i++;
	}
	envp[i] = NULL;
	return (envp);
}
