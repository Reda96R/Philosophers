#include "includes/philo.h"

void  ft_sleeping_time(t_philo *philo, int t_to_sleep)
{
  long long current;
  long long new_current;

  current = ft_time_elapsed(philo->data);
  while (1)
  {
    new_current = (ft_time_elapsed(philo->data) - current);
    if (new_current >= t_to_sleep)
      break ;
    usleep(1000);
  }
}

long long ft_initial_t(void)
{
  struct timeval  initial_t;

  gettimeofday(&initial_t, NULL);
  return ((initial_t.tv_sec * 1000) + (initial_t.tv_usec / 1000));
}

long long ft_time_elapsed(t_data *data)
{
  struct timeval now;

  gettimeofday(&now, NULL);
  return ((now.tv_sec * 1000) + (now.tv_usec / 1000) - data->initial_t);
}

