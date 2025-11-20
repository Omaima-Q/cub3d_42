/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dim.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaimaqaroot <omaimaqaroot@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 16:35:43 by omaimaqaroo       #+#    #+#             */
/*   Updated: 2025/10/25 16:35:45 by omaimaqaroo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Returns positive difference between two integers.
 * @details Function returns positive difference of two integers x and y.
 * @param x First integer argument.
 * @param y Second integer argument.
 * @return Difference between arguments as non-negative integer value,.
*/
int	ft_dim(int x, int y)
{
	if (x < y)
		return (y - x);
	else
		return (x - y);
}
