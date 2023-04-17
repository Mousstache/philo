/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motroian <motroian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:44:33 by motroian          #+#    #+#             */
/*   Updated: 2023/04/17 18:22:02 by motroian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_philo *philo)
{
	int	philo_got_put_in_a_pack;

	pthread_mutex_lock(&philo->die);
	philo_got_put_in_a_pack = philo->dead;
	pthread_mutex_unlock(&philo->die);
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
	printf("%ld %d %s", get_time(philo, 1), philo->name, msg);
	pthread_mutex_unlock(&philo->data->print);
	return (0);
}
void	you_slip(long time, t_philo *philo)
{
	int	begin;

	begin = get_time(philo, 0);
	while (get_time(philo, 0) - begin < time)
		usleep(10);
}
long int	get_time(t_philo *philo, int c)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	if (c == 0)
		return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
	else
		return ((time.tv_sec * 1000) + (time.tv_usec / 1000) - (philo->finisheat));
}

int	ft_sleep(t_philo *philo)
{
	print_msg(philo, "is sleeping");
	you_slip(philo->data->ttsleep, philo);
	return (0);
}
