#include "includes/philo.h"
#include <pthread.h>

void  ft_philo_eat(t_philo *philo)
{
  if (!philo->data->g_e)
  {
    pthread_mutex_lock(&philo->data->fork[philo->left_fork]);
    printf("first fork\n");
    pthread_mutex_lock(&philo->data->fork[philo->right_fork]);
    printf("second fork\n");
    printf("eating\n");
    philo->lastmeal = ;
    philo->eaten++;
    ft_sleep(philo, philo->data->t_to_eat);
    pthread_mutex_unlock(&philo->data->fork[philo->left_fork]);
    pthread_mutex_unlock(&philo->data->fork[philo->right_fork]);
  }
}

void  ft_philo_sleep(t_philo *philo)
{
  if (!philo->data->g_e)
  {
    printf("sleeping\n");
    ft_sleep(philo, philo->data->t_to_sleep);
  }
}

void  ft_philo_think(t_philo *philo)
{
  if (!philo->data->g_e)
    printf("thinking\n");
}
