/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohrechyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 09:01:29 by ohrechyn          #+#    #+#             */
/*   Updated: 2017/04/21 09:07:52 by ohrechyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int			digit_width_min_dg(int *set_minus,
		int *oux, int *ret, int *length)
{
	*set_minus = 0;
	*oux = 0;
	*ret = 0;
	*length = 0;
	return (0);
}

static void			digit_width_min(int *zero_s,
		int *oux, int *set_minus, int *spec)
{
	if (g_sharp && (*spec == 'o' || *spec == 'u' || *spec == 'x'
				|| *spec == 'X'))
		*zero_s = 1;
	if (*spec == 'o' || *spec == 'u' || *spec == 'x' || *spec == 'X')
		*oux = 1;
	if (*spec == 'i' || *spec == 'd' || *spec == 'f')
		*set_minus = 1;
}

static int			digit_width_min2(int *otric,
		int *len, int *zero_suka, int *spec)
{
	int length;

	length = 0;
	if (g_tochnost >= *len && *spec != 'c' && *spec != 's')
		length += g_width - g_tochnost;
	else
		length += g_width - *len;
	if ((*zero_suka && *otric == 2 && (g_tochnost < *len
					|| (*len < g_width && g_tochnost <= *len)))
			|| (*spec == 'o' && g_sharp && *otric == 2))
		length -= 1;
	return (length);
}

static long long	digit_width(int len, int otric, int spec, int length)
{
	int ret;
	int zero_suka;
	int set_minus;
	int oux;

	zero_suka = digit_width_min_dg(&set_minus, &oux, &ret, &length);
	digit_width_min(&zero_suka, &oux, &set_minus, &spec);
	length += digit_width_min2(&otric, &len, &zero_suka, &spec);
	ret += digit_width_min3(&otric, &len, &length, &spec);
	if (!oux)
		ret += digit_width_min4(&otric, &zero_suka, &length, &spec);
	ret += digit_width_min5(&otric, &len, &length, &spec);
	digit_width_min6(&oux, &otric, &length);
	if (g_width && !g_minus)
	{
		length += digit_width_min8(&otric, &ret, &set_minus, &zero_suka);
		digit_width_min9(&otric, &length, &ret, &spec);
		ret += digit_width_min10(&otric, &spec, &set_minus, &zero_suka);
	}
	else if (!otric && !zero_suka && set_minus)
		ret += print_only_c('-');
	else if (digit_width_min11(&otric, &spec))
		ret += print_only_c('+');
	ret += digit_width_min12(&otric, &spec, &len, &zero_suka);
	return (digit_width_min13(&otric, &len, &ret, &spec));
}

long long int		get_width(int len, int otric, int chr, int type)
{
	if (type == 'd' || type == 'u' || type == 'o' || type == 'p'
			|| type == 'b' || type == 'x' || type == 'X' || type == 's'
			|| type == 'c' || type == 'f')
		return (digit_width(len, otric, type, 0));
	chr = 0;
	return (0);
}
