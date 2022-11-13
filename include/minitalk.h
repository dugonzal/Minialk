/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 01:32:44 by dugonzal          #+#    #+#             */
/*   Updated: 2022/10/29 15:20:51 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# define TRUE 42
# include "../ft_printf/include/ft_printf.h"

typedef struct minitalk
{
	int				size;
	unsigned char	msg;
}					t_minitalk;

int		ft_strlen(char *str);
int		ft_atoi(const char *str);
void	error(char *str);

#endif
