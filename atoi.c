/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjuras <fjuras@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 23:23:06 by fjuras            #+#    #+#             */
/*   Updated: 2022/10/01 23:24:59 by fjuras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	ft_isspace(int c)
{
	return (c == ' ' || c == '\n' || c == '\r'
		|| c == '\t' || c == '\v' || c == '\f');
}

static int	ft_atoi_sub(const char *np, int i, int s, int base)
{
	int	r;

	i--;
	r = 0;
	while (i >= 0)
	{
		r += s * (np[i] - '0');
		s *= base;
		i--;
	}
	return (r);
}

int	ft_atoi(const char *np)
{
	int	s;
	int	i;

	while (ft_isspace(*np))
		np++;
	s = 1;
	if (*np == '-')
		s = -1;
	if (*np == '-' || *np == '+')
		np++;
	i = 0;
	while (ft_isdigit(np[i]))
		i++;
	return (ft_atoi_sub(np, i, s, 10));
}
