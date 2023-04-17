/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motroian <motroian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:30:17 by motroian          #+#    #+#             */
/*   Updated: 2023/04/17 18:25:13 by motroian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->left);
	print_msg(philo, "Take a fork");
	pthread_mutex_unlock(&philo->left);
	pthread_mutex_lock(& philo->finish);
	philo->finisheat = get_time(philo, 1);
	pthread_mutex_unlock(& philo->finish);
	print_msg(philo, "is eating");
	return (0);
}

void	*routine(void *ptr)
{
	t_data	*data;

	data = (t_data *)ptr;
	// printf(">> %p\n", data);
	if (data->nbphilo % 2 == 0) // replace to index
		usleep(data->tteat * 0.28);
	// while (1)
	// {
	// 	if (ft_eat(data))
	// 		break ;
	// 	if (ft_sleep(data))
	// 		break ;
	// 	if (print_msg(data, "is thinking"))
	// 		break ;
	// }
	return (NULL);
}
void	watcher(t_data *data)
{
	int		i;
	long	time;

			printf("laaaaaaaaaaaaaaaaaaaaaaa");
	while (1)
	{
		i = -1;
		while (++i < data->nbphilo)
		{
			printf(">> test(%d): %p", i, data);
			// pthread_mutex_lock(& data->philo[i].finish);
			// time = get_time(& data->philo[i], 1) - data->philo[i].finisheat;
			time = get_time(&data->philo[i], 1);
			// pthread_mutex_unlock(& data->philo[i].finish);
			if (time >= data->ttdie)
			{
				pthread_mutex_lock(& data->philo[i].die);
				data->philo[i].dead = 1;
				pthread_mutex_unlock(& data->philo[i].die);
				print_msg(&data->philo[i], "died");
				return ;
			}
		}
		usleep(100);
	}
}
int	main (int	ac, char **av)
{
	t_data	data;
	int		i;

	i = -1;
	if(ac != 5 && ac != 6)
		return (0);
	memset(&data, 0, sizeof(t_data));
	parsing(&data, av, (ac == 6));
	// while (++i < data.nbphilo)
		// pthread_mutex_destroy(&data.philo[i].left);
	free(data.fork);
}