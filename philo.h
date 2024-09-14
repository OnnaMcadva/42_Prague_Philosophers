/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annavm <annavm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 10:54:29 by annavm            #+#    #+#             */
/*   Updated: 2024/09/14 20:23:48 by annavm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include "philo_define.h"
# include "philo_struct.h"

// philo_check.c
void	check_arg(int argc, char *argv[]);
void	check_death(t_info *tab);

// philo_init.c
void	init_arg(char *argv[], t_info *tab);
void	init_philo(t_info *tab);
void	init_thread(t_info *tab, pthread_t **id);

// philo_libft.c
int		ft_putendl_err(char *s);
int		ft_atoi_v(const char *str);

// philo_utils.c 
void	status(t_philo *philo, char *msg);
size_t	crrnt_time(void);
void	waiting(t_info *tab, size_t ms);
void	eating(t_philo *philo, t_info *tab);

#endif
