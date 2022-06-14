/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayo-ca <amayo-ca@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 17:18:36 by amayo-ca          #+#    #+#             */
/*   Updated: 2022/05/19 15:15:50 by amayo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static char	*ft_to_bit(char *s, size_t i, size_t j, int pid)
{
	char	*ret;
	int		c;
	int		bytes;

	i = 0;
	j = 7;
	ret = ft_calloc(i * 8 + 1, sizeof(char));
	if (ret == NULL)
		return (NULL);
	while (s[i])
	{
		c = s[i++];
		bytes = 8;
		while (bytes > 0)
		{
			if ((c & (1 << j--)) != 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(80);
			bytes--;
		}
		j = 7;
	}
	return (ret);
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*bits;

	if (argc != 3)
	{
		ft_printf("wrong number of arguments\n");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	bits = ft_to_bit(argv[2], 0, 0, pid);
	if (bits == NULL)
	{
		ft_printf("allocation went wrong\n");
		return (0);
	}
	free(bits);
	return (0);
}
