/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motroian <motroian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:32:21 by motroian          #+#    #+#             */
/*   Updated: 2023/04/03 15:21:09 by motroian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>
# include <errno.h>
# include <pthread.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/time.h>
# include <sys/types.h>


typedef struct s_data	t_data;

typedef struct s_philo
{
	long long time;
	int	name;
	int	nbeat;
	pthread_mutex_t	mut;
	pthread_mutex_t *left;
	pthread_mutex_t *right;
	pthread_t		create;
	t_data		*data;
}	t_philo;

typedef struct s_data
{
	int		ttsleep;
	int		tteat;
	int		nbphilo;
	int		ttdie;
	int		nbeat;
	int		finisheat;
	int		dead;
	pthread_mutex_t die;
	pthread_mutex_t *fork;
	pthread_mutex_t print;
	pthread_mutex_t finish;
	t_philo *philo;
}	t_data;

void		parsing(t_data *data, char **av, int opt);
long int	ft_atoi(char *str);
void		*routine(void *args);

#endif