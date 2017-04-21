/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohrechyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 09:37:36 by ohrechyn          #+#    #+#             */
/*   Updated: 2017/04/21 09:39:19 by ohrechyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	digit_width_min14(int *ret, int *length, int *spec)
{
	if (*spec == 'p')
	{
		*length -= 2;
		*ret += 2;
		if (g_width && g_zero)
			print_only_s("0x");
	}
	if (*spec == 'b')
	{
		*length -= 2;
		*ret += 2;
		if (g_width && g_zero)
			print_only_s("0b");
	}
}

void	min_width_min1(char *str, int *start_w, int *start_t, int t)
{
	if (!g_space_start && !*start_w)
		*start_w = find_cifra(str, t);
	if (g_space_start && !*start_t)
		*start_t = find_cifra(str, t);
}

int		min_width_min2(char *str, int t, int *start_w, int *start_t)
{
	while (str[t++])
		if (str[t] == '%')
		{
			g_per = 1;
			return (t);
		}
		else if (str[t] == '.')
			g_space_start = 1;
		else if (str[t] == '0' && !g_space_start)
			g_zero = 1;
		else if (ft_isdigit(str[t]))
			min_width_min1(str, start_w, start_t, t);
		else if (str[t] == ' ')
			g_space++;
		else if (str[t] == '+')
			g_plus_pl++;
		else if (str[t] == '-')
			g_minus++;
		else
			return (t);
	return (0);
}

void	print_f_min4(int *count, int *zero_count, long long *right)
{
	int x;

	x = 0;
	if (g_tochnost != 0)
		*count += 1;
	if (zero_count > 0)
		while (*zero_count > x++)
			*count += 1;
	if (g_tochnost == -1 && *right == 0)
	{
		*zero_count = 5;
		*count += 5;
	}
}
