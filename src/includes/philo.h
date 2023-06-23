/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 22:25:11 by rerayyad          #+#    #+#             */
/*   Updated: 2023/06/23 22:29:12 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <limits.h>
# include "mylib.h"

typedef struct s_data	t_data;

typedef struct s_philo
{
	int				philo_id;
	int				eaten;
	long long		last_meal;
	int				right_fork;
	int				left_fork;
	pthread_t		tid;
	t_data			*data;
}	t_philo;

typedef struct s_data
{
	int							philos_nb;
	long long					t_to_eat;
	long long					t_to_sleep;
	long long					t_to_die;
	long long					initial_t;
	int							m_meals;
	int							last_meal;
	int							g_e;
	t_philo						*philo;
	pthread_mutex_t				*fork;
	pthread_mutex_t				output;
	pthread_mutex_t				checker;
}	t_data;

/*::: actions :::*/
void				ft_philo_eat(t_philo *philo);
void				ft_philo_sleep(t_philo *philo);
void				ft_philo_think(t_philo *philo);

/*::: session :::*/
void				ft_session_starter(t_data *data);
void				ft_referee(t_data *data);
void				ft_death_check(t_philo *philo);
void				*philo_routine(void *p);
void				*ft_only_one(void *philo);
void				ft_session_end(t_data *data);

/*::: utils :::*/
void				ft_errors_buster(int err_id);
void				ft_args_checker(int ac, char *av[]);
void				ft_data_filler(t_data *data, char *av[]);
void				ft_philo_filler(t_data *data);
void				ft_ph_status(t_philo *philo, char *status, int n);

/*::: time :::*/
void				ft_sleeping_time(t_philo *philo, int t_to_sleep);
long long			ft_initial_t(void);
long long			ft_time_elapsed(t_data *data);

#endif 
