#include "includes/philo.h"

void  *ft_only_one(void *philo)
{
  t_philo *p;

  p = (t_philo *)philo;
  pthread_mutex_lock(&p->data->fork[p->left_fork]);
  ft_ph_status(p, "has taken a fork 🥄");
  p->last_meal = ft_time_elapsed(p->data);
  ft_sleeping_time(p, p->data->t_to_die);
  ft_ph_status(p, "\033[0;31mdied 💀\033[0m");
  p->data->g_e = 1;
  return (NULL);
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
    {
      pthread_create(&data->philo[i].tid, NULL, &philo_routine\
      , (void *) &data->philo[i]);
      i++;
    }
    while (!data->g_e)
      ft_referee(data);
  }
}

void  ft_referee(t_data *data)
{
  int i;
  int j;

  i = 0;
  j = 0;
  while (!data->g_e)
  {
    ft_death_check(&data->philo[i]);
    if (data->m_meals)
    {
      while (data->philos_nb > j)
      {
        if (data->m_meals > data->philo[j].eaten)
          break;
        j++;
      }
      if (data->philos_nb == j)
        data->g_e = 1;
    }
    usleep(5000);
    if (i == (data->philos_nb - 1)) //checking from 0 again
      i = -1;
    i++;
  }
}

void  ft_death_check(t_philo *philo)
{
  pthread_mutex_lock(&philo->data->checker);
  if ((ft_time_elapsed(philo->data) - philo->last_meal) >= philo->data->t_to_die)
  {
    ft_ph_status(philo, "\033[0;31mdied 💀\033[0m");
    philo->data->g_e = 1;
  }
  pthread_mutex_unlock(&philo->data->checker);
}

void *philo_routine(void *p)
{
  t_philo *philo;
  t_data *data;

  philo = (t_philo *)p;
  data = philo->data;
  if (philo->philo_id % 2)
    usleep(1500);
  while (!data->g_e)
  {
    if (data->m_meals && philo->eaten == data->m_meals)
      break;
    ft_philo_eat(philo);
    ft_philo_sleep(philo);
    ft_philo_think(philo);
  }
  return (NULL);
}

