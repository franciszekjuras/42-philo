/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjuras <fjuras@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 22:54:21 by fjuras            #+#    #+#             */
/*   Updated: 2022/10/01 23:15:31 by fjuras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "counter.h"

void	counter_init(t_counter *counter)
{
	pthread_mutex_init(&counter->mutex, NULL);
	counter->count = 0;
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

int	counter_read(t_counter *counter)
{
	int	value;

	pthread_mutex_lock(&counter->mutex);
	value = counter->count;
	pthread_mutex_unlock(&counter->mutex);
	return (value);
}
