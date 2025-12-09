/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaimaqaroot <omaimaqaroot@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 16:39:21 by omaimaqaroo       #+#    #+#             */
/*   Updated: 2025/10/25 16:39:24 by omaimaqaroo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putendl_fd(const char *s, int fd)
{
	int	done;

	if (!s)
		return (write(fd, "(null)", 6));
	done = 0;
	while (s[done])
	{
		if (write(fd, &s[done], sizeof(char)) < 0)
			return (-1);
		done++;
	}
	if (write(fd, "\n", sizeof(char)) < 0)
		return (-1);
	done++;
	return (done);
}
