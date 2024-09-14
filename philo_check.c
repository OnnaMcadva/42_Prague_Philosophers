/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annavm <annavm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 11:37:32 by annavm            #+#    #+#             */
/*   Updated: 2024/09/14 20:10:14 by annavm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_arg(int argc, char *argv[])
{
	int	i;
	int	j;

	if (argc < 5 || argc > 6)
		ft_putendl_err(ARGS);
	j = 0;
	while (argv[0][j])
		j++;
	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				ft_putendl_err(CHAR_ARGS);
			j++;
		}
		i++;
	}
}

void	check_death(t_info *tab)
{
	int	i;

	while (!tab->full)
	{
		i = -1;
		while (!tab->is_dead && ++i < tab->num_phi)
		{
			pthread_mutex_lock(&tab->check);
			if (crrnt_time() - tab->philos[i].last_eat > (size_t)tab->die_time)
			{
				status(&tab->philos[i], DIED);
				tab->is_dead = 1;
			}
			pthread_mutex_unlock(&tab->check);
			usleep(100);
		}
		if (tab->is_dead)
			break ;
		i = 0;
		while (tab->max_meals != -1 && i < tab->num_phi
			&& tab->philos[i].meals >= tab->max_meals)
			i++;
		if (i == tab->num_phi)
			tab->full = 1;
	}
}
