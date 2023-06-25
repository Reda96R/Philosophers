/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 22:18:24 by rerayyad          #+#    #+#             */
/*   Updated: 2023/06/25 15:17:07 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	ft_philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->fork[philo->left_fork]);
	ft_ph_status(philo, "has taken a fork ", 0);
	pthread_mutex_lock(&philo->data->fork[philo->right_fork]);
	ft_ph_status(philo, "has taken a fork ", 0);
	ft_ph_status(philo, "\033[0;32mis eating \033[0m", 0);
	pthread_mutex_lock(&philo->data->time);
	philo->last_meal = ft_time_elapsed(philo->data);
	pthread_mutex_unlock(&philo->data->time);
	ft_sleeping_time(philo, philo->data->t_to_eat);
	pthread_mutex_lock(&philo->data->eat);
	philo->eaten++;
	pthread_mutex_unlock(&philo->data->eat);
	pthread_mutex_unlock(&philo->data->fork[philo->left_fork]);
	pthread_mutex_unlock(&philo->data->fork[philo->right_fork]);
}

void	ft_philo_sleep(t_philo *philo)
{
	ft_ph_status(philo, "is sleeping ", 0);
	ft_sleeping_time(philo, philo->data->t_to_sleep);
}

void	ft_philo_think(t_philo *philo)
{
	ft_ph_status(philo, "is thinking ", 0);
}
