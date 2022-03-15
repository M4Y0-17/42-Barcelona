/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayo-ca <amayo-ca@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:54:32 by amayo-ca          #+#    #+#             */
/*   Updated: 2022/01/18 21:01:49 by amayo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t len)
{
	size_t			i;
	unsigned char	*dstc;
	unsigned char	*srcc;

	if ((str1 == NULL) & (str2 == NULL))
		return (NULL);
	dstc = (unsigned char *)str1;
	srcc = (unsigned char *)str2;
	i = 1;
	if (srcc < dstc)
	{
		while (i <= len)
		{
			dstc[len - i] = srcc[len - i];
			i++;
		}
	}
	else
		ft_memcpy(dstc, srcc, len);
	return (str1);
}
