/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_priv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjuras <fjuras@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:51:58 by fjuras            #+#    #+#             */
/*   Updated: 2022/10/02 22:13:14 by fjuras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "philo.h"

void	stamped_print(t_thdata *data, const char *str)
{	
	printf("%-5d %3d %s\n",
		ms_elapsed_since(data->common->start_time), data->idx, str);
}

int	philo_die(t_thdata *data)
{
	if (resrc_acq(&data->common->dead_token))
		stamped_print(data, "died");
	return (0);
}
