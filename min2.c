/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohrechyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 09:31:08 by ohrechyn          #+#    #+#             */
/*   Updated: 2017/04/21 09:37:26 by ohrechyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	digit_width_min9(int *otric, int *length, int *ret, int *spec)
{
	int i;

	i = 0;
	if ((*otric == 1 && !g_zero && g_plus_pl)
			|| (*otric == 1 && g_zero && g_tochnost != -1 && g_plus_pl))
		*length -= 1;
	if (*otric == 1 && g_plus_pl && (g_zero && g_tochnost == -1)
			&& *spec != 'u')
	{
		*length -= print_only_c('+');
		*ret += 1;
	}
	if (*length > 0)
	{
		while (i++ < *length)
		{
			if ((g_tochnost == -1 && g_zero)
					|| ((*spec == 's' || *spec == 'c') && g_zero))
				*ret += print_only_c('0');
			else
				*ret += print_only_c(' ');
		}
	}
}

int		digit_width_min10(int *otric, int *spec, int *set_minus, int *zero_suka)
{
	int ret;

	ret = 0;
	if (((!*otric && !g_zero) || (!*otric && g_zero && g_tochnost != -1))
			&& !*zero_suka && *set_minus)
		ret += print_only_c('-');
	if (((*otric && !g_zero && g_plus_pl) || (*otric && g_zero
					&& g_tochnost != -1 && g_plus_pl)) && *spec != 'u')
		ret += print_only_c('+');
	return (ret);
}

int		digit_width_min11(int *otric, int *spec)
{
	if ((*otric == 1 && g_plus_pl && *spec != 'u' && *spec != 'p'
				&& *spec != 'b' && *spec != 'x' && *spec != 'X')
			&& !(*spec == 'o' && *otric == 1))
		return (1);
	return (0);
}

int		digit_width_min12(int *otric, int *spec, int *len, int *zero_suka)
{
	int ret;

	ret = 0;
	if ((*zero_suka && *otric == 2 && (g_tochnost < *len
					|| (*len < g_width && g_tochnost <= *len)))
			|| (*spec == 'o' && g_sharp && *otric == 2))
		ret += print_only_c('0');
	return (ret);
}

int		digit_width_min13(int *otric, int *len, int *ret, int *spec)
{
	int i;

	if ((*spec == 'x' || *spec == 'X') && len
			&& g_sharp && *otric && !(g_width && g_zero))
	{
		if (*spec == 'x')
			print_only_s("0x");
		if (*spec == 'X')
			print_only_s("0X");
	}
	if (*spec == 'p' && !(g_width && g_zero))
		print_only_s("0x");
	if (*spec == 'b' && !(g_width && g_zero))
		print_only_s("0b");
	if (g_tochnost != -1 && *spec != 'c' && *spec != 's')
	{
		i = 0;
		while (i++ < (g_tochnost - *len))
			*ret += print_only_c('0');
	}
	return (*ret);
}
