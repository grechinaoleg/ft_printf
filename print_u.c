/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohrechyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 11:18:51 by ohrechyn          #+#    #+#             */
/*   Updated: 2017/04/21 11:19:55 by ohrechyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		print_u(unsigned int n, char **z)
{
	if (n >= 10)
		return (print_u(n / 10, z) + print_u(n % 10, z));
	*z = ft_charjoin(*z, n + 48);
	return (1);
}

int		print_u_bg(unsigned int n)
{
	char	*s;
	int		len;
	int		z;

	if (n == 0)
		z = 0;
	else
		z = 1;
	s = ft_strdup("");
	print_u(n, &s);
	len = ft_strlen(s);
	if (n == 0 && g_tochnost == 0)
		len -= 1;
	len += get_width(len, z, 0, 'u');
	if (n != 0 || (g_tochnost > 0 || g_tochnost == -1))
		print_only_s(s);
	return (len);
}
