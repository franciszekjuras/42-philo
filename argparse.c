/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argparse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjuras <fjuras@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:51:58 by fjuras            #+#    #+#             */
/*   Updated: 2022/10/01 23:57:06 by fjuras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "argparse.h"
#include "atoi.h"

t_args	parse_args(int argc, char **argv)
{
	t_args	args;

	args.philo_num = ft_atoi(argv[1]);
	args.time_die = ft_atoi(argv[2]);
	args.time_eat = ft_atoi(argv[3]);
	args.time_sleep = ft_atoi(argv[4]);
	if (argc >= 6)
		args.eat_num = ft_atoi(argv[5]);
	else
		args.eat_num = -1;
	return (args);
}
