#include <stddef.h>
#include <stdio.h>
#include <pthread.h>

void	*routine(void *args)
{
	int i;

	while (1)
	{
		i = 0;
		printf("tour%i", i);
		i++;
	}
	return (NULL);
}

int main(int ac, char **av)
{
	pthread_t	philo;

	pthread_create(&philo, &routine, NULL, NULL);
}