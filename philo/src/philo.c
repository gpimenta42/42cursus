/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 18:05:29 by gpimenta          #+#    #+#             */
/*   Updated: 2023/04/25 19:29:56 by gpimenta         ###   ########.fr       */
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

int	error(int n)
{
	if (n == 1)
		printf("invalid number of arguments\n");
	else if (n == 2)
		printf("some invalid argument\n");
	exit (1);
	return (1);
}

int	valid_args(char **av)
{
	int	i;

	i = 0;
	while (av[++i])
	{
		if (!ft_isdigit_or(av[i]))
			return (0);
		if (!is_positive(av[i]))
			return (0);
		if (ft_atoi(av[i]) <= 0)
			return (0);
	}
	return (1);
}

t_vars	init_args(int ac, char **av)
{
	int		i;
	t_vars	vars;

	i = 0;
	vars.n_philos = ft_atoi(av[++i]);
	vars.time_to_die = ft_atoi(av[++i]);
	vars.time_to_eat = ft_atoi(av[++i]);
	vars.time_to_sleep = ft_atoi(av[++i]);
	if (ac == 6)
		vars.target_meals = ft_atoi(av[++i]);
	else
		vars.target_meals = 2147483647;
	vars.full_philos = 0;
	vars.someone_died = 0;
	return (vars);
}

/*int gettimeofday(struct timeval *__restrict__ __tv,
					void *__restrict__ __tz)

ms = s * 1000;
ms = us / 1000;
*/

int	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

/*
arr of philos
arr of forks
*/

/*
int pthread_mutex_init(pthread_mutex_t *__mutex,
				const pthread_mutexattr_t *__mutexattr)
*/

void	mutex_init(t_vars *vars, t_philos *philos)
{
	int	i;

	pthread_mutex_init(&vars->printing, NULL);
	i = -1;
	while (++i < vars->n_philos)
		pthread_mutex_init(&philos[i].can_die, NULL);
}

/*
left fork and right fork has to be pointer
to remember the address of fork[i];
*/

t_philos	*philos_init(t_vars *vars, pthread_mutex_t *forks)
{
	t_philos			*philos;
	int					i;

	philos = malloc(sizeof(t_philos) * vars->n_philos);
	if (!philos)
		return (NULL);
	mutex_init(vars, philos);
	i = -1;
	while (++i < vars->n_philos)
	{
		philos[i].id = i + 1;
		philos[i].left_fork = &forks[i];
		philos[i].right_fork = &forks[(i + 1) % vars->n_philos];
		philos[i].n_meals = 0;
		philos[i].vars = vars;
		philos[i].flag = 0;
	}
	return (philos);
}

/*
int pthread_mutex_lock(pthread_mutex_t *__mutex)
*/

void	print_dead(t_philos *philo, int i)
{
	char		*dead;
	size_t		time;

	dead = "died! 🪦\n";
	if (philo->vars->full_philos == philo->vars->n_philos)
		return ;
	time = get_time() - philo->start_time;
	pthread_mutex_lock(&philo->vars->printing);
	printf("%ld ms %d %s", time, philo[i].id, dead);
	pthread_mutex_unlock(&philo->vars->printing);
}

void	printing(t_philos *philo, char c)
{
	char		*fork;
	char		*eating;
	char		*sleeping;
	char		*thinking;
	size_t		time;

	fork = "has taken a fork 🍴";
	eating = "is eating 🍝";
	sleeping = "is sleeping 😴";
	thinking = "is thinking 🤔";
	// if (philo->vars->someone_died
	// 	|| philo->vars->full_philos == philo->vars->n_philos)
	// 	return ;
	time = get_time() - philo->start_time;
	pthread_mutex_lock(&philo->vars->printing);
	if (philo->vars->someone_died
		|| philo->vars->full_philos == philo->vars->n_philos)
	{
		pthread_mutex_unlock(&philo->vars->printing);
		return ;
	}
	if (c == 'f')
		printf("%ld ms %d %s\n", time, philo->id, fork);
	else if (c == 'e')
		printf("%ld ms %d %s\n", time, philo->id, eating);
	else if (c == 's')
		printf("%ld ms %d %s\n", time, philo->id, sleeping);
	else if (c == 't')
		printf("%ld ms %d %s\n", time, philo->id, thinking);
	pthread_mutex_unlock(&philo->vars->printing);
}

void	*routine(void *philo_void)
{
	t_philos	*philo;

	philo = (t_philos *)philo_void;
	if (philo->vars->n_philos == 1)
	{
		philo->last_meal = get_time();
		pthread_mutex_lock(philo->left_fork);
		printing(philo, 'f');
		return (NULL);
	}
	while (!philo->vars->someone_died
		&& philo->vars->full_philos < philo->vars->n_philos)
	{
		pthread_mutex_lock(philo->left_fork);
		pthread_mutex_lock(philo->right_fork);
		pthread_mutex_lock(&philo->can_die);
		printing(philo, 'f');
		printing(philo, 'f');
		printing(philo, 'e');
		usleep(philo->vars->time_to_eat * 1000);
		pthread_mutex_unlock(&philo->can_die);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		philo->last_meal = get_time();
		philo->n_meals += 1;
		printing(philo, 's');
		usleep(philo->vars->time_to_sleep * 1000);
		printing(philo, 't');
	}
	return (NULL);
}

/*
int pthread_create(pthread_t *__restrict__ __newthread,
			const pthread_attr_t *__restrict__ __attr,
			void *(*__start_routine)(void *),
			void *__restrict__ __arg)

int pthread_join(pthread_t __th, void **__thread_return)
Make calling thread wait for termination of the thread TH.
*/

/*
can only dies if it can locks can_die
if its locked already because he's eating then cannot die
*/

void	*supervisor(void *philos_void)
{
	t_philos	*philos;
	int			i;
	size_t		time;

	philos = (t_philos *)philos_void;
	while (philos->vars->full_philos < philos->vars->n_philos)
	{
		i = -1;
		while (++i < philos->vars->n_philos)
		{
			pthread_mutex_lock(&philos[i].can_die);
			if (get_time() - philos[i].last_meal >= philos->vars->time_to_die)
			{
				philos->vars->someone_died = 1;
				print_dead(philos, i);
				pthread_mutex_unlock(&philos[i].can_die);
				return (NULL);
			}
			pthread_mutex_unlock(&philos[i].can_die);
			if (philos[i].n_meals >= philos->vars->target_meals
				&& !philos[i].flag)
			{
				philos->vars->full_philos += 1;
				philos[i].flag = 1;
			}
		}
	}
	time = get_time() - philos->start_time;
	pthread_mutex_lock(&philos->vars->printing);
	printf("%ld ms all philos ate %d meals 🎉\n",
		time, philos->vars->target_meals);
	pthread_mutex_unlock(&philos->vars->printing);
	return (NULL);
}

void	supervisor_creator(t_philos *philos)
{
	pthread_t	th_supervisor;

	pthread_create(&th_supervisor, NULL, &supervisor, (void *)philos);
	pthread_join(th_supervisor, NULL);
}

void	routine_creator(t_philos *philos, t_vars vars)
{
	int	i;

	i = -1;
	while (++i < vars.n_philos)
	{
		philos[i].start_time = get_time();
		pthread_create(&philos[i].thread, NULL, &routine, (void *)&philos[i]);
		usleep(100);
	}
	supervisor_creator(philos);
	i = -1;
	while (++i < vars.n_philos)
		pthread_join(philos[i].thread, NULL);
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

pthread_mutex_t	*forks_init(t_vars vars)
{
	pthread_mutex_t		*forks;
	int					i;

	forks = malloc(sizeof(pthread_mutex_t) * vars.n_philos);
	if (!forks)
		return (NULL);
	i = -1;
	while (++i < vars.n_philos)
		pthread_mutex_init(&forks[i], NULL);
	return (forks);
}

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
}
