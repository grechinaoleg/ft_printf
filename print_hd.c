/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohrechyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 10:33:34 by ohrechyn          #+#    #+#             */
/*   Updated: 2017/04/21 10:34:40 by ohrechyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

short int	up_g_zero_hd(short int n)
{
	short int	s;

	s = -1;
	n = n * s;
	return (n);
}

int			print_hd(short int n, int *index)
{
	char	*str;
	int		i;
	int		z;

	if (n < 0)
		z = 0;
	else
		z = 1;
	if (n < 0)
		n = up_g_zero_hd(n);
	*index += 1;
	if (n == -32768)
		str = ft_strdup("32768");
	else
		str = ft_itoa(n);
	i = ft_strlen(str);
	i += get_width(i, z, 0, 'd');
	print_only_s(str);
	return (i);
}
