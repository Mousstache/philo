/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motroian <motroian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:30:17 by motroian          #+#    #+#             */
/*   Updated: 2023/04/06 17:28:15 by motroian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


long int	get_time(void *args)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	print_msg(t_philo *philo, char *msg)
{
	pthread_mutex_lock(philo->data->print);
	printf("%d %d %s", get_time(), philo->name, msg);
	pthread_mutex_unlock(philo->data->print);
}

void	check_death(void *args)
{
	return (args);
}

void	*routine(void *args)
{
	t_philo	philo;

	philo = (t_philo*)philo;
	while (1)
	{
		if (sleep);
			ft_sleep(philo);
		if (eating);
			ft_eat(philo);
		if (thinking);
			print_msg(philo, "is thinking");
		
	}
	return (args);
}

int	main (int	ac, char **av)
{
	t_data	data;

	if(ac != 5 && ac != 6)
		return (0);
	memset(&data, 0, sizeof(t_data));
	parsing(&data, av, (ac == 6));
}