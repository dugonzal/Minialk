/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dugonzal <dugonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 19:24:29 by ciclo             #+#    #+#             */
/*   Updated: 2023/10/16 11:17:46 by Dugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while (str && *str > 47 && *str < 58)
		result = result * 10 + (*(str++) - 48);
	return (result * sign);
}

void	error(char *str)
{
	ft_printf("%s", str);
	exit (EXIT_FAILURE);
}

int	ft_strlen(char *str)
{
	int	i;

	i = -1;
	while (str[++i]);
	return (i);
}
