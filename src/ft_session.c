/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_session.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 22:21:23 by rerayyad          #+#    #+#             */
/*   Updated: 2023/06/25 16:40:43 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	*ft_only_one(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	pthread_mutex_lock(&p->data->fork[p->left_fork]);
	ft_ph_status(p, "has taken a fork", 0);
	p->last_meal = ft_time_elapsed(p->data);
	ft_sleeping_time(p, p->data->t_to_die);
	ft_ph_status(p, "\033[0;31mdied \033[0m", 0);
	p->data->g_e = 1;
	return (NULL);
}

void	ft_session_starter(t_data *data)
{
	int	i;

	i = 0;
	if (data->philos_nb == 1)
		ft_only_one(data->philo);
	else
	{
		while (data->philos_nb > i)
		{
			pthread_create(&data->philo[i].tid, NULL, &philo_routine \
			, (void *) &data->philo[i]);
			i++;
		}
		while (!data->g_e)
			ft_referee(data);
	}
}

void	*philo_routine(void *p)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)p;
	data = philo->data;
	if (philo->philo_id % 2)
		usleep(20000);
	while (1)
	{
		if (data->m_meals && philo->eaten == data->m_meals)
			break ;
		ft_philo_eat(philo);
		ft_philo_sleep(philo);
		ft_philo_think(philo);
	}
	return (NULL);
}

void	ft_session_end(t_data *data)
{
	int	i;

	i = data->philos_nb;
	while (--i >= 0)
		pthread_detach(data->philo[i].tid);
	while (++i < data->philos_nb)
		pthread_mutex_destroy(&data->fork[i]);
	pthread_mutex_destroy(&data->output);
	pthread_mutex_destroy(&data->checker);
	free(data->fork);
	free(data->philo);
	free(data);
}
