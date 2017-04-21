/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_jo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohrechyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 10:49:33 by ohrechyn          #+#    #+#             */
/*   Updated: 2017/04/21 10:50:32 by ohrechyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		print_jo(uintmax_t n, int *index, int co, int x)
{
	char	*s;
	int		len;
	int		z;

	x = 0;
	if (n == 0)
		z = 0;
	else
		z = 1;
	if (co)
		*index += co;
	s = ft_itoa_base(n, 8);
	len = ft_strlen(s);
	len += get_width(len, z, 0, 'o');
	print_only_s(s);
	return (len);
}
