/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argparse.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjuras <fjuras@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:51:58 by fjuras            #+#    #+#             */
/*   Updated: 2022/10/03 00:42:01 by fjuras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGPARSE_H
# define ARGPARSE_H

typedef struct s_args
{
	int	philo_num;
	int	time_die;
	int	time_eat;
	int	time_sleep;
	int	eat_goal;
}	t_args;

int	parse_args(t_args *args, int argc, char **argv);

int	are_args_sane(t_args *args);

#endif
