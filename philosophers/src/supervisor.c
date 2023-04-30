/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 15:37:21 by gpimenta          #+#    #+#             */
/*   Updated: 2023/04/29 16:53:34 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*dying_philo(t_philos *philos, int i)
{
	pthread_mutex_lock(&philos->vars->printing);
	philos->vars->someone_died = 1;
	pthread_mutex_unlock(&philos->vars->printing);
	print_dead(philos, i);
	pthread_mutex_unlock(&philos[i].can_die);
	return (NULL);
}

void	all_full(t_philos *philos)
{
	size_t		time;

	time = get_time() - philos->start_time;
	pthread_mutex_lock(&philos->vars->printing);
	printf("%ld ms all philos ate %d meals 🎉\n",
		time, philos->vars->target_meals);
	pthread_mutex_unlock(&philos->vars->printing);
}

void	one_more_full(t_philos *philos, int i)
{
	philos->vars->full_philos += 1;
	philos[i].flag = 1;
}

void	*supervisor(void *philos_void)
{
	t_philos	*philos;
	int			i;

	philos = (t_philos *)philos_void;
	while (philos->vars->full_philos < philos->vars->n_philos)
	{
		i = -1;
		while (++i < philos->vars->n_philos)
		{
			pthread_mutex_lock(&philos[i].can_die);
			if (get_time() - philos[i].last_meal >= philos->vars->time_to_die)
				return (dying_philo(philos, i));
			pthread_mutex_unlock(&philos[i].can_die);
			pthread_mutex_lock(&philos->vars->printing);
			if (philos[i].n_meals == philos->vars->target_meals
				&& !philos[i].flag)
				one_more_full(philos, i);
			pthread_mutex_unlock(&philos->vars->printing);
		}
	}
	all_full(philos);
	return (NULL);
}

void	supervisor_creator(t_philos *philos)
{
	pthread_t	th_supervisor;

	if (pthread_create(&th_supervisor, NULL, &supervisor, (void *)philos))
		return ;
	if (pthread_join(th_supervisor, NULL))
		return ;
}
