/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_appendC.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayo-ca <amayo-ca@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 14:05:12 by amayo-ca          #+#    #+#             */
/*   Updated: 2022/05/12 15:24:24 by amayo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_appendc(char *str, char c)
{
	size_t	i;
	char	*tmp;

	tmp = malloc(ft_strlen(str) + 2);
	if (tmp == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = c;
	tmp[i + 1] = '\0';
	free(str);
	return (tmp);
}
