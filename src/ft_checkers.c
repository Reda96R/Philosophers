/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 16:38:19 by rerayyad          #+#    #+#             */
/*   Updated: 2023/06/25 16:40:20 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	ft_referee(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (!data->g_e)
	{
		ft_death_check(&data->philo[i]);
		ft_meals_tracker(data);
		if (i == (data->philos_nb - 1))
			i = -1;
		i++;
	}
}

void	ft_death_check(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->checker);
	pthread_mutex_lock(&philo->data->time);
	if ((ft_time_elapsed(philo->data) - philo->last_meal) \
	>= philo->data->t_to_die)
	{
		pthread_mutex_unlock(&philo->data->time);
		ft_ph_status(philo, "\033[0;31mdied \033[0m", 1);
		philo->data->g_e = 1;
	}
	pthread_mutex_unlock(&philo->data->time);
	pthread_mutex_unlock(&philo->data->checker);
}

void	ft_meals_tracker(t_data *data)
{
	int	j;

	j = 0;
	if (data->m_meals)
	{
		while (data->philos_nb > j)
		{
			pthread_mutex_lock(&data->eat);
			if (data->m_meals > data->philo[j].eaten)
			{
				pthread_mutex_unlock(&data->eat);
				break ;
			}
			pthread_mutex_unlock(&data->eat);
			j++;
		}
		if (data->philos_nb == j)
				data->g_e = 1;
	}
}
