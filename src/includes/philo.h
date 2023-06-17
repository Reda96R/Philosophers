#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include "mylib.h"

typedef struct s_data t_data;

typedef struct s_philo
{
  int       philo_id;
  pthread_t tid;
  int       eaten;
  long long lastmeal;
  int       right_fork;
  int       left_fork;
  t_data    *data;
} t_philo;

typedef struct s_data
{
  int philos_nb;
  long long t_to_eat;
  long long t_to_sleep;
  long long t_to_die;
  long long initial_t;
  int       meals;
  int       end_meal;
  int       g_e;
  t_philo   *philo;
  pthread_mutex_t *fork;
  pthread_mutex_t cout;
  pthread_mutex_t checker;
} t_data;

/*::: utils :::*/
void  ft_errors_buster(int err_id);
void ft_args_checker(int ac, char *av[]);
void  ft_data_filler(t_data *data, char *av[]);
void  ft_philo_filler(t_data *data);

/*::: time :::*/
long long ft_initial_t(void);
long long ft_elapsed_time(t_data *data);

#endif 
