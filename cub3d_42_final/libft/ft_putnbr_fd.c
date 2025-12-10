/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaimaqaroot <omaimaqaroot@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 16:39:31 by omaimaqaroo       #+#    #+#             */
/*   Updated: 2025/10/25 16:39:33 by omaimaqaroo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putnbr_fd(int n, int fd)
{
	long	i;
	long	a;
	char	c;
	int		done;

	a = n;
	done = 0;
	if (a < 0)
	{
		write(fd, "-", sizeof(char));
		done++;
		a = -a;
	}
	i = 10;
	while (a / i)
		i *= 10;
	i /= 10;
	while (i > 0)
	{
		c = (char)((a / i) % 10 + 48);
		write(fd, &c, sizeof(char));
		done++;
		i /= 10;
	}
	return (done);
}
