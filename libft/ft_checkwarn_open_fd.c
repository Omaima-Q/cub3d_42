/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkwarn_open_fd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaimaqaroot <omaimaqaroot@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 16:35:06 by omaimaqaroo       #+#    #+#             */
/*   Updated: 2025/10/25 16:35:13 by omaimaqaroo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	ft_checkwarn_open_fd(int fd)
{
	if (fd < 0)
	{
		ft_putstr_fd("Failed to open the file\n", STDERR_FILENO);
		return (-1);
	}
	return (0);
}
