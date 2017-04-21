/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohrechyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 11:24:54 by ohrechyn          #+#    #+#             */
/*   Updated: 2017/04/21 11:27:14 by ohrechyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int		valid_zero(char *str, int *index, int *end)
{
	int		dig;
	int		z;
	int		l;

	z = *index + 1;
	dig = 0;
	l = *index;
	while (str[z] && l <= *end)
	{
		if (ft_isdigit(str[z]))
		{
			if (str[z] == '0' && !dig)
			{
				*index = l + 1;
				return (1);
			}
			dig = 1;
		}
		z++;
		l++;
	}
	return (0);
}

static int		valid_digit_min(t_hard **list, int *index, int *end, int *last)
{
	t_hard	*rs;

	*last = 0;
	rs = *list;
	*index = rs->index - 1;
	*end = rs->end;
	return (0);
}

long long int	valid_digit(char *str, t_hard **list, int dig)
{
	int		last;
	int		s[8];
	int		index;
	int		end;
	char	*tmp;

	dig = valid_digit_min(list, &index, &end, &last);
	g_zero = valid_zero(str, &index, &end);
	while (str[index++] && index <= end)
	{
		if (ft_isdigit(str[index]) && !dig)
		{
			s[0] = index;
			dig = 1;
		}
		if (dig && !ft_isdigit(str[index]) && !last)
		{
			s[1] = index;
			last = 1;
		}
	}
	tmp = ft_strsub(str, (unsigned int)s[0], (size_t)(s[1] - s[0]));
	if (!tmp)
		return (-1);
	return (ft_atoi(tmp));
}
