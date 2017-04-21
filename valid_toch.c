/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_toch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohrechyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 11:27:45 by ohrechyn          #+#    #+#             */
/*   Updated: 2017/04/21 11:30:29 by ohrechyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	valid_toch_min(t_hard **list, int *dig, int *last, int *start)
{
	t_hard	*rs;

	rs = *list;
	*dig = 0;
	*last = 0;
	*start = rs->dot;
}

static void	valid_toch_min2(int start, int end, char **tmp, char *str)
{
	if ((end - start) > 0)
		*tmp = ft_strsub(str, (unsigned int)start, (size_t)(end - start));
	else
		*tmp = ft_strdup("0");
}

int			valid_toch(char *str, t_hard **list, int start)
{
	int		tmp_start;
	int		dig;
	int		last;
	char	*tmp;
	int		s[8];

	valid_toch_min(list, &dig, &last, &start);
	tmp_start = start;
	while (str[start++])
	{
		if (ft_isdigit(str[start]) && !dig)
		{
			s[0] = start;
			dig = 1;
		}
		if (!ft_isdigit(str[start]) && !last)
		{
			s[1] = start;
			last = 1;
			break ;
		}
	}
	valid_toch_min2(tmp_start + 1, s[1], &tmp, str);
	return ((int)ft_atoi(tmp));
}
