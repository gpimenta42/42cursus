/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 15:40:47 by gpimenta          #+#    #+#             */
/*   Updated: 2023/04/29 17:05:22 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	case_one(t_philos *philo)
{
	pthread_mutex_lock(&philo->can_die);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->can_die);
	pthread_mutex_lock(philo->left_fork);
	printing(philo, 'f');
}

void	eating(t_philos *philo)
{
	pthread_mutex_unlock(&philo->vars->printing);
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(&philo->can_die);
	printing(philo, 'f');
	printing(philo, 'f');
	printing(philo, 'e');
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->can_die);
	usleep(philo->vars->time_to_eat * 1000);
	pthread_mutex_lock(&philo->vars->printing);
	philo->n_meals += 1;
	pthread_mutex_unlock(&philo->vars->printing);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	*routine(void *philo_void)
{
	t_philos	*philo;

	philo = (t_philos *)philo_void;
	if (philo->vars->n_philos == 1)
	{
		case_one(philo);
		return (NULL);
	}
	pthread_mutex_lock(&philo->vars->printing);
	while (!philo->vars->someone_died
		&& philo->vars->full_philos < philo->vars->n_philos)
	{
		eating(philo);
		printing(philo, 's');
		usleep(philo->vars->time_to_sleep * 1000);
		printing(philo, 't');
		pthread_mutex_lock(&philo->vars->printing);
		usleep(100);
	}
	pthread_mutex_unlock(&philo->vars->printing);
	return (NULL);
}
