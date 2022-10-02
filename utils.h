/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjuras <fjuras@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:51:58 by fjuras            #+#    #+#             */
/*   Updated: 2022/10/02 21:51:07 by fjuras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <sys/time.h>

typedef struct timeval	t_timeval;

time_t	time_diff_us(t_timeval later, t_timeval earlier);
time_t	us_to_ms(time_t time_us);
int		ms_elapsed_since(t_timeval earlier);
int		did_ms_elapse_since(time_t time_ms, t_timeval earlier);
void	swap(void **a, void **b);

#endif
