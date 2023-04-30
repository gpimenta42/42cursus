/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 18:05:29 by gpimenta          #+#    #+#             */
/*   Updated: 2023/04/29 15:42:42 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*
One or more philosophers sit at a round table.
There is a large bowl of spaghetti in the middle of the table.

The philosophers alternatively eat, think, or sleep.

There are also forks on the table.
There are as many forks as philosophers

Because serving and eating spaghetti
with only one fork is very inconvenient,
a philosopher takes their right and their left forks to eat,
one in each hand.

When a philosopher has finished eating,
they put their forks back on the table and
start sleeping. Once awake, they start thinking again.

The simulation stops when a philosopher dies of starvation.
Every philosopher needs to eat and should never starve.

Global variables are forbidden!

Your(s) program(s) should take the following arguments:
	number_of_philosophers
	time_to_die time_to_eat  (in milliseconds)
	time_to_sleep (in milliseconds)
	[number_of_times_each_philosopher_must_eat]

Each philosopher has a number ranging
from 1 to number_of_philosophers.

Philosopher number 1 sits next to
philosopher number number_of_philosophers.

Any state change of a philosopher must be formatted as follows:
◦ timestamp_in_ms X has taken a fork
◦ timestamp_in_ms X is eating
◦ timestamp_in_ms X is sleeping
◦ timestamp_in_ms X is thinking
◦ timestamp_in_ms X died
Replace timestamp_in_ms with the current timestamp in milliseconds
and X with the philosopher number.

A message announcing a philosopher died
should be displayed no more than 10 ms
after the actual death of the philosopher.

Each philosopher should be a thread.

If there is only one philosopher,
there should be only one fork on the table.

To prevent philosophers from duplicating forks,
you should protect the forks state
with a mutex for each of them.
*/

/*
int pthread_mutex_init(pthread_mutex_t *__mutex,
				const pthread_mutexattr_t *__mutexattr)
*/

void	ft_free(pthread_mutex_t *forks, t_philos *philos)
{
	if (forks)
		free(forks);
	if (philos)
		free(philos);
}

void	mutex_destroy(t_vars *vars, t_philos *philos, pthread_mutex_t *forks)
{
	int	i;

	pthread_mutex_destroy(&vars->printing);
	i = -1;
	while (++i < vars->full_philos)
	{
		pthread_mutex_destroy(&philos[i].can_die);
		pthread_mutex_destroy(&forks[i]);
	}
}

/*
int pthread_create(pthread_t *__restrict__ __newthread,
			const pthread_attr_t *__restrict__ __attr,
			void *(*__start_routine)(void *),
			void *__restrict__ __arg)

int pthread_join(pthread_t __th, void **__thread_return)
Make calling thread wait for termination of the thread TH.
*/

void	routine_creator(t_philos *philos, t_vars vars)
{
	int	i;

	i = -1;
	while (++i < vars.n_philos)
	{
		philos[i].start_time = get_time();
		if (pthread_create(&philos[i].thread, NULL, &routine,
				(void *)&philos[i]) != 0)
			return ;
		usleep(100);
	}
	supervisor_creator(philos);
	i = -1;
	while (++i < vars.n_philos)
		if (pthread_join(philos[i].thread, NULL))
			return ;
}

/*
arr of philos
arr of forks
*/

int	main(int ac, char **av)
{
	t_philos			*philos;
	t_vars				vars;
	pthread_mutex_t		*forks;

	if (ac < 5 || ac > 6)
		return (error(1));
	if (!valid_args(av))
		return (error(2));
	vars = init_args(ac, av);
	forks = forks_init(vars);
	philos = philos_init(&vars, forks);
	routine_creator(philos, vars);
	mutex_destroy(&vars, philos, forks);
	ft_free(forks, philos);
}
