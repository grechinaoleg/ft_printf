/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohrechyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 11:20:36 by ohrechyn          #+#    #+#             */
/*   Updated: 2017/04/21 11:22:51 by ohrechyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		print_x_bg(unsigned int n, char type, char **z)
{
	int		c;

	if (n >= 16)
		return (print_x_bg((n / 16), type, z) + print_x_bg((n % 16), type, z));
	else
	{
		if (type == 'x')
			c = base(n);
		else
			c = ft_toupper(base(n));
		*z = ft_charjoin(*z, (char)c);
		return (1);
	}
}

int		print_x(unsigned int n, char type, int *index, int co)
{
	int		length;
	char	*z;
	int		counter;
	int		otrec;

	if (co)
		*index += co;
	if (n == 0)
		otrec = 0;
	else
		otrec = 1;
	z = ft_strdup("");
	length = 0;
	print_x_bg(n, type, &z);
	counter = ft_strlen(z);
	if (n == 0 && g_tochnost == 0)
		counter -= 1;
	length += get_width(counter, otrec, 1, type);
	if (n != 0 || (g_tochnost > 0 || g_tochnost == -1))
		length += print_only_s(z);
	return (length);
}
