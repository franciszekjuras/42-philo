/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjuras <fjuras@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:51:58 by fjuras            #+#    #+#             */
/*   Updated: 2022/10/03 00:43:05 by fjuras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include "argparse.h"
#include "app.h"
#include "philo.h"
#include "resrc.h"
#include "counter.h"
#include "atoi.h"

int	app_init(t_app *app, int argc, char **argv)
{
	int	i;

	if (!parse_args(&app->thcommon.args, argc, argv))
	{
		printf("Usage: %s <time to die> <time to eat> "
			"<time to sleep> [times must eat]\n", argv[0]);
		return (-1);
	}
	app->philo_num = app->thcommon.args.philo_num;
	app->th_ids = malloc(sizeof(pthread_t) * app->philo_num);
	app->th_data = malloc(sizeof(t_thdata) * app->philo_num);
	app->forks = malloc(sizeof(t_resrc) * app->philo_num);
	resrc_init(&app->thcommon.dead_token);
	counter_init(&app->thcommon.left_count, app->philo_num);
	i = 0;
	while (i < app->philo_num)
	{
		resrc_init(&app->forks[i]);
		++i;
	}
	gettimeofday(&app->thcommon.start_time, NULL);
	return (0);
}

void	app_fill_th_data(t_app *app)
{
	int	i;

	i = 0;
	while (i < app->philo_num)
	{
		app->th_data[i].lfork = &app->forks[i];
		app->th_data[i].rfork = &app->forks[i + 1];
		app->th_data[i].idx = i + 1;
		app->th_data[i].common = &app->thcommon;
		++i;
	}
	app->th_data[i - 1].rfork = &app->forks[0];
}

void	app_start(t_app *app, void *(*th_func)(void *))
{
	int	i;

	i = 0;
	while (i < app->philo_num)
	{
		pthread_create(&app->th_ids[i], NULL, th_func, &app->th_data[i]);
		++i;
	}
}

void	app_free(t_app *app)
{
	int	i;

	resrc_free(&app->thcommon.dead_token);
	counter_free(&app->thcommon.left_count);
	free(app->th_ids);
	free(app->th_data);
	i = 0;
	while (i < 0)
		resrc_free(&app->forks[i++]);
	free(app->forks);
}

int	main(int argc, char **argv)
{
	t_app	app;
	int		i;

	if (app_init(&app, argc, argv) < 0)
		return (-1);
	app_fill_th_data(&app);
	app_start(&app, philo_main);
	i = 0;
	while (i < app.philo_num)
		pthread_join(app.th_ids[i++], NULL);
	app_free(&app);
}
