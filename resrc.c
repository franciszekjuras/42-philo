/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resrc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjuras <fjuras@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 22:54:21 by fjuras            #+#    #+#             */
/*   Updated: 2022/10/01 22:58:23 by fjuras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "resrc.h"

void	resrc_init(t_resrc *resrc)
{
	pthread_mutex_init(&resrc->mutex, NULL);
	resrc->available = 1;
}

void	resrc_free(t_resrc *resrc)
{
	pthread_mutex_destroy(&resrc->mutex);
}

int	resrc_acq(t_resrc *resrc)
{
	int	acq_result;

	pthread_mutex_lock(&resrc->mutex);
	acq_result = resrc->available;
	resrc->available = 0;
	pthread_mutex_unlock(&resrc->mutex);
	return (acq_result);
}

void	resrc_rel(t_resrc *resrc)
{
	pthread_mutex_lock(&resrc->mutex);
	resrc->available = 1;
	pthread_mutex_unlock(&resrc->mutex);
}
