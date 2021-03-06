/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hdd_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohrechyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 10:35:15 by ohrechyn          #+#    #+#             */
/*   Updated: 2017/04/21 10:36:21 by ohrechyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		print_hhd_i(signed char print, int set)
{
	char			*str;
	int				len;
	int				z;
	long long int	tmp;

	tmp = (long long)print;
	if (tmp < 0)
		z = 0;
	else
		z = 1;
	if (tmp < 0)
		tmp *= -1;
	str = ft_strdup(ft_itoa(tmp));
	len = (int)ft_strlen(str);
	if (print == 0 && g_tochnost == 0)
		len -= 1;
	if (set)
		len += get_width(len, z, 0, 'd');
	if (print != 0 || (print == 0 && (g_tochnost > 0 || g_tochnost == -1)))
		print_only_s(str);
	return (len);
}
