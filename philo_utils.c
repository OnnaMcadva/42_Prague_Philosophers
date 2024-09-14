/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annavm <annavm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 11:38:20 by annavm            #+#    #+#             */
/*   Updated: 2024/09/14 20:19:07 by annavm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	status(t_philo *philo, char *msg)
{
	size_t	t;

	t = crrnt_time() - philo->tablo->start_time;
	pthread_mutex_lock(&philo->tablo->display);
	if (!philo->tablo->is_dead && !philo->tablo->full)
	{
		printf("\033[0;94m%ld\033[0m", t);
		printf(" %d ", philo->id);
		printf("%s", msg);
		printf("\n");
	}
	pthread_mutex_unlock(&philo->tablo->display);
}

size_t	crrnt_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

void	waiting(t_info *tab, size_t ms)
{
	size_t	t;

	t = crrnt_time();
	while (!(tab->is_dead))
	{
		if (crrnt_time() - t >= ms)
			break ;
		usleep(100);
	}
}

void	eating(t_philo *philo, t_info *tab)
{
	pthread_mutex_lock(&philo->fork);
	status(philo, FORK);
	if (tab->num_phi == 1)
	{
		waiting(tab, tab->die_time);
		status(philo, DIED);
		pthread_mutex_unlock(&philo->fork);
		tab->is_dead = 1;
		return ;
	}
	pthread_mutex_lock(&philo->next->fork);
	status(philo, FORK);
	pthread_mutex_lock(&tab->check);
	philo->meals++;
	status(philo, EAT);
	philo->last_eat = crrnt_time();
	pthread_mutex_unlock(&tab->check);
	waiting(tab, tab->eat_time);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->next->fork);
}
