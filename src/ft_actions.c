#include "includes/philo.h"

void  ft_philo_eat(t_philo *philo)
{
  if (!philo->data->g_e)
  {
    pthread_mutex_lock(&philo->data->fork[philo->left_fork]);
    ft_ph_status(philo, "has taken a fork 🥄");
    pthread_mutex_lock(&philo->data->fork[philo->right_fork]);
    ft_ph_status(philo, "has taken a fork 🥄");
    ft_ph_status(philo, "\033[32mis eating 🥣\033[0m");
    philo->last_meal = ft_time_elapsed(philo->data);
    philo->eaten++;
    ft_sleeping_time(philo, philo->data->t_to_eat);
    pthread_mutex_unlock(&philo->data->fork[philo->left_fork]);
    pthread_mutex_unlock(&philo->data->fork[philo->right_fork]);
  }
}

void  ft_philo_sleep(t_philo *philo)
{
  if (!philo->data->g_e)
  {
    ft_ph_status(philo, "is sleeping 💤");
    ft_sleeping_time(philo, philo->data->t_to_sleep);
  }
}

void  ft_philo_think(t_philo *philo)
{
  if (!philo->data->g_e)
    ft_ph_status(philo, "is thinking 🧠");
}
