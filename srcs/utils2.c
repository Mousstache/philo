/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motroian <motroian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:50:14 by motroian          #+#    #+#             */
/*   Updated: 2023/05/15 18:36:29 by motroian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_dead(t_data *data, int i)
{
	pthread_mutex_lock(& data->die);
	data->dead = 1;
	pthread_mutex_unlock(& data->die);
	pthread_mutex_lock(&data->print);
	printf("%lld %d Died\n", (get_time() - data->philo[i].time),
		data->philo->name + 1);
	pthread_mutex_unlock(&data->print);
}

void	ft_unlock(t_philo *philo, int opt)
{
	if (opt == 0)
		pthread_mutex_unlock(philo->right);
	else if (opt == 1)
		pthread_mutex_unlock(philo->left);
	else
	{
		pthread_mutex_unlock(philo->left);
		pthread_mutex_unlock(philo->right);
	}
}

int	ft_digit(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = -1;
		while (av[i][++j])
		{
			if (!(av[i][j] >= '0' && av[i][j] <= '9'))
				return (1);
		}
		i++;
	}
	return (0);
}
