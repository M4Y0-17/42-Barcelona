/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayo-ca <amayo-ca@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 12:58:09 by amayo-ca          #+#    #+#             */
/*   Updated: 2022/01/27 11:01:03 by amayo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*ptr;

	if (nitems == 0 || size == 0)
		return (malloc(0));
	ptr = malloc (nitems * size);
	if (ptr == NULL)
		return (ptr);
	ft_bzero(ptr, size * nitems);
	return (ptr);
}
