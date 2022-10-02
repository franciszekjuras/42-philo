/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjuras <fjuras@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 22:54:26 by fjuras            #+#    #+#             */
/*   Updated: 2022/10/02 22:57:37 by fjuras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COUNTER_H
# define COUNTER_H
# include <pthread.h>

typedef struct s_counter
{
	int				count;
	pthread_mutex_t	mutex;
}	t_counter;

void	counter_init(t_counter *counter, int start_value);

void	counter_free(t_counter *counter);

void	counter_incr(t_counter *counter);

void	counter_decr(t_counter *counter);

int		counter_read(t_counter *counter);

#endif
