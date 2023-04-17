/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motroian <motroian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:32:21 by motroian          #+#    #+#             */
/*   Updated: 2023/04/17 18:23:57 by motroian         ###   ########.fr       */
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
	long long		time;
	int				name;
	int				nbeat;
	long long		finisheat;
	int				dead;
	pthread_mutex_t	mut;
	pthread_mutex_t left;
	pthread_mutex_t finish;
	pthread_mutex_t die;
	pthread_mutex_t *right;
	pthread_t		create;
	t_data			*data;
}	t_philo;

typedef struct s_data
{
	int				ttsleep;
	int				tteat;
	int				nbphilo;
	int				ttdie;
	int				nbeat;
	pthread_mutex_t *fork;
	pthread_mutex_t print;
	t_philo			*philo;
}	t_data;

long int	get_time(t_philo *philo, int c);
void		parsing(t_data *data, char **av, int opt);
long int	ft_atoi(char *str);
void		*routine(void *args);
int			print_msg(t_philo *philo, char *msg);
int			ft_sleep(t_philo *philo);
int			ft_eat(t_philo *philo);
void		watcher(t_data *data);

#endif