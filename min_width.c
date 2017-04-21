/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohrechyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 09:39:31 by ohrechyn          #+#    #+#             */
/*   Updated: 2017/04/21 09:42:33 by ohrechyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	get_min_steps(int steps, int stope)
{
	int		len;

	if (!g_width && !g_tochnost && !g_space_start && g_space)
		steps += 1;
	len = stope - (steps);
	if (!g_width && !g_tochnost && !g_space_start && !g_space && !g_per)
		return (0);
	if (len > 0)
		return (len);
	return (0);
}

int			find_cifra(char *str, int t)
{
	int		stop;
	int		s;
	int		tmp;

	tmp = t;
	stop = 0;
	while (str[t])
	{
		if (!ft_isdigit(str[t]))
			stop = t;
		t++;
	}
	s = stop - tmp;
	if (stop > 0)
		return (ft_atoi(ft_strsub(str, (unsigned int)tmp, (size_t)s)));
	return (0);
}

int			min_width(char *str, int *i, int stope, int steps)
{
	int		t;
	int		start_w;
	int		start_t;

	t = *i;
	steps = t;
	start_w = 0;
	start_t = 0;
	stope = min_width_min2(str, t, &start_w, &start_t);
	g_width = start_w;
	g_tochnost = start_t;
	*i += get_min_steps(steps, stope);
	if (start_w || start_t || g_space || g_space_start)
		return (1);
	return (0);
}

static int	print_min_width(void)
{
	int		i;
	int		len;

	len = 0;
	i = 0;
	if (g_width > 0)
	{
		while (i++ < g_width)
		{
			if (g_zero && !g_minus)
				len += print_only_c('0');
			else
				len += print_only_c(' ');
		}
	}
	return (len);
}

int			get_min_width(void)
{
	int		len;

	len = 0;
	if (g_per)
		g_width -= 1;
	if (!g_minus)
		len += print_min_width();
	if (g_per)
		len += print_only_c('%');
	if (g_minus)
		len += print_min_width();
	clean_globals();
	return (len);
}
