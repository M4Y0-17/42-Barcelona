/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayo-ca <amayo-ca@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 12:10:29 by amayo-ca          #+#    #+#             */
/*   Updated: 2022/02/08 12:16:15 by amayo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	array_lenght;
	size_t	count;
	char	*ptr;

	if (!s)
		return (NULL);
	array_lenght = ft_strlen(s);
	ptr = malloc(sizeof(char) * array_lenght + 1);
	if (!ptr)
		return (NULL);
	count = 0;
	while (s[count])
	{
		ptr[count] = f(count, s[count]);
		count++;
	}
	ptr[count] = '\0';
	return (ptr);
}
