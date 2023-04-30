/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 15:36:35 by gpimenta          #+#    #+#             */
/*   Updated: 2023/04/29 15:48:35 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_dead(t_philos *philo, int i)
{
	char		*dead;
	size_t		time;

	dead = "died! 🪦\n";
	if (philo->vars->full_philos == philo->vars->n_philos)
		return ;
	pthread_mutex_lock(&philo->vars->printing);
	time = get_time() - philo->start_time;
	printf("%ld ms %d %s", time, philo[i].id, dead);
	pthread_mutex_unlock(&philo->vars->printing);
}

#define FORK "has taken a fork 🍴"
#define EAT "is eating 🍝"
#define SLEEP "is sleeping 😴"
#define THINK "is thinking 🤔"

void	printing(t_philos *philo, char c)
{
	size_t		time;
	const char	*event[4] = {FORK, EAT, SLEEP, THINK};

	pthread_mutex_lock(&philo->vars->printing);
	if (philo->vars->someone_died
		|| philo->vars->full_philos == philo->vars->n_philos)
	{
		pthread_mutex_unlock(&philo->vars->printing);
		return ;
	}
	time = get_time() - philo->start_time;
	if (c == 'f')
		printf("%ld ms %d %s\n", time, philo->id, event[0]);
	else if (c == 'e')
		printf("%ld ms %d %s\n", time, philo->id, event[1]);
	else if (c == 's')
		printf("%ld ms %d %s\n", time, philo->id, event[2]);
	else if (c == 't')
		printf("%ld ms %d %s\n", time, philo->id, event[3]);
	pthread_mutex_unlock(&philo->vars->printing);
}
