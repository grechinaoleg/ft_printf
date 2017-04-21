/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohrechyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 10:45:22 by ohrechyn          #+#    #+#             */
/*   Updated: 2017/04/21 10:46:23 by ohrechyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		print_hu(unsigned short int n, char **z)
{
	if (n >= 10)
		return (print_hu(n / 10, z) + print_hu(n % 10, z));
	*z = ft_charjoin(*z, n + 48);
	return (1);
}

int		print_hu_bg(unsigned short int n, int *index)
{
	char	*s;
	int		len;

	*index = *index + 1;
	s = ft_strdup("");
	print_hu(n, &s);
	len = ft_strlen(s);
	len += get_width(len, 1, 0, 'u');
	print_only_s(s);
	return (len);
}
