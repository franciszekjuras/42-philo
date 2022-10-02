/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjuras <fjuras@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:51:58 by fjuras            #+#    #+#             */
/*   Updated: 2022/10/02 20:40:20 by fjuras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef APP_H
# define APP_H
# include <pthread.h>
# include "argparse.h"
# include "counter.h"
# include "philo.h"
# include "resrc.h"
# include "utils.h"

typedef struct s_app
{
	pthread_t	*th_ids;
	t_thdata	*th_data;
	t_resrc		*forks;
	t_thcommon	thcommon;
	int			philo_num;
}	t_app;

#endif
