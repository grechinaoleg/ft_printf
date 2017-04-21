/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hhu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohrechyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 10:39:15 by ohrechyn          #+#    #+#             */
/*   Updated: 2017/04/21 10:40:31 by ohrechyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		print_hhu(unsigned char n, char **z)
{
	if (n >= 10)
		return (print_hhu(n / 10, z) + print_hhu(n % 10, z));
	*z = ft_charjoin(*z, n + 48);
	return (1);
}

int		print_hhu_bg(unsigned char n, int *index)
{
	char	*s;
	int		len;
	int		z;

	if (n == 0)
		z = 0;
	else
		z = 1;
	*index = *index + 2;
	s = ft_strdup("");
	print_hhu(n, &s);
	len = ft_strlen(s);
	len += get_width(len, z, 0, 'u');
	print_only_s(s);
	return (len);
}
