/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohrechyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 09:16:04 by ohrechyn          #+#    #+#             */
/*   Updated: 2017/04/21 09:30:55 by ohrechyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		digit_width_min3(int *otric, int *len, int *length, int *spec)
{
	int		ret;

	ret = 0;
	if (*spec == 'f' && g_space && *len <= g_width)
	{
		*length -= print_only_c(' ');
		ret += 1;
	}
	if ((*spec == 'x' || *spec == 'X') && *len && g_sharp && *otric)
	{
		*length -= 2;
		ret += 2;
		if (g_width && g_zero)
		{
			if (*spec == 'x')
				print_only_s("0x");
			if (*spec == 'X')
				print_only_s("0X");
		}
	}
	digit_width_min14(&ret, length, spec);
	if ((*spec == 'x' || *spec == 'X') && *len && g_sharp && !*otric)
		*length += 1;
	return (ret);
}

int		digit_width_min4(int *otric, int *zero_suka, int *length, int *spec)
{
	int		ret;

	ret = 0;
	if ((*otric == 1 && g_space && g_width && *length > 0 &&
				!g_plus_pl && *spec != 'o' && *spec != 'p' && !zero_suka))
	{
		*length -= print_only_c(' ');
		ret += 1;
	}
	return (ret);
}

int		digit_width_min5(int *otric, int *len, int *length, int *spec)
{
	int		ret;

	ret = 0;
	if (((*spec == 'd' || *spec == 'i')) && ((g_space && (*len <= g_width
						|| !g_width) && !g_plus_pl && *otric == 1)
				|| (g_zero && g_space && *otric && g_width < 1)))
	{
		*length -= print_only_c(' ');
		ret += 1;
	}
	return (ret);
}

void	digit_width_min6(int *oux, int *otric, int *length)
{
	if (*oux && g_sharp && !*otric)
		*length -= 1;
}

int		digit_width_min8(int *otric, int *ret, int *set_minus, int *zero_suka)
{
	int		length;

	length = 0;
	if (!*otric && *set_minus)
		length -= 1;
	if (!*otric && (g_zero && g_tochnost == -1) && !*zero_suka && *set_minus)
	{
		print_only_c('-');
		*ret += 1;
	}
	return (length);
}
