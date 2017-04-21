/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_llu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohrechyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 11:01:08 by ohrechyn          #+#    #+#             */
/*   Updated: 2017/04/21 11:02:04 by ohrechyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		print_llu(unsigned long long int n, char **z)
{
	if (n >= 10)
		return (print_llu(n / 10, z) + print_llu(n % 10, z));
	*z = ft_charjoin(*z, n + 48);
	return (1);
}

int		print_llu_bg(unsigned long long int n, int *index)
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
	print_llu(n, &s);
	len = ft_strlen(s);
	len += get_width(len, z, 0, 'u');
	print_only_s(s);
	return (len);
}
