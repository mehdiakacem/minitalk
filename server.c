/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 12:15:24 by makacem           #+#    #+#             */
/*   Updated: 2022/05/28 18:36:10 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include "printf/ft_printf.h"

int	g_c;

void	handle_sigusr(int sig, siginfo_t *info, void *context)
{
	static int	b;
	static int	old_pid;

	(void) context;
	if (info->si_pid != old_pid)
	{
		old_pid = info->si_pid;
		g_c = 0;
		b = 0;
	}
	if (sig == SIGUSR1)
	{
		g_c = g_c | (1 << b);
		b++;
	}
	if (sig == SIGUSR2)
		b++;
	if (b == 8)
	{
		ft_printf("%c", g_c);
		g_c = 0;
		b = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &handle_sigusr;
	sa.sa_flags = SA_SIGINFO;
	ft_printf("%d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
