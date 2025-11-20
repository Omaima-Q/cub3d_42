/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaimaqaroot <omaimaqaroot@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 16:40:32 by omaimaqaroo       #+#    #+#             */
/*   Updated: 2025/10/25 16:40:34 by omaimaqaroo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	str_is_less(char *str, long max, int lim)
{
	long	num;

	num = 0;
	while (lim)
	{
		num = (num * 10) + (*str - '0');
		str++;
		lim--;
	}
	if (num > max)
		return (0);
	return (1);
}

static int	is_int(int sign, char *str)
{
	long	order;
	long	max;
	int		lim;
	int		i;

	max = INT_MAX;
	if (sign < 0)
		max = (long) -1 * INT_MIN;
	order = 1;
	lim = 0;
	while (max / order)
	{
		order *= 10;
		lim++;
	}
	order /= 10;
	i = 0;
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] != '\0' || i > lim)
		return (0);
	if (i == lim)
		return (str_is_less(str, max, lim));
	return (1);
}

/**
 * @brief Checks if string is a number and valid parameter for ft_atoi().
 * @details A function checks whether a string is a number(digits)
 * readable by ft_atoi() and fits within int limits.
 * @param str A pointer to a string representing a number.
 * @return Returns 1 if string is an int, otherwise returns 0.
*/
int	ft_str_is_int(char *str)
{
	int	sign;

	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (!ft_isdigit(*str))
		return (0);
	while (*str == '0')
		str++;
	if (*str != '\0' && (!ft_isdigit(*str) || !is_int(sign, str)))
		return (0);
	return (1);
}
