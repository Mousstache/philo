/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motroian <motroian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:44:33 by motroian          #+#    #+#             */
/*   Updated: 2023/05/12 17:33:27 by motroian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_philo *philo)
{
	int	philo_got_put_in_a_pack;

	pthread_mutex_lock(&philo->data->die);
	philo_got_put_in_a_pack = philo->data->dead;
	pthread_mutex_unlock(&philo->data->die);
	return (philo_got_put_in_a_pack);
}

int	print_msg(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->data->print);
	if (check_death(philo))
	{
		pthread_mutex_unlock(&philo->data->print);
		return (1);
	}
	printf("%lld %d %s\n", get_time() - philo->time, philo->name +1, msg);
	pthread_mutex_unlock(&philo->data->print);
	return (0);
}

void	you_slip(long time)
{
	long	begin;

	begin = get_time();
	while (get_time() - begin < time)
		usleep(10);
}

long int	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int	ft_sleep(t_philo *philo)
{
	if (print_msg(philo, "is sleeping"))
		return (EXIT_SUCCESS);
	you_slip(philo->data->ttsleep);
	return (EXIT_SUCCESS);
}
