/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjuras <fjuras@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:51:58 by fjuras            #+#    #+#             */
/*   Updated: 2022/10/02 00:08:53 by fjuras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include "resrc.h"
# include "counter.h"
# include "argparse.h"

typedef struct s_thdata
{
	int			idx;
	t_resrc		*forks;
	t_counter	*num_finished;
}	t_thdata;

typedef struct s_philo
{
	pthread_t	*thread_ids;
	t_thdata	*thread_data;
	t_resrc		*forks;
	t_args		args;
	t_counter	num_finished;
}	t_philo;

#endif
