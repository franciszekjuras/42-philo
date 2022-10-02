/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_priv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjuras <fjuras@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:51:58 by fjuras            #+#    #+#             */
/*   Updated: 2022/10/03 01:11:48 by fjuras           ###   ########.fr       */
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
	if (!resrc_avl(&data->common->dead_token))
		return ;
	pthread_mutex_lock(&data->common->print_mutex);
	stamped_print_unprot(data, str);
	pthread_mutex_unlock(&data->common->print_mutex);
}

int	philo_die(t_thdata *data)
{
	if (resrc_acq(&data->common->dead_token))
		stamped_print_unprot(data, "died");
	return (0);
}
