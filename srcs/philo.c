/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motroian <motroian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:30:17 by motroian          #+#    #+#             */
/*   Updated: 2023/04/09 19:32:28 by motroian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_eat(t_philo *philo)
{
	print_msg(philo, "Take a fork");
	pthread_mutex_lock(& philo->data->finish);
	philo->data->finisheat = get_time(philo, 1);
	pthread_mutex_unlock(& philo->data->finish);
	print_msg(philo, "is eating");
	return (0);
}

void	watcher(t_data *data)
{
	int		i;
	long	time;

	while (1)
	{
		i = -1;
		while (++i <= data->nbphilo)
		{
			pthread_mutex_lock(& data->finish);
			time = get_time(& data->philo[i], 1) - data->finisheat;
			pthread_mutex_unlock(& data->finish);
			if (time >= data->ttdie)
			{
				pthread_mutex_lock(& data->die);
				data->dead = 1;
				pthread_mutex_unlock(& data->die);
				print_msg(data->philo, "died");
				return ;
			}
		}
		usleep(100);
	}
}

void	*routine(void *phil)
{
	t_philo	*philo;

	philo = (t_philo *)phil;
	while (1)
	{
		if (ft_sleep(philo))
			break ;
		if (ft_eat(philo))
			break ;
		if (print_msg(philo, "is thinking"))
			break ;
	}
	return (NULL);
}
int	main (int	ac, char **av)
{
	t_data	data;

	if(ac != 5 && ac != 6)
		return (0);
	memset(&data, 0, sizeof(t_data));
	parsing(&data, av, (ac == 6));
}