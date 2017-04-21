/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohrechyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 11:06:01 by ohrechyn          #+#    #+#             */
/*   Updated: 2017/04/21 11:07:04 by ohrechyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		print_lo(unsigned long int n, int *index, int co, int x)
{
	char	*s;
	int		len;
	int		z;

	x = 0;
	if (n == 0)
		z = 1;
	else
		z = 2;
	if (co)
		*index += co;
	s = ft_itoa_base(n, 8);
	len = ft_strlen(s);
	if (n == 0 && g_tochnost == 0 && !g_sharp)
		len -= 1;
	len += get_width(len, z, 0, 'o');
	if (n != 0 || (g_tochnost > 0 || g_tochnost == -1) || (n == 0 && g_sharp))
		print_only_s(s);
	return (len);
}
