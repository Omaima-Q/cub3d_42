/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaimaqaroot <omaimaqaroot@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 16:38:19 by omaimaqaroo       #+#    #+#             */
/*   Updated: 2025/10/25 16:38:20 by omaimaqaroo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Returns smaller int.
 * @details Function returns smaller value out of two.
 * @param x Integer argument to be compared.
 * @param y Integer argument to be compared.
 * @return Integer value, the smaller out of two.
*/
int	ft_min(int x, int y)
{
	if (x < y)
		return (x);
	else
		return (y);
}
