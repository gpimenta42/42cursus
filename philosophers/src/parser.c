/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 15:35:23 by gpimenta          #+#    #+#             */
/*   Updated: 2023/04/29 16:53:46 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	mutex_init(t_vars *vars, t_philos *philos)
{
	int	i;

	if (pthread_mutex_init(&vars->printing, NULL))
		return ;
	i = -1;
	while (++i < vars->n_philos)
		if (pthread_mutex_init(&philos[i].can_die, NULL))
			return ;
}

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
		philos[i].last_meal = get_time();
		philos[i].flag = 0;
	}
	return (philos);
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
	{
		if (pthread_mutex_init(&forks[i], NULL))
			return (NULL);
	}
	return (forks);
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
		vars.target_meals = -1;
	vars.full_philos = 0;
	vars.someone_died = 0;
	return (vars);
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
