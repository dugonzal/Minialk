/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dugonzal <dugonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 01:32:09 by dugonzal          #+#    #+#             */
/*   Updated: 2023/10/16 11:19:22 by Dugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void send(char av, int bit, int pid) {
	if ((av >> bit) & 1)
		(kill(pid, SIGUSR2));
	else
		(kill(pid, SIGUSR1));
	usleep (1000);
}

void	send_bit(int pid, char *av)
{
	int	i;
	int	bit;
	int size = ft_strlen(av);
	
	i = -1;
	while (++i < size)
		for (bit = 0; bit < 8; bit++)
			send(av[i], bit, pid);
}

int isal(char *av) {
  for (int i = 0; av[i]; i++)
	  if (av[i] < 48 || av[i] > 57)
		return (1);
  return (0);
}

int	main(int ac, char **av)
{
	if (ac != 3 )
		error("Error: Wrong number of arguments\n");
	int pid = ft_atoi(av[1]);
	if  (isal(av[1]) == 1)
		error("Error: noT is ->[number]<- arguments\n");
	send_bit(pid , av[2]);
	exit (EXIT_SUCCESS);
}
