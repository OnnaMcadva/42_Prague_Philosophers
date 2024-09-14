/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annavm <annavm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 10:55:12 by annavm            #+#    #+#             */
/*   Updated: 2024/09/14 20:10:36 by annavm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	cleanup_and_exit(t_info *tab, pthread_t *id)
{
	int	i;

	i = -1;
	while (++i < tab->num_phi)
		pthread_join(id[i], NULL);
	i = -1;
	while (++i < tab->num_phi)
		pthread_mutex_destroy(&tab->philos[i].fork);
	pthread_mutex_destroy(&tab->display);
	pthread_mutex_destroy(&tab->check);
	free(tab->philos);
	free(id);
}

int	main(int argc, char *argv[])
{
	t_info		tab;
	pthread_t	*id;

	check_arg(argc, argv);
	init_arg(argv, &tab);
	init_philo(&tab);
	id = (pthread_t *)malloc(tab.num_phi * sizeof(pthread_t));
	tab.start_time = crrnt_time();
	init_thread(&tab, &id);
	check_death(&tab);
	cleanup_and_exit(&tab, id);
	return (0);
}
