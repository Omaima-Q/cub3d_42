/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaimaqaroot <omaimaqaroot@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 16:36:00 by omaimaqaroo       #+#    #+#             */
/*   Updated: 2025/10/25 16:36:02 by omaimaqaroo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/**
 * @brief Frees the allocation and sets the pointer as NULL.
 * @details Frees allocations that were created via the preceding allocation 
 * functions. Sets the pointer \p ptr to NULL.
 * @param ptr A pointer to be freed.
 * @return Does not return anything.
*/
void	ft_free(void **ptr)
{
	if (*ptr)
		free(*ptr);
	*ptr = NULL;
}
