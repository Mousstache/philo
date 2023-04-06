/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motroian <motroian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:44:33 by motroian          #+#    #+#             */
/*   Updated: 2023/04/06 17:30:15 by motroian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(t_philo *philo)
{
	print_msg(philo, "take a fork");
	print_msg()
}

void	ft_sleep(t_philo *philo)
{
	pthread_mutex_lock(philo->data->print);
	print_msg(philo, "is sleeping");
	pthread_mutex_unlock(philo->data->print);
}

// pthread_mutex_t lo;
// pthread_mutex_t lof;

// typedef struct t_data
// {
// 	int test;
// 	int j;
// }t_data;

// void	*routine(void *args)
// {
// 	t_data* data;

// 	data = (t_data *)args;
// 	pthread_mutex_lock(&lo);
// 	data->j = 20;
// 	pthread_mutex_unlock(&lo);
// }


// int main(void)
// {
// 	pthread_t	thread;
// 	pthread_mutex_init(&lo, NULL);
// 	pthread_mutex_init(&lof, NULL);
// 	t_data	data;
// 	data.j = 25;
// 	pthread_create(&thread, NULL, routine, &data);
// 	pthread_mutex_lock(&lof);
// 	printf("j: %d\n", data.j);
// 	pthread_mutex_unlock(&lof);
// 	pthread_join(thread, NULL);
// 	printf("END");
// }