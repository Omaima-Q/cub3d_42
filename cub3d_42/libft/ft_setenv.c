/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaimaqaroot <omaimaqaroot@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 16:39:47 by omaimaqaroo       #+#    #+#             */
/*   Updated: 2025/10/25 16:39:48 by omaimaqaroo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	index_envar(const char *name, char **envp)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(name);
	while (envp[i])
	{
		if (ft_strncmp(name, envp[i], len) == 0)
		{
			if (envp[i][len] == '\0' || envp[i][len] == '=')
				return (i);
		}
		i++;
	}
	return (-1);
}

static int	index_expand_env(char ***envp)
{
	int		size;
	int		i;
	char	**strv;

	size = 0;
	while (envp[0][size])
		size++;
	strv = (char **) malloc(sizeof(char *) * (size + 2));
	if (strv == NULL)
		return (-1);
	strv[size + 1] = NULL;
	strv[size] = NULL;
	i = 0;
	while (i < size)
	{
		strv[i] = envp[0][i];
		i++;
	}
	free(*envp);
	*envp = strv;
	return (size);
}

static char	*create_entry(const char *s1, const char *s2, const char *s3)
{
	char	*tmp;
	char	*str;

	if (s3 == NULL)
		return (ft_strdup(s1));
	tmp = ft_strjoin(s1, s2);
	if (tmp == NULL)
		return (NULL);
	str = ft_strjoin(tmp, s3);
	if (str == NULL)
	{
		free(tmp);
		return (NULL);
	}
	free(tmp);
	return (str);
}

int	ft_setenv(const char *name, const char *value, int overw, char ***envp)
{
	int		index;
	char	*str;

	index = index_envar(name, *envp);
	if (index < 0 || overw)
	{
		str = create_entry(name, "=", value);
		if (str == NULL)
			return (-1);
		if (index < 0)
			index = index_expand_env(envp);
		if (index < 0)
		{
			free(str);
			return (-1);
		}
	}
	else
		return (0);
	if (envp[0][index])
		free(envp[0][index]);
	envp[0][index] = str;
	return (0);
}
