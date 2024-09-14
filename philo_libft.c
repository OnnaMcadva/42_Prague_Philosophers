/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_libft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annavm <annavm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 11:13:33 by annavm            #+#    #+#             */
/*   Updated: 2024/09/14 19:53:12 by annavm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
		write(fd, s++, 1);
}

int	ft_putendl_err(char *s)
{
	ft_putstr_fd("\033[0;91mError. \033[0m", 2);
	ft_putstr_fd(s, 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}

int	ft_atoi_v(const char *str)
{
	long	result;
	int		i;

	i = 0;
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
		result = (str[i++] - '0') + (result * 10);
	if (i > 12 || result > 2147483647)
		ft_putendl_err(LARGE_ARG);
	return ((int)result);
}
