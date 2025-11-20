/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaimaqaroot <omaimaqaroot@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 16:39:39 by omaimaqaroo       #+#    #+#             */
/*   Updated: 2025/10/25 16:39:41 by omaimaqaroo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/**
 * @brief Writes string on a given file descriptor
 * @details Functions writes the string s until null-terminator to a 
 * file descriptor fd. If s is null then "(null)" is written.
 * @param s Pointer to a string to be written.
 * @param fd File descriptor.
 * @return On success returns number of bytes written. If error occured -1 is 
 * returned.
*/
int	ft_putstr_fd(const char *const s, int fd)
{
	int	done;

	if (!s)
		return (write (fd, "(null)", 6));
	done = 0;
	while (s[done])
	{
		if (write(fd, &s[done], sizeof(char)) < 0)
			return (-1);
		done++;
	}
	return (done);
}
