/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annavm <annavm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 11:38:05 by annavm            #+#    #+#             */
/*   Updated: 2024/09/14 20:05:34 by annavm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_arg(char *argv[], t_info *tab)
{
	tab->num_phi = ft_atoi_v(argv[1]);
	tab->die_time = ft_atoi_v(argv[2]);
	tab->eat_time = ft_atoi_v(argv[3]);
	tab->sleep_time = ft_atoi_v(argv[4]);
	tab->max_meals = -1;
	if (argv[5])
		tab->max_meals = ft_atoi_v(argv[5]);
	tab->is_dead = 0;
	tab->full = 0;
}

void	init_philo(t_info *tab)
{
	int	i;

	tab->philos = (t_philo *)malloc(tab->num_phi * sizeof(t_philo));
	if (!tab->philos)
		ft_putendl_err(MALLOC);
	i = -1;
	while (++i < tab->num_phi)
	{
		tab->philos[i].id = i + 1;
		tab->philos[i].tablo = tab;
		tab->philos[i].meals = 0;
		if (i + 1 == tab->num_phi)
			tab->philos[i].next = & tab->philos[0];
		else
			tab->philos[i].next = &tab->philos[i + 1];
		if (i == 0)
			tab->philos[i].prev = &tab->philos[tab->num_phi - 1];
		else
			tab->philos[i].prev = &tab->philos[i - 1];
		pthread_mutex_init(&tab->philos[i].fork, NULL);
	}
	pthread_mutex_init(&tab->display, NULL);
	pthread_mutex_init(&tab->check, NULL);
}

static void	*routine(void *arg)
{
	t_philo	*philo;
	t_info	*tab;

	philo = (t_philo *)arg;
	tab = philo->tablo;
	if (philo->id % 2 == 0)
		usleep(1000);
	while (!tab->is_dead && !tab->full)
	{
		eating(philo, philo->tablo);
		status(philo, SLEEP);
		waiting(tab, tab->sleep_time);
		status(philo, THINK);
	}
	return (NULL);
}

void	init_thread(t_info *tab, pthread_t **id)
{
	int	i;

	i = -1;
	while (++i < tab->num_phi)
	{
		if (pthread_create(&id[0][i], NULL, &routine, &tab->philos[i]))
		{
			free(tab->philos);
			free(*id);
			ft_putendl_err(THREAD);
		}
		pthread_mutex_lock(&(tab->check));
		tab->philos[i].last_eat = tab->start_time;
		pthread_mutex_unlock(&tab->check);
	}
}
