/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayo-ca <amayo-ca@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 17:18:36 by amayo-ca          #+#    #+#             */
/*   Updated: 2022/05/19 11:55:13 by amayo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_confirm(int sig)
{
	static int				bitcount = 8;
	static unsigned char	c = '\0';

	bitcount--;
	if (sig == SIGUSR2)
	{
	}
	else
		c = c | (1 << bitcount);
	if (bitcount == 0)
	{
		write(1, &c, 1);
		bitcount = 8;
		c = '\0';
	}
}

int	main(int argc, char **argv)
{
	if (argc != 1 && argv[0][0] == '.')
	{
		ft_printf("wrong number of arguments\n");
		return (0);
	}
	ft_printf("Server PID: %u\n", getpid());
	signal(SIGUSR1, ft_confirm);
	signal(SIGUSR2, ft_confirm);
	while (1 == 1)
	{
		pause();
	}
	return (0);
}
