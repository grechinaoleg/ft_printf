/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohrechyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 11:31:45 by ohrechyn          #+#    #+#             */
/*   Updated: 2017/04/21 11:39:59 by ohrechyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	valid_width_dot(char *str, t_hard **list, int a)
{
	t_hard	*rs;
	int		o;
	char	*s;

	rs = *list;
	o = rs->dot;
	while (str[o--])
		if (str[o] >= '0' && str[o] <= '9')
			a++;
		else
			break ;
	o = rs->dot;
	s = ft_strnew((size_t)a);
	while (str[o--])
	{
		if (str[o] >= '0' && str[o] <= '9')
		{
			s[a - 1] = str[o];
			a--;
		}
		else
			break ;
	}
	return ((int)ft_atoi(s));
}

int			valid_width(char *str, t_hard **list, int digit)
{
	t_hard	*rs;

	rs = *list;
	if (rs->dot)
		return (valid_width_dot(str, list, 0));
	else if (digit)
		return (digit);
	return (0);
}
