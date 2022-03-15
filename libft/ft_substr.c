/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayo-ca <amayo-ca@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:44:53 by amayo-ca          #+#    #+#             */
/*   Updated: 2022/02/08 16:04:58 by amayo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	size_src;
	size_t	count;
	char	*ptr;

	if (!s)
		return (NULL);
	count = 0;
	size_src = ft_strlen(s);
	if (start > size_src)
		ptr = malloc(sizeof(char) + 1);
	else if (size_src - start < len)
		ptr = malloc(sizeof(char) * (size_src - start) + 1);
	else
		ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	while (start + count < size_src && count < len)
	{
		ptr[count] = s[start + count];
		count++;
	}
	ptr[count] = '\0';
	return (ptr);
}
