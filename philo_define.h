/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_define.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annavm <annavm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 10:54:11 by annavm            #+#    #+#             */
/*   Updated: 2024/09/14 20:07:21 by annavm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_DEFINE_H
# define PHILO_DEFINE_H

//errors
# define ARGS "\033[38;5;051mPlease indicate:\033[0m\n\
\033[38;5;206mNumOfPhilos TimeToDie TimeToEat TimeToSleep [NumOfMeals]\033[0m"
# define CHAR_ARGS "\033[38;5;219mAn unauthorized character was found\033[0m"
# define LARGE_ARG "\033[38;5;206mCan not be more than 2147483647\033[0m"
# define MALLOC "\033[0;95mMemory allocation failure\033[0m"
# define THREAD "\033[0;95mFailed to create thread\033[0m"

//messages
# define FORK "\033[38;5;118mhas taken a fork\033[0m"
# define EAT "\033[38;5;227mis eating\033[0m"
# define SLEEP "\033[38;5;206mis sleeping\033[0m"
# define THINK "\033[38;5;051mis thinking\033[0m"
# define DIED "\033[38;5;219mdied\n\n ⬤ ▅▇█▇▆▅▄▄▄▇ \n\033[0m"

#endif
