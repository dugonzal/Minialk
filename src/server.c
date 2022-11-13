/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 01:32:28 by dugonzal          #+#    #+#             */
/*   Updated: 2022/10/31 19:32:28 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

t_minitalk	g_minitalk;

void	send_msg(int sig)
{
	g_minitalk.size++;
	g_minitalk.msg >>= 1;
	if (sig == SIGUSR2)
		g_minitalk.msg |= 128;
	if (g_minitalk.size == 8)
	{
		ft_printf("%c", g_minitalk.msg);
		g_minitalk.size = 0;
	}
}

void	handler(int sig, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	send_msg(sig);
}

int	main(int argc,__attribute__((unused))char **argv)
{
	struct sigaction	sa;

	if (argc != 1)
		error("Error: Wrong number of arguments\n");
	g_minitalk.msg = 0;
	g_minitalk.size = 0;
	ft_printf("Server PID: -> %d\n", getpid());
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;
	if ((sigaction(SIGUSR1, &sa, NULL)) == -1)
		error("Error: sigaction failed sigusr1");
	if ((sigaction(SIGUSR2, &sa, NULL)) == -1)
		error("Error: sigaction failed sigusr2");
	while (TRUE)
		pause();
	exit (0);
}
