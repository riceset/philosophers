#include "philo.h"

typedef struct s_time
{
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int num_of_times_each_philo_must_eat;
} t_time;

typedef struct s_data
{
	int id;
	int num_philos;
	t_time time;
	pthread_mutex_t *forks;
} t_data;

t_data *init_data(int argc, char **argv)
{
	t_data *data;

	data = malloc(sizeof(t_data *));
	if (!data)
		return (NULL);
	data->num_philos = ft_atoi(argv[1]);
	data->time.time_to_die = atoi(argv[2]);
	data->time.time_to_eat = atoi(argv[3]);
	data->time.time_to_sleep = atoi(argv[4]);
	if (argc == 6)
		data->time.num_of_times_each_philo_must_eat = atoi(argv[5]);
	else
		data->time.num_of_times_each_philo_must_eat = -1;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philos);
	if (!data->forks)
		return (NULL);
	int i = 0;
	while (i < data->num_philos)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}

	return (data);
}

void *routine(void *arg)
{
	(void)arg;
	return (NULL);
}

void destroy_data(t_data *data)
{
	free(data->forks);
	free(data);
}

int main(int argc, char **argv)
{
	t_data *data;
	pthread_t *philos;

	if (!(5 <= argc && argc <= 6))
		return (1);
	data = init_data(argc, argv);
	if (!data)
		return (1);

	philos = malloc(sizeof(pthread_t) * data->num_philos);
	if (!philos)
		return (1);
	int i = 0;
	while (i < data->num_philos)
	{
		data->id = i + 1;
		pthread_create(&philos[i], NULL, routine, NULL);
		i++;
	}
	i = 0;
	while (i < data->num_philos)
	{
		pthread_join(philos[i], NULL);
		i++;
	}
	free(philos);
	destroy_data(data);
	return (0);
}
