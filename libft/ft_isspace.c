/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaimaqaroot <omaimaqaroot@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 16:37:09 by omaimaqaroo       #+#    #+#             */
/*   Updated: 2025/10/25 16:37:11 by omaimaqaroo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Function tests for white-space characters.
 * @details Function tests if a character is one of the following:
 * '\t' '\n' '\v' '\f' '\t' ' '
 * @param c A character to be tested.
 * @return Returns zero if the character test false and returns non-zero if
 * the character tests true.
*/
int	ft_isspace(int c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r')
		return (1);
	if (c == ' ')
		return (1);
	return (0);
}
