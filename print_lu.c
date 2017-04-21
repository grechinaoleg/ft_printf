/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohrechyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 11:11:58 by ohrechyn          #+#    #+#             */
/*   Updated: 2017/04/21 11:12:49 by ohrechyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		print_lu(unsigned long int n, char **z)
{
	if (n >= 10)
		return (print_lu(n / 10, z) + print_lu(n % 10, z));
	*z = ft_charjoin(*z, n + 48);
	return (1);
}

int		print_lu_bg(unsigned long int n, int *index)
{
	char	*s;
	int		len;
	int		z;

	if (n == 0)
		z = 0;
	else
		z = 1;
	*index = *index + 1;
	s = ft_strdup("");
	print_lu(n, &s);
	len = ft_strlen(s);
	len += get_width(len, z, 0, 'u');
	print_only_s(s);
	return (len);
}
