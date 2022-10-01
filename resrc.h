/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resrc.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjuras <fjuras@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 22:54:26 by fjuras            #+#    #+#             */
/*   Updated: 2022/10/01 22:58:00 by fjuras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESRC_H
# define RESRC_H
# include <pthread.h>

typedef struct s_resrc
{
	int				available;
	pthread_mutex_t	mutex;
}	t_resrc;

void	resrc_init(t_resrc *resrc);

void	resrc_free(t_resrc *resrc);

int		resrc_acq(t_resrc *resrc);

void	resrc_rel(t_resrc *resrc);

#endif
