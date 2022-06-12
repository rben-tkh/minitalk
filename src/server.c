/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 10:26:37 by rben-tkh          #+#    #+#             */
/*   Updated: 2022/06/12 20:13:01 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_data	g_data;

static void	treat_char(void)
{
	if (g_data.c == 0)
	{
		write(1, g_data.buf, g_data.buflen);
		write(1, "\n", 1);
		free(g_data.buf);
		g_data.buf = 0;
		g_data.buflen = 1;
	}
	else
	{
		g_data.buf = ft_strjoin(g_data.buf, g_data.c, g_data.buflen);
		g_data.buflen++;
	}
	g_data.c = 0;
}

static void	treat_zero(int unused, siginfo_t *data, void *unused2)
{
	(void)unused;
	(void)unused2;
	if (g_data.count < 8)
	{
		g_data.c = (g_data.c << 1);
		if (g_data.count == 7)
			treat_char();
		g_data.count++;
	}
	else
	{
		g_data.count = 0;
		g_data.c = (g_data.c << 1);
		g_data.count++;
	}
	kill(data->si_pid, SIGUSR1);
}

static void	treat_one(int unused, siginfo_t *data, void *unused2)
{
	(void)unused;
	(void)unused2;
	if (g_data.count < 8)
	{
		g_data.c = (g_data.c << 1) + 1;
		if (g_data.count == 7)
			treat_char();
		g_data.count++;
	}
	else
	{
		g_data.count = 0;
		g_data.c = (g_data.c << 1) + 1;
		g_data.count++;
	}
	kill(data->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa1;
	struct sigaction	sa2;

	g_data.count = 0;
	g_data.buflen = 1;
	write(1, "PID : ", 6);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	sa1.sa_sigaction = treat_zero;
	sa2.sa_sigaction = treat_one;
	sa1.sa_flags = SA_SIGINFO;
	sa2.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa1, NULL);
	sigaction(SIGUSR2, &sa2, NULL);
	while (1)
		pause();
	return (0);
}
