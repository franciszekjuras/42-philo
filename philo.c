/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjuras <fjuras@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:51:58 by fjuras            #+#    #+#             */
/*   Updated: 2022/10/02 00:06:29 by fjuras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include "philo.h"
#include "resrc.h"
#include "counter.h"
#include "atoi.h"

t_args	parse_args(int argc, char **argv)
{
	t_args	args;

	args.philo_num = ft_atoi(argv[1]);
	args.time_die = ft_atoi(argv[2]);
	args.time_eat = ft_atoi(argv[3]);
	args.time_sleep = ft_atoi(argv[4]);
	if (argc >= 6)
		args.eat_num = ft_atoi(argv[5]);
	else
		args.eat_num = -1;
	return (args);
}

void	*crazy_printer(void *arg)
{
	t_thdata	*data;

	data = arg;
	// usleep(1000);
	counter_incr(data->counter);
	// while (!resrc_acq(data->fork))
	// 	usleep(10);
	// printf("%d started eating\n", data->idx);
	// usleep(100);
	// printf("%d stoped eating\n", data->idx);
	// resrc_rel(data->fork);
	return (NULL);
}

int	philo_init(t_philo *app, int argc, char **argv)
{
	if (argc < 5)
	{
		printf("%s: at least 4 arguments required\n", argv[0]);
		return (-1);
	}
	app->args = parse_args(argc, argv);
	app->thread_ids = malloc(sizeof(pthread_t) * app->args.philo_num);
	app->thread_data = malloc(sizeof(t_thdata) * app->args.philo_num);
	app->forks = malloc(sizeof(t_resrc) * app->args.philo_num);
	return (0);
}

void	philo_free(t_philo *app)
{
	free(app->thread_ids);
	free(app->thread_data);
	free(app->forks);
	return (0);
}

int	main(int argc, char **argv)
{
	t_philo	app;
	int		i;

	if (philo_init(&app, argc, argv) < 0)
		return (-1);

	// resrc_init(&fork);
	// counter_init(&counter);
	// i = 0;
	// while (i < N)
	// {
	// 	thread_data[i].idx = i + 1;
	// 	thread_data[i].fork = &fork;
	// 	thread_data[i].counter = &counter;
	// 	pthread_create(&thread_ids[i], NULL, crazy_printer, &thread_data[i]);
	// 	++i;
	// }
	// i = 0;
	// while (i < N)
	// 	pthread_join(thread_ids[i++], NULL);
	// printf("Counter: %d\n", counter_read(&counter));
	// resrc_free(&fork);
	// counter_free(&counter);
	// return (0);
}
