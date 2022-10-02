/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjuras <fjuras@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:51:58 by fjuras            #+#    #+#             */
/*   Updated: 2022/10/02 21:23:53 by fjuras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <stdlib.h>
#include "utils.h"

time_t	time_diff_us(t_timeval later, t_timeval earlier)
{
	time_t		diff_us;

	diff_us = (later.tv_sec - earlier.tv_sec) * 1000000;
	diff_us += (later.tv_usec - earlier.tv_usec);
	return (diff_us);
}

time_t	us_to_ms(time_t time_us)
{
	return ((time_us) / 1000);
}

int	ms_elapsed_since(t_timeval earlier)
{
	t_timeval	now;
	time_t		since_ms;

	gettimeofday(&now, NULL);
	since_ms = us_to_ms(time_diff_us(now, earlier));
	return (since_ms);
}

int	did_ms_elapse_since(time_t time_ms, t_timeval earlier)
{
	if (ms_elapsed_since(earlier) >= time_ms)
		return (1);
	else
		return (0);
}

void	swap(void **a, void **b)
{
	void	*c;

	c = *a;
	*a = *b;
	*b = c;
}
