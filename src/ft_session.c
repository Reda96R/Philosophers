#include "includes/philo.h"
#include <pthread.h>

void  ft_only_one(void *philo)
{
  t_philo *p;

  p = (t_philo *)philo;
  pthread_mutex_lock(&p->data->fork[p->left_fork]);
  printf("");
}

void  ft_session_starter(t_data *data)
{
  int i;

  i = 0;
  if (data->philos_nb == 1)
    ft_only_one(data->philo);
  else
  {
    while (data->philos_nb > i)
      pthread_create(&data->philo[i].tid, NULL, &philo_routine\
      (void *) &data->philo[i++]);
  }
}

void *philo_routine(void *p)
{
  t_philo *philo;
  t_data *data;

  philo = (t_philo *)p;
  data = philo->data;
  while (!data->g_e)
  {
    if (data->meals && philo->eaten == data->meals)
      break;
    ft_eat(philo);
    ft_sleep(philo);
    ft_think(philo);
  }
  return (NULL);
}

