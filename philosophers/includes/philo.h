/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 18:03:49 by gpimenta          #+#    #+#             */
/*   Updated: 2023/04/29 16:41:01 by gpimenta         ###   ########.fr       */
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
5 600 150 150

100 800 200 200

5 800 200 200 10
| grep "1 is eating" | wc -l


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

/*
left fork and right fork has to be pointer
to remember the address of fork[i];
*/

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

int				valid_args(char **av);
t_vars			init_args(int ac, char **av);
pthread_mutex_t	*forks_init(t_vars vars);
t_philos		*philos_init(t_vars *vars, pthread_mutex_t *forks);
void			mutex_init(t_vars *vars, t_philos *philos);
int				get_time(void);
int				error(int n);
int				ft_isdigit_or(char *str);
int				is_positive(char *str);
int				ft_atoi(const char *str);

void			routine_creator(t_philos *philos, t_vars vars);
void			*routine(void *philo_void);
void			printing(t_philos *philo, char c);
void			eating(t_philos *philo);
void			case_one(t_philos *philo);
void			supervisor_creator(t_philos *philos);
void			*supervisor(void *philos_void);
void			one_more_full(t_philos *philos, int i);
void			all_full(t_philos *philos);
void			*dying_philo(t_philos *philos, int i);
void			print_dead(t_philos *philo, int i);

void			mutex_destroy(t_vars *vars, t_philos *philos,
					pthread_mutex_t *forks);
void			ft_free(pthread_mutex_t *forks, t_philos *philos);

#endif
