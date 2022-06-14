/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayo-ca <amayo-ca@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 10:35:11 by amayo-ca          #+#    #+#             */
/*   Updated: 2022/02/10 10:54:39 by amayo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char	*big, const char *little, size_t len)
{
	size_t	c;

	if (*little == 0 || big == little)
		return ((char *)big);
	c = ft_strlen(little);
	while (*big && c <= len--)
	{
		if (!(ft_strncmp((char *)big, (char *)little, c)))
			return ((char *)big);
		big++;
	}
	return (NULL);
}
