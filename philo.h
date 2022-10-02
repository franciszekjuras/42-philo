/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjuras <fjuras@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:51:58 by fjuras            #+#    #+#             */
/*   Updated: 2022/10/02 22:05:00 by fjuras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <sys/time.h>
# include "argparse.h"
# include "resrc.h"
# include "counter.h"
# include "utils.h"

typedef struct s_thcommon
{
	t_resrc		dead_token;
	t_counter	num_finished;
	t_timeval	start_time;
	t_args		args;
}	t_thcommon;

typedef struct s_thdata
{
	int			idx;
	t_resrc		*lfork;
	t_resrc		*rfork;
	t_thcommon	*common;
}	t_thdata;

typedef struct s_state	t_state;

typedef int				(*t_state_func)(t_thdata *, t_state *);

struct s_state
{
	t_state_func	func;
	t_timeval		last_meal;
	t_timeval		last_sleep;
};


int		philo_sleep(t_thdata *data, t_state *state);
int		philo_think(t_thdata *data, t_state *state);
int		philo_eat(t_thdata *data, t_state *state);
void	*philo_main(void *arg);

#endif
