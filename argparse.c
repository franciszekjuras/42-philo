/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argparse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjuras <fjuras@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:51:58 by fjuras            #+#    #+#             */
/*   Updated: 2022/10/03 00:42:24 by fjuras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "argparse.h"
#include "atoi.h"

int	parse_args(t_args *args, int argc, char **argv)
{
	if (argc < 5)
		return (0);
	args->philo_num = ft_atoi(argv[1]);
	args->time_die = ft_atoi(argv[2]);
	args->time_eat = ft_atoi(argv[3]);
	args->time_sleep = ft_atoi(argv[4]);
	if (argc >= 6)
		args->eat_goal = ft_atoi(argv[5]);
	else
		args->eat_goal = -1;
	if (!are_args_sane(args))
		return (0);
	return (1);
}

int	are_args_sane(t_args *args)
{
	int	insanity;

	insanity = 0;
	insanity += (args->philo_num <= 0);
	insanity += (args->time_die <= 0);
	insanity += (args->time_eat <= 0);
	insanity += (args->time_sleep <= 0);
	return (insanity == 0);
}
