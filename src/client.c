/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 10:26:44 by rben-tkh          #+#    #+#             */
/*   Updated: 2022/06/12 20:49:44 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_tor;

void	treat_ping(int unused)
{
	(void)unused;
	g_tor = 1;
}

static int	ft_convert(int pid, char c)
{
	int		i;
	char	tmp;

	i = 8;
	tmp = c;
	while (i--)
	{
		g_tor = 0;
		if (ft_pow(2, i) > tmp)
			kill(pid, SIGUSR1);
		else
		{
			tmp = tmp - ft_pow(2, i);
			kill(pid, SIGUSR2);
		}
		while (!g_tor)
			pause();
	}
	return (0);
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	pid = ft_atoi(av[1]);
	if (ac != 3 || !av[1] || !av[2] || pid < 1 || pid > 4194304)
		write(2, "Invalid arguments\n", 18);
	else
	{
		signal(SIGUSR1, treat_ping);
		i = 0;
		while (av[2][i])
		{
			ft_convert(pid, av[2][i]);
			i++;
		}
		ft_convert(pid, 0);
	}
	return (0);
}
