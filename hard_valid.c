/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_valid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohrechyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 09:08:12 by ohrechyn          #+#    #+#             */
/*   Updated: 2017/04/21 09:09:35 by ohrechyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	*hard_valid_min(int *i, int z)
{
	int *s;

	s = (int *)malloc(sizeof(int) * 11);
	while (z++ <= 7)
		s[z] = 0;
	s[8] = *i;
	s[9] = *i;
	return (s);
}

int			hard_valid(int *i, char *str, t_hard **list)
{
	int *s;

	s = hard_valid_min(i, -1);
	while (str[s[9]++])
		if (str[s[9]] == ' ')
			s[0] = s[9];
		else if (str[s[9]] == '#')
			s[1]++;
		else if (str[s[9]] == '.' && !s[2])
			s[2] = s[9];
		else if (str[s[9]] == '+')
			s[4]++;
		else if (str[s[9]] == '-')
			s[5]++;
		else if (str[s[9]] >= '0' && str[s[9]] <= '9')
			s[3]++;
		else if (simple(str[s[9]]))
		{
			s[6] = s[9];
			break ;
		}
		else
			return (0);
	return (add_hard(s[8] + 1, s, list));
}
