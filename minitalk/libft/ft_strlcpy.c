/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayo-ca <amayo-ca@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 21:04:55 by amayo-ca          #+#    #+#             */
/*   Updated: 2022/02/10 12:11:19 by amayo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_lng;
	size_t	des_lng;

	src_lng = 0;
	des_lng = 0;
	while (src[src_lng] != '\0')
		src_lng++;
	while (dest[des_lng] != '\0')
		des_lng++;
	if (dstsize == 0)
		return (src_lng);
	i = 0;
	while (src[i] != '\0' && i < (dstsize - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_lng);
}
