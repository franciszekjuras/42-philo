/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjuras <fjuras@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 22:54:21 by fjuras            #+#    #+#             */
/*   Updated: 2022/10/02 22:56:21 by fjuras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "counter.h"

void	counter_init(t_counter *counter, int start_value)
{
	pthread_mutex_init(&counter->mutex, NULL);
	counter->count = start_value;
}

void	counter_free(t_counter *counter)
{
	pthread_mutex_destroy(&counter->mutex);
}

void	counter_incr(t_counter *counter)
{
	pthread_mutex_lock(&counter->mutex);
	counter->count++;
	pthread_mutex_unlock(&counter->mutex);
}

void	counter_decr(t_counter *counter)
{
	pthread_mutex_lock(&counter->mutex);
	counter->count--;
	pthread_mutex_unlock(&counter->mutex);
}

int	counter_read(t_counter *counter)
{
	int	value;

	pthread_mutex_lock(&counter->mutex);
	value = counter->count;
	pthread_mutex_unlock(&counter->mutex);
	return (value);
}
