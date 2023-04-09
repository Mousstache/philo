/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motroian <motroian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 16:02:06 by motroian          #+#    #+#             */
/*   Updated: 2023/04/09 19:33:11 by motroian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static
void ft_error(int nb)
{
	if (nb == 1)
		write (2, "La string est nulle\n", 21);
	if (nb == 2)
		write (2, "Le nombre est negatif\n", 22);
	if (nb == 3)
		write (2, "Le nombre est trop grand\n", 25);
	exit(1);
}

long int	ft_atoi(char *str)
{
	int			a;
	int			b;
	long int	c;

	a = 0;
	b = 1;
	c = 0;
	if(!str || !*str)
		ft_error(1);
	while ((str[a] >= 9 && str[a] <= 13) || (str[a] == 32))
		a++;
	while (str[a] == '-' || str[a] == '+')
	{
		if (str[a] == '-')
			ft_error(2);
		a++;
	}
	while (str[a] >= 48 && str[a] <= 57)
	{
		c = c * 10 + (str[a] - '0');
		if (c * b > INT_MAX)
			ft_error(3);
		a++;
	}
	return (c);
}

void	init_philo(t_data *data, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i <= data->nbphilo)
	{
		philo[i].name = i;
		philo[i].time = get_time(data->philo, 0);
		philo[i].mut = pthread_mutex_init(& philo[i].mut, NULL);
		philo[i].left = pthread_mutex_init(philo[i].left, NULL);
		if (i == data->nbphilo - 1)
			philo[i].right = pthread_mutex_init(philo[0].left, NULL);
		philo[i].right = pthread_mutex_init(philo[i + 1].left, NULL);
	}
}
void	parsing(t_data *data, char **av, int opt)
{
	pthread_t *philo;
	int		i;

	i = -1;
	pthread_mutex_init(& data->die, NULL);
	pthread_mutex_init(& data->finish, NULL);
	pthread_mutex_init(& data->print, NULL);
	data->nbphilo = ft_atoi(av[1]);
	data->tteat = ft_atoi(av[3]);
	data->ttdie = ft_atoi(av[2]);
	data->ttsleep = ft_atoi(av[4]);
	if (opt)
		data->nbeat = ft_atoi(av[5]);
	philo = malloc(sizeof(t_philo *) * data->nbphilo);
	data->fork = malloc(sizeof(pthread_mutex_t) * data->nbphilo);
	init_philo(data, philo);
	while (++i <= data->nbphilo)
		pthread_create(&philo[i], NULL, &routine, data);
	i = -1;
	while (++i <= data->nbphilo)
		pthread_join(philo[i], NULL);
}
