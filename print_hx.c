/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohrechyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 10:46:31 by ohrechyn          #+#    #+#             */
/*   Updated: 2017/04/21 10:48:07 by ohrechyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	print_hx_bg(unsigned short int n, char type, char **z)
{
	int		c;

	if (n >= 16)
		return (print_hx_bg((n / 16), type, z) + print_hx_bg((n % 16),
					type, z));
	else
	{
		if (type == 'x')
			c = base((int)n);
		else
			c = ft_toupper(base((int)n));
		*z = ft_charjoin(*z, (char)c);
		return (1);
	}
}

int			print_hx(unsigned short int n, char type, int *index, int co)
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
	print_hx_bg(n, type, &z);
	counter = ft_strlen(z);
	length += get_width(counter, otrec, 1, type);
	length += print_only_s(z);
	return (length);
}
