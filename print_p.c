/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohrechyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 11:16:01 by ohrechyn          #+#    #+#             */
/*   Updated: 2017/04/21 11:17:07 by ohrechyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		print_x_long(unsigned long n)
{
	if (n >= 16)
		return (print_x_long(n / 16) + print_x_long(n % 16));
	else
		return (print_only_c(base((int)n)));
}

int		print_x_long_rt(unsigned long n, char **z)
{
	if (n >= 16)
		return (print_x_long_rt(n / 16, z) + print_x_long_rt(n % 16, z));
	else
	{
		*z = ft_charjoin(*z, base((int)n));
		return (0);
	}
}

int		print_p(void *nbr, char b)
{
	int		length;
	char	*z;
	int		counter;
	int		f;

	length = 0;
	if (!nbr)
		f = 0;
	else
		f = 1;
	z = ft_strdup("");
	print_x_long_rt((unsigned long)nbr, &z);
	counter = ft_strlen(z);
	if (!nbr && g_tochnost == 0)
		counter -= 1;
	length += get_width(counter, f, 1, b);
	if (nbr || (!nbr && (g_tochnost > 0 || g_tochnost == -1)))
		length += print_only_s(z);
	return (length);
}
