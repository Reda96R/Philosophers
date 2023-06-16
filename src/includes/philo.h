#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>

typedef struct s_data
{
  int philos;
  long long t_to_eat;
  long long t_to_sleep;
  long long t_to_die;
  int       meals;
  int       end_meal;
} t_data;

/*::: utils :::*/
void ft_args_checker(int ac, char *av[]);
void  ft_errors_buster(int err_id);

#endif 
