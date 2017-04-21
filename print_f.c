/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohrechyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 09:45:19 by ohrechyn          #+#    #+#             */
/*   Updated: 2017/04/21 09:53:57 by ohrechyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int				find_okrug(double d, int okrug)
{
	long double	temp_d;
	int			i;
	char		*s;
	int			count;

	i = 0;
	temp_d = d;
	temp_d -= (long long int)d;
	while (i++ < okrug + 1)
		temp_d *= 10;
	s = ft_itoa((long long)temp_d);
	count = ft_strlen(s);
	if (g_tochnost == 0)
	{
		if (s[0] >= '5')
			g_left += 1;
	}
	if (s[count - 1] >= '5')
		return (1);
	else
		return (0);
}

static double	print_f_min(double *d, int *g, int *okrug, int *count)
{
	if (*d < 0)
	{
		*g = 0;
		*d = *d * -1;
		*count += 1;
	}
	else
		*g = 1;
	if (g_tochnost > 16)
		*okrug = 16;
	else if (g_tochnost > 0)
		*okrug = g_tochnost;
	else
		*okrug = 6;
	return (*d);
}

static double	print_f_min2(int *right_count, long long *right,
		double *d, int *zero_count)
{
	*right_count = ft_strlen(ft_itoa(*right));
	if (g_tochnost == 0)
		*right_count = 0;
	*zero_count = g_tochnost - *right_count;
	return (*d);
}

static int		print_f_min3(long long *right,
		int *zero_count, int *count)
{
	int		x;

	x = 0;
	print_only_s(ft_itoa(g_left));
	if (g_tochnost != 0)
	{
		print_only_c('.');
		print_only_s(ft_itoa(*right));
	}
	if (*zero_count > 0)
		while (*zero_count > x++)
			print_only_c('0');
	return (*count);
}

int				print_f(double d, int count, int i, int g)
{
	long long	right;
	int			zero_count;
	int			right_count;
	int			left_count;
	int			okrug;

	g_temp_d = print_f_min(&d, &g, &okrug, &count) - (long long int)d;
	while (i++ < okrug)
		g_temp_d *= 10;
	right = (long long)g_temp_d;
	g_left = (long long)print_f_min2(&right_count, &right, &d, &zero_count);
	if (find_okrug(d, okrug))
		right += 1;
	left_count = ft_strlen(ft_itoa(g_left));
	count = left_count + right_count;
	print_f_min4(&count, &zero_count, &right);
	count += get_width(count, g, 3, 'f');
	return (print_f_min3(&right, &zero_count, &count));
}
