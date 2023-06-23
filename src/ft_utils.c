#include "includes/philo.h"

void  ft_ph_status(t_philo *philo, char *status)
{
  if (!philo->data->g_e)
  {
    pthread_mutex_lock(&philo->data->output);
    printf("%lld\t%d\t%s\n", ft_time_elapsed(philo->data), philo->philo_id, status);
    pthread_mutex_unlock(&philo->data->output);
  }
}

void  ft_errors_buster(int err_id)
{
  printf("\033[0;31m");
  if (err_id == 1)
    printf("Input error:\n\tusage: ./philo [nb_of_philos] [time_to_die] [time_to_eat]\
     [time_to_sleep] [nb_of_eats]*\n*optional\n");
  else if (err_id == 2)
      printf("Error: one of th arguments is less or equal to 0\n");
  else if (err_id == 3)
    printf("Error: all arguments must be integers\n");
  exit (0);
}

void ft_args_checker(int ac, char *av[])
{
  int i;

  i = 1;
  if (ac < 5 || ac > 6)
    ft_errors_buster(1);
  while (av[i])
  {
    if(ft_atoi(av[i]) > INT_MAX || ft_atoi(av[i]) < INT_MIN)
      ft_errors_buster(3);
    if (ft_atoi(av[i]) <= 0)
      ft_errors_buster(2);
    i++;
  }
}

void  ft_data_filler(t_data *data, char *av[])
{
  int i;

  i = 0;
  data->philos_nb = ft_atoi(av[1]);
  data->t_to_die = atoi(av[2]);
  data->t_to_eat = ft_atoi(av[3]);
  data->t_to_sleep = ft_atoi(av[4]);
  data->initial_t = ft_initial_t();
  if (av[5])
    data->m_meals = ft_atoi(av[5]);
  else
    data->m_meals = 0;
  data->g_e = 0; 
  data->philo = (t_philo *) malloc(sizeof (t_philo) * data->philos_nb);
  data->fork = (pthread_mutex_t *) malloc(sizeof (pthread_mutex_t) * data->philos_nb);
  pthread_mutex_init(&data->checker, NULL);
  pthread_mutex_init(&data->output, NULL);
  while (data->philos_nb > i)
    pthread_mutex_init(&data->fork[i++], NULL);
  ft_philo_filler(data);
  data->initial_t = ft_initial_t();
}

void  ft_philo_filler(t_data *data)
{
  int i;

  i = 0;
  while (data->philos_nb > i)
  {
    data->philo[i].philo_id = i + 1;
    data->philo[i].eaten = 0;
    data->philo[i].last_meal = 0;
    data->philo[i].left_fork = i;
    data->philo[i].right_fork = (i + 1) % data->philos_nb;
    data->philo[i].data = data;
    i++;
  }
}
