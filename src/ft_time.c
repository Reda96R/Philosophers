#include "includes/philo.h"

long long ft_initial_t(void)
{
  struct timeval  initial_t;

  gettimeofday(&initial_t, NULL);
  return ((initial_t.tv_sec * 1000) + (initial_t.tv_usec / 1000));
}

long long ft_elapsed_time(t_data *data)
{
  struct timeval now;

  gettimeofday(&now, NULL);
  return ((initial_t.tv_sec * 1000) + (initial_t.tv_usec / 1000) - data->initial_t);
}

