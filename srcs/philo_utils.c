/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motroian <motroian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:44:33 by motroian          #+#    #+#             */
/*   Updated: 2023/04/09 17:10:03 by motroian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_msg(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->data->print);
	printf("%ld %d %s", get_time(philo, 1), philo->name, msg);
	pthread_mutex_unlock(&philo->data->print);
	return (0);
}
int	check_death(t_data *data)
{
	int	philo_got_put_in_a_pack;

	pthread_mutex_lock(data->die, NULL);
	philo_got_put_in_a_pack = data->dead;
	pthread_mutex_unlock(data->die, NULL);
	return (philo_got_put_in_a_pack);
}
void	you_slip(long time)
{
	int	begin;

	begin = get_time(0);
	while (get_time(0) - begin < time)
		usleep(10);
}
long int	get_time(t_philo *philo, int c)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	if (c == 0)
		return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
	else
		return ((time.tv_sec * 1000) + (time.tv_usec / 1000) - (philo->time));
}

int	ft_sleep(t_philo *philo)
{
	print_msg(philo, "is sleeping");
	you_slip(philo->data->ttsleep);
	return (0);
}
