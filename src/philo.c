/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 22:23:43 by rerayyad          #+#    #+#             */
/*   Updated: 2023/06/23 22:23:57 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

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

int	main(int ac, char *av[])
{
	t_data	*data;

	ft_args_checker(ac, av);
	data = (t_data *)malloc(sizeof (t_data));
	if (!data)
		return (1);
	ft_data_filler(data, av);
	ft_session_starter(data);
	ft_session_end(data);
}
