/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjuras <fjuras@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:51:58 by fjuras            #+#    #+#             */
/*   Updated: 2022/10/02 22:12:57 by fjuras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include "philo.h"
#include "philo_priv.h"
#include "resrc.h"
#include "utils.h"

int	philo_sleep(t_thdata *data, t_state *state)
{
	if (did_ms_elapse_since(data->common->args.time_die, state->last_meal))
		return (philo_die(data));
	if (did_ms_elapse_since(data->common->args.time_sleep, state->last_sleep))
	{
		state->func = philo_think;
		stamped_print(data, "is thinking");
	}
	return (1);
}

int	philo_think(t_thdata *data, t_state *state)
{
	if (did_ms_elapse_since(data->common->args.time_die, state->last_meal))
		return (philo_die(data));
	if (resrc_acq(data->lfork))
	{
		if (resrc_acq(data->rfork))
		{
			state->func = philo_eat;
			stamped_print(data, "is eating");
			gettimeofday(&state->last_meal, NULL);
		}
		else
		{
			resrc_rel(data->lfork);
			swap((void **)&data->lfork, (void **)&data->rfork);
		}
	}
	return (1);
}

int	philo_eat(t_thdata *data, t_state *state)
{
	if (did_ms_elapse_since(data->common->args.time_eat, state->last_meal))
	{
		resrc_rel(data->lfork);
		resrc_rel(data->rfork);
		state->func = philo_sleep;		
		stamped_print(data, "is sleeping");
		gettimeofday(&state->last_sleep, NULL);
	}
	return (1);
}

void	*philo_main(void *arg)
{
	t_thdata	*data;
	t_state		state;

	data = arg;
	state.func = philo_think;
	stamped_print(data, "is thinking");
	gettimeofday(&state.last_meal, NULL);
	while (state.func(data, &state) && resrc_avl(&data->common->dead_token))
		usleep(1000);
	return (NULL);
}
