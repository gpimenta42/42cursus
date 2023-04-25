/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 18:03:49 by gpimenta          #+#    #+#             */
/*   Updated: 2023/04/25 19:13:35 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h> /*pthread*/
# include <stdio.h> /*printf*/
# include <unistd.h>
# include <stdlib.h> /*malloc*/
# include <sys/time.h> /*gettimeofday*/

/*
Test: [4 310 200 100] | a philo should die
	as vezes ninguem morre

Test: [4 410 200 200 10] | no one should die, simulation should stop after 10 eats
	ko
	as vezes - alguem morre

Test: [100 800 200 200] | no one should die
	ko
*/

typedef struct s_vars
{
	int				n_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				target_meals;
	int				full_philos;
	int				someone_died;
	pthread_mutex_t	printing;
}	t_vars;

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	int				n_meals;
	int				flag;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	can_die;
	int				start_time;
	int				last_meal;
	t_vars			*vars;
}	t_philos;

int		ft_isdigit_or(char *str);
int		is_positive(char *str);
int		ft_atoi(const char *str);

#endif
