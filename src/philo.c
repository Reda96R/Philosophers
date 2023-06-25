/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 22:23:43 by rerayyad          #+#    #+#             */
/*   Updated: 2023/06/25 16:40:29 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

int	main(int ac, char *av[])
{
	t_data	*data;

	if (!ft_args_checker(ac, av))
		return (1);
	data = (t_data *)malloc(sizeof (t_data));
	if (!data)
		return (1);
	ft_data_filler(data, av);
	ft_session_starter(data);
	ft_session_end(data);
}
