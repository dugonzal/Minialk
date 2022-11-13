/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 01:32:09 by dugonzal          #+#    #+#             */
/*   Updated: 2022/10/31 19:31:20 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	send_bit(int pid, char *argv)
{
	int	i;
	int	bit;

	i = 0;
	while (i < ft_strlen(argv))
	{
		bit = 0;
		while (bit < 8)
		{
			if ((argv[i] >> bit) & 1)
				(kill(pid, SIGUSR2));
			else
				(kill(pid, SIGUSR1));
			usleep (1000);
			bit++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		error("Error: Wrong number of arguments\n");
	send_bit(ft_atoi(argv[1]), argv[2]);
	exit (EXIT_SUCCESS);
}
