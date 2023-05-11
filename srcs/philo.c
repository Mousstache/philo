/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motroian <motroian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:30:17 by motroian          #+#    #+#             */
/*   Updated: 2023/05/11 16:38:13 by motroian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_eat(t_philo *philo)
{
	if (philo -> name % 2 == 0)
	{
		pthread_mutex_lock(philo->left);
		if (print_msg(philo, "Take a fork"))
		{
			pthread_mutex_unlock(philo->left);
			return (1);
		}
		pthread_mutex_lock(philo->right);
		if (print_msg(philo, "Take a fork"))
		{
			pthread_mutex_unlock(philo->right);
			return (1);
		}
	}
	else
	{
		pthread_mutex_lock(philo->right);
		if (print_msg(philo, "Take a fork"))
		{
			pthread_mutex_unlock(philo->right);
			return (1);
		}
		pthread_mutex_lock(philo->left);
		if (print_msg(philo, "Take a fork"))
		{
			pthread_mutex_unlock(philo->left);
			return (1);
		}
	}
	pthread_mutex_lock(& philo->finish);
	philo->finisheat = get_time();
	pthread_mutex_unlock(& philo->finish);
	if (print_msg(philo, "is eating"))
		return (1);
	you_slip(philo->data->tteat);
	philo->nb_eat++;
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
	if (philo->nb_eat == philo->data->nbeat)
	{
		pthread_mutex_lock(&philo->nbeatlock);
		philo->data->finish++;
		pthread_mutex_unlock(&philo->nbeatlock);
		return (1);
	}
	return (0);
}

void	*routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->name % 2 == 0)
		you_slip(philo->data->tteat * 0.8);
	while (1)
	{
		if (philo->data->nbphilo % 2 && philo->nb_eat)
			you_slip(philo->data->ttdie * 0.25);
		if (ft_eat(philo))
			break ;
		if (ft_sleep(philo))
		 	break ;
		if (print_msg(philo, "is thinking"))
		 	break ;
	}
	return (NULL);
}
void	ft_dead(t_data *data, int i)
{
	pthread_mutex_lock(& data->die);
	data->dead = 1;
	pthread_mutex_unlock(& data->die);
	pthread_mutex_lock(&data->print);
	printf("%lld %d Died\n", (get_time() - data->philo[i].time) , data->philo->name + 1);
	pthread_mutex_unlock(&data->print);
}


void	watcher(t_data *data)
{
	int		i;
	long	time;

	while (1)
	{
		i = -1;
		while (++i < data->nbphilo)
		{
			pthread_mutex_lock(& data->philo->nbeatlock);
			if (data->finish == data->nbeat)
			{
				data->dead = 1;
				pthread_mutex_unlock(&data->philo->nbeatlock);
				return ;
			}
			pthread_mutex_unlock(&data->philo->nbeatlock);
			pthread_mutex_lock(& data->philo[i].finish);
			time = get_time() - data->philo[i].finisheat;
			pthread_mutex_unlock(& data->philo[i].finish);
			if (time >= data->ttdie)
			{
				ft_dead(data, i);
				return ;
			}
		}
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
	while (++i < data.nbphilo)
		pthread_mutex_destroy(data.philo[i].left);
	free(data.fork);
}