/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annavm <annavm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 10:54:21 by annavm            #+#    #+#             */
/*   Updated: 2024/09/14 10:54:22 by annavm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_STRUCT_H
# define PHILO_STRUCT_H

typedef struct s_philo
{
	int				id;
	int				meals;
	size_t			last_eat;
	pthread_mutex_t	fork;
	struct s_philo	*next;
	struct s_philo	*prev;
	struct s_info	*tablo;
}	t_philo;

typedef struct s_info
{
	int				num_phi;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				max_meals;
	size_t			start_time;
	t_philo			*philos;
	pthread_mutex_t	display;
	pthread_mutex_t	check;
	int				is_dead;
	int				full;
}				t_info;

#endif
