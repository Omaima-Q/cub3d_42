/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaimaqaroot <omaimaqaroot@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 16:36:15 by omaimaqaroo       #+#    #+#             */
/*   Updated: 2025/10/25 16:36:17 by omaimaqaroo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_getenv(const char *name, char **envp)
{
	size_t	len;
	size_t	i;

	if (!name || !envp || ft_strchr(name, '='))
		return (NULL);
	len = ft_strlen(name);
	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(name, envp[i], len) && envp[i][len] == '=')
			return ((char *)(envp[i] + len + 1));
		i++;
	}
	return (NULL);
}
