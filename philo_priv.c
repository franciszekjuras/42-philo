/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_priv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjuras <fjuras@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:51:58 by fjuras            #+#    #+#             */
/*   Updated: 2022/10/03 13:43:06 by fjuras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include "philo.h"

static void	stamped_print_unprot(t_thdata *data, const char *str)
{
	printf("%-5d %3d %s\n",
		ms_elapsed_since(data->common->start_time), data->idx, str);
}

void	stamped_print(t_thdata *data, const char *str)
{
	pthread_mutex_lock(&data->common->print_mutex);
	if (resrc_avl(&data->common->dead_token))
		stamped_print_unprot(data, str);
	pthread_mutex_unlock(&data->common->print_mutex);
}

int	philo_die(t_thdata *data)
{
	pthread_mutex_lock(&data->common->print_mutex);
	if (resrc_acq(&data->common->dead_token))
		stamped_print_unprot(data, "died");
	pthread_mutex_unlock(&data->common->print_mutex);
	return (0);
}
